#include "Settings.h"
#include "includes.h"

SETTINGS infoSettings;
MACHINESETTINGS infoMachineSettings;

const uint16_t default_max_temp[]      = HEAT_MAX_TEMP;
const uint16_t default_max_fanPWM[]    = FAN_MAX_PWM;
const uint16_t default_size_min[]      = {X_MIN_POS, Y_MIN_POS, Z_MIN_POS};
const uint16_t default_size_max[]      = {X_MAX_POS, Y_MAX_POS, Z_MAX_POS};
const uint16_t default_xy_speed[]      = {SPEED_XY_SLOW, SPEED_XY_NORMAL, SPEED_XY_FAST};
const uint16_t default_z_speed[]       = {SPEED_Z_SLOW, SPEED_Z_NORMAL, SPEED_Z_FAST};
const uint16_t default_ext_speed[]     = {EXTRUDE_SLOW_SPEED, EXTRUDE_NORMAL_SPEED, EXTRUDE_FAST_SPEED};
const uint16_t default_level_speed[]   = {LEVELING_POINT_XY_FEEDRATE, LEVELING_POINT_Z_FEEDRATE};
const uint16_t default_pause_speed[]   = {NOZZLE_PAUSE_XY_FEEDRATE, NOZZLE_PAUSE_Z_FEEDRATE, NOZZLE_PAUSE_E_FEEDRATE};
const uint16_t default_preheat_ext[]   = PREHEAT_HOTEND;
const uint16_t default_preheat_bed[]   = PREHEAT_BED;
const uint8_t default_custom_enabled[] = CUSTOM_GCODE_ENABLED;

