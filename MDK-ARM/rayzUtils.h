#ifndef _RAYZUTILS_H_
#define _RAYZUTILS_H_

//===============================
//---start------includes---------

#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

//---end--------includes---------
//===============================
//---start------defines----------

//---end--------defines----------
//===============================
//---start------prototypes-------

void DWT_Init(void);
void HAL_DelayMicros(uint32_t us);
int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);

//---end--------prototypes-------
//===============================

#endif /* _RAYZUTILS_H_ */