#include "SpeedControl.h"
#include "includes.h"

#define SPEED_REFRESH_TIME 500  // 1 second is 1000

const char * const speedCmd[SPEED_NUM] = {"M220", "M221"};

static uint16_t setPercent[SPEED_NUM] = {100, 100};
static uint16_t curPercent[SPEED_NUM] = {100, 100};
static uint8_t needSetPercent = 0;

static uint32_t speedNextUpdateTime = 0;
static bool speedUpdateWaiting = false;

void speedSetPercent(const uint8_t tool, const uint16_t per)
{
  uint16_t value = NOBEYOND(SPEED_MIN, per, SPEED_MAX);

  SET_BIT_VALUE(needSetPercent, tool, value != curPercent[tool]);
  setPercent[tool] = value;
}

uint16_t speedGetSetPercent(const uint8_t tool)
{
  return setPercent[tool];
}

void speedSetCurPercent(const uint8_t tool, const uint16_t per)
{
  curPercent[tool] = per;
}

uint16_t speedGetCurPercent(const uint8_t tool)
{
  return curPercent[tool];
}

void loopCheckSpeed(void)
{
  static uint32_t nextUpdateTime = 0;

  if (OS_GetTimeMs() < nextUpdateTime)  // avoid rapid fire, clogging the queue
    return;

  nextUpdateTime = OS_GetTimeMs() + SPEED_REFRESH_TIME;

  for (uint8_t i = 0; i < SPEED_NUM; i++)
  {
    if (infoSettings.ext_count == 0 && i > 0)  // don't poll M221 if there are no extruders
      continue;

    if (GET_BIT(needSetPercent, i))
    {
      if (storeCmd("%s S%d D%d\n", speedCmd[i], setPercent[i], heatGetToolIndex()))
        SET_BIT_OFF(needSetPercent, i);
    }
  }
}

void speedQueryClearUpdateWaiting(void)
{
  speedUpdateWaiting = false;
}

void speedQuery(void)
{
  // if RepRap or M220/M221 previously sent and still waiting for a reply and not timed out, do nothing
  if (infoMachineSettings.firmwareType == FW_REPRAPFW || (speedUpdateWaiting && (OS_GetTimeMs() < speedNextUpdateTime)))
    return;

  if (infoHost.tx_slots != 0 && infoHost.connected)
  {
    speedUpdateWaiting = storeCmd("M220\n");

    if (infoSettings.ext_count > 0)
      speedUpdateWaiting |= storeCmd("M221\n");  // speedUpdateWaiting set to "true" if at least one command will be sent

    if (speedUpdateWaiting)
      speedNextUpdateTime = OS_GetTimeMs() + ACK_QUERY_TIMEOUT;
  }
}