// Reset settings data
void infoSettingsReset(void)
{
// General Settings
  infoSettings.serial_port[0]         = PRIMARY_BAUDRATE;  // primary serial port
  infoSettings.emulated_m600          = EMULATED_M600;

// UI Settings
  infoSettings.rotate_ui              = DISABLED;
  infoSettings.language               = LANG_DEFAULT;
  infoSettings.status_screen          = ENABLE_STATUS_SCREEN;
  infoSettings.title_bg_color         = lcd_colors[TITLE_BACKGROUND_COLOR];
  infoSettings.bg_color               = lcd_colors[BACKGROUND_COLOR];
  infoSettings.font_color             = lcd_colors[FONT_COLOR];
  infoSettings.reminder_color         = lcd_colors[REMINDER_FONT_COLOR];
  infoSettings.status_color           = lcd_colors[STATUS_FONT_COLOR];
  infoSettings.status_xyz_bg_color    = lcd_colors[STATUS_XYZ_BG_COLOR];
  infoSettings.list_border_color      = lcd_colors[LISTVIEW_BORDER_COLOR];
  infoSettings.list_button_bg_color   = lcd_colors[LISTVIEW_ICON_COLOR];
  infoSettings.mesh_min_color         = lcd_colors[MESH_MIN_COLOR];
  infoSettings.mesh_max_color         = lcd_colors[MESH_MAX_COLOR];
  infoSettings.terminal_color_scheme  = TERMINAL_COLOR_SCHEME;

  infoSettings.ack_notification       = ACK_NOTIFICATION_STYLE;
  infoSettings.files_sort_by          = SORT_DATE_NEW_FIRST;
  infoSettings.files_list_mode        = ENABLED;
  infoSettings.fan_percentage         = SHOW_FAN_PERCENTAGE;
  infoSettings.persistent_info        = ENABLED;
  infoSettings.terminal_ack           = DISABLED;
  infoSettings.notification_m117      = NOTIFICATION_M117;
  infoSettings.prog_disp_type         = ELAPSED_REMAINING;
  infoSettings.layer_disp_type        = SHOW_LAYER_HEIGHT;

// Marlin Mode Settings (only for TFT24 V1.1 & TFT28/TFT35/TFT43/TFT50/TFT70 V3.0)
  infoSettings.mode                   = DEFAULT_LCD_MODE;
  infoSettings.serial_always_on       = SERIAL_ALWAYS_ON;
  infoSettings.marlin_bg_color        = lcd_colors[MARLIN_BKCOLOR];
  infoSettings.marlin_font_color      = lcd_colors[MARLIN_FNCOLOR];
  infoSettings.marlin_fullscreen      = MARLIN_FULLSCREEN;
  infoSettings.marlin_show_title      = MARLIN_SHOW_TITLE;
  infoSettings.marlin_type            = LCD12864;

// RRF Mode Settings
  infoSettings.rrf_macros_enable      = 0;

// Printer / Machine Settings
  infoSettings.hotend_count           = HOTEND_NUM;
  infoSettings.bed_en                 = ENABLE;
  infoSettings.chamber_en             = DISABLE;
  infoSettings.ext_count              = EXTRUDER_NUM;
  infoSettings.fan_count              = FAN_NUM;
  infoSettings.ctrl_fan_en            = ENABLE_CTRL_FAN;
  infoSettings.min_ext_temp           = PREVENT_COLD_EXTRUSION_MINTEMP;
  infoSettings.auto_load_leveling     = AUTO_SAVE_LOAD_BL_VALUE;
  infoSettings.onboard_sd             = AUTO;  // ENABLED / DISABLED / AUTO
  infoSettings.m27_refresh_time       = M27_REFRESH;
  infoSettings.m27_active             = M27_WATCH_OTHER_SOURCES;
  infoSettings.long_filename          = AUTO;  // ENABLED / DISABLED / AUTO

  infoSettings.pause_retract_len      = NOZZLE_PAUSE_RETRACT_LENGTH;
  infoSettings.resume_purge_len       = NOZZLE_RESUME_PURGE_LENGTH;
  infoSettings.pause_pos[X_AXIS]      = NOZZLE_PAUSE_X_POSITION;  // X
  infoSettings.pause_pos[Y_AXIS]      = NOZZLE_PAUSE_Y_POSITION;  // Y
  infoSettings.pause_z_raise          = NOZZLE_PAUSE_Z_RAISE;

  infoSettings.level_edge             = LEVELING_EDGE_DISTANCE;
  infoSettings.level_z_pos            = LEVELING_POINT_Z;
  infoSettings.level_z_raise          = LEVELING_POINT_MOVE_Z;

  infoSettings.move_speed             = 1;  // index on infoSettings.axis_speed, infoSettings.ext_speed

  infoSettings.probing_after_homing   = ENABLED;
  infoSettings.probing_z_raise        = PROBING_Z_RAISE;
  infoSettings.z_steppers_alignment   = DISABLED;
  infoSettings.touchmi_sensor         = TOUCHMI_SENSOR_VALUE;

// Power Supply Settings (only if connected to TFT controller)
  infoSettings.auto_off               = DISABLED;
  infoSettings.ps_active_high         = PS_ACTIVE_HIGH;
  infoSettings.auto_off_temp          = PS_AUTO_SHUTDOWN_TEMP;

// Filament Runout Settings (only if connected to TFT controller)
  infoSettings.runout                 = FIL_RUNOUT;
  infoSettings.runout_inverted        = FIL_RUNOUT_INVERTED;
  infoSettings.runout_nc              = FIL_RUNOUT_NC;
  infoSettings.runout_noise_ms        = FIL_RUNOUT_NOISE_THRESHOLD;
  infoSettings.runout_distance        = FIL_RUNOUT_DISTANCE_MM;

// Power Loss Recovery & BTT UPS Settings
  infoSettings.plr                    = ENABLED;
  infoSettings.plr_home               = PLR_HOME;
  infoSettings.plr_z_raise            = PLR_Z_RAISE;
  infoSettings.btt_mini_ups           = BTT_MINI_UPS;

// Other Device-Specific Settings
  infoSettings.touch_sound            = ENABLED;
  infoSettings.toast_sound            = ENABLED;
  infoSettings.alert_sound            = ENABLED;
  infoSettings.heater_sound           = ENABLED;
  infoSettings.lcd_brightness         = DEFAULT_LCD_BRIGHTNESS;
  infoSettings.lcd_idle_brightness    = DEFAULT_LCD_IDLE_BRIGHTNESS;
  infoSettings.lcd_idle_time          = DEFAULT_LCD_IDLE_TIME;
  infoSettings.block_touch_on_idle    = DISABLED;
  infoSettings.knob_led_color         = STARTUP_KNOB_LED_COLOR;
  infoSettings.knob_led_idle          = ENABLED;
  #ifdef NEOPIXEL_PIXELS
    infoSettings.neopixel_pixels      = NEOPIXEL_PIXELS;
  #else
    infoSettings.neopixel_pixels      = 0;
  #endif

// Start, End & Cancel Gcode Commands
  infoSettings.start_gcode_state      = DISABLED;
  infoSettings.end_gcode_state        = DISABLED;
  infoSettings.cancel_gcode_state     = ENABLED;

// All the remaining array initializations
  for (int i = 1; i < MAX_SERIAL_PORT_COUNT; i++)  // supplemetary serial ports
  {
    infoSettings.serial_port[i]       = DISABLED;
  }

  for (int i = 0; i < MAX_HEATER_COUNT; i++)
  {
    infoSettings.max_temp[i]          = default_max_temp[i];
  }

  for (int i = 0; i < MAX_FAN_COUNT; i++)
  {
    infoSettings.fan_max[i]           = default_max_fanPWM[i];
  }

  for (int i = 0; i < AXIS_NUM; i++)  //x, y, z
  {
    infoSettings.inverted_axis[i]     = DISABLED;
    infoSettings.machine_size_min[i]  = default_size_min[i];
    infoSettings.machine_size_max[i]  = default_size_max[i];
  }
  infoSettings.inverted_leveling_y_axis = DISABLED;

  for (int i = 0; i < FEEDRATE_COUNT - 1 ; i++)  //xy, z
  {
    infoSettings.level_feedrate[i]    = default_level_speed[i];
  }

  for (int i = 0; i < SPEED_COUNT; i++)
  {
    infoSettings.xy_speed[i]          = default_xy_speed[i];
    infoSettings.z_speed[i]           = default_z_speed[i];
    infoSettings.ext_speed[i]         = default_ext_speed[i];
  }

  for (int i = 0; i < FEEDRATE_COUNT; i++)
  {
    infoSettings.pause_feedrate[i]    = default_pause_speed[i];  // XY, Z, E
  }

  resetConfig();
}

