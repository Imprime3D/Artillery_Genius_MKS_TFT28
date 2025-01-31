#ifndef _NUMPAD_H_
#define _NUMPAD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

double numPadFloat(uint8_t* title, double param_val, double reset_val, bool negative);
int32_t numPadInt(uint8_t* title, int32_t param_val, int32_t reset_val, bool negative);

#ifdef __cplusplus
}
#endif

#endif