void initMachineSetting(void)
{
  // some settings are assumes as active unless reported disabled by marlin
  infoMachineSettings.firmwareType            = FW_NOT_DETECTED;  // set fimware type to not_detected to avoid repeated ABL gcode on mode change
  infoMachineSettings.EEPROM                  = ENABLED;
  infoMachineSettings.autoReportTemp          = DISABLED;
  infoMachineSettings.autoReportPos           = DISABLED;
  infoMachineSettings.leveling                = BL_DISABLED;
  infoMachineSettings.zProbe                  = ENABLED;
  infoMachineSettings.levelingData            = ENABLED;
  infoMachineSettings.softwarePower           = DISABLED;
  infoMachineSettings.toggleLights            = DISABLED;
  infoMachineSettings.caseLightsBrightness    = DISABLED;
  infoMachineSettings.emergencyParser         = DISABLED;
  infoMachineSettings.promptSupport           = DISABLED;
  infoMachineSettings.onboard_sd_support      = DISABLED;
  infoMachineSettings.autoReportSDStatus      = DISABLED;
  infoMachineSettings.long_filename_support   = DISABLED;
  infoMachineSettings.babyStepping            = DISABLED;
  infoMachineSettings.buildPercent            = DISABLED;
  infoMachineSettings.softwareEndstops        = ENABLED;
}

void setupMachine(void)
{
  // Avoid repeated calls caused by manually sending M115 in terminal menu
  static bool firstCall = true;
  if (!firstCall) return;
  firstCall = false;

  #ifdef ENABLE_BL_VALUE
    #if ENABLE_BL_VALUE == 2
        infoMachineSettings.leveling = BL_ABL;
    #elif ENABLE_BL_VALUE == 3
        infoMachineSettings.leveling = BL_BBL;
    #elif ENABLE_BL_VALUE == 4
        infoMachineSettings.leveling = BL_UBL;
    #elif ENABLE_BL_VALUE == 5
        infoMachineSettings.leveling = BL_MBL;
    #endif
  #endif

  if (infoMachineSettings.leveling != BL_DISABLED && infoMachineSettings.EEPROM == 1 && infoSettings.auto_load_leveling == 1)
  {
    storeCmd("M420 S1\n");
  }

  if (infoMachineSettings.firmwareType != FW_MARLIN)  // Smoothieware does not report detailed M115 capabilities
  {
    infoMachineSettings.EEPROM                  = ENABLED;
    infoMachineSettings.autoReportTemp          = DISABLED;
    infoMachineSettings.autoReportPos           = DISABLED;
    infoMachineSettings.leveling                = ENABLED;
    infoMachineSettings.zProbe                  = ENABLED;
    infoMachineSettings.levelingData            = ENABLED;
    infoMachineSettings.emergencyParser         = ENABLED;
    infoMachineSettings.autoReportSDStatus      = DISABLED;
  }
  if (infoSettings.onboard_sd != AUTO)
    infoMachineSettings.onboard_sd_support = infoSettings.onboard_sd;

  if (infoSettings.long_filename != AUTO)
    infoMachineSettings.long_filename_support = infoSettings.long_filename;

  mustStoreCmd("M503 S0\n");

  if (infoMachineSettings.firmwareType == FW_REPRAPFW)
  {
    mustStoreCmd("M555 P2\n");  //  Set RRF compatibility behaves similar to 2: Marlin
  }
  mustStoreCmd("M82\n");  // Set extruder to absolute mode
  mustStoreCmd("G90\n");  // Set to Absolute Positioning
}

float flashUsedPercentage(void)
{
  uint32_t total = W25Qxx_ReadCapacity();
  float percent = ((float)FLASH_USED * 100) / total;
  return percent;
}

// check font/icon/config signature in SPI flash for update
void checkflashSign(void)
{
  //cur_flash_sign[lang_sign] = flash_sign[lang_sign];  // ignore language signature not implemented yet

  bool statusfont = getFlashSignStatus(font_sign);
  bool statusconfig = getFlashSignStatus(config_sign);
  bool statuslang = getFlashSignStatus(lang_sign);
  bool statusicon = getFlashSignStatus(icon_sign);

  if (!statuslang)
    infoSettings.language = LANG_DEFAULT;

  if (!statusfont || !statusicon || !statusconfig)
  {
    int ypos = BYTE_HEIGHT + 5;
    GUI_Clear(BLACK);
    GUI_DispString(5, 5, (uint8_t *)"Found outdated data:");

    ypos += BYTE_HEIGHT;
    if (statusfont)
      GUI_DispString(10, ypos, (uint8_t *)"Fonts: OK");
    else
      GUI_DispString(10, ypos, (uint8_t *)"Fonts: Update required");

    ypos += BYTE_HEIGHT;
    if (statusconfig)
      GUI_DispString(10, ypos, (uint8_t *)"Config: OK");
    else
      GUI_DispString(10, ypos, (uint8_t *)"Config: Update required");

    ypos += BYTE_HEIGHT;
    if (statuslang)
      GUI_DispString(10, ypos, (uint8_t *)"Language: OK");
    else
      GUI_DispString(10, ypos, (uint8_t *)"Language: Update required(Optional)");

    ypos += BYTE_HEIGHT;
    if (statusicon)
      GUI_DispString(10, ypos, (uint8_t *)"Icons: OK");
    else
      GUI_DispString(10, ypos, (uint8_t *)"Icons: Update required");

    ypos += BYTE_HEIGHT;
    GUI_DispStringInRectEOL(10, ypos + 10, LCD_WIDTH, LCD_HEIGHT, (uint8_t *)"Insert the SD card with the required\n"
                                                                             "files and press the reset button\nto update.");
    while (1);
  }
}

bool getFlashSignStatus(int index)
{
  uint32_t flash_sign[sign_count] = {FONT_CHECK_SIGN, CONFIG_CHECK_SIGN, LANGUAGE_CHECK_SIGN, ICON_CHECK_SIGN};
  uint32_t cur_flash_sign[sign_count];
  uint32_t addr = FLASH_SIGN_ADDR;
  uint32_t len = sizeof(flash_sign);

  W25Qxx_ReadBuffer((uint8_t*)&cur_flash_sign, addr, len);
  return (flash_sign[index] == cur_flash_sign[index]);
}
