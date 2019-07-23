#include "rayzUtils.h"

//======================================
//---start---code---"HAL_DelayMicros();"

#define    DWT_CYCCNT    *(volatile unsigned long *)0xE0001004
#define    DWT_CONTROL   *(volatile unsigned long *)0xE0001000
#define    SCB_DEMCR     *(volatile unsigned long *)0xE000EDFC

void DWT_Init(void)
{
	SCB_DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT_CYCCNT  = 1;
	DWT_CONTROL |= DWT_CTRL_CYCCNTENA_Msk; 
}

void HAL_DelayMicros(uint32_t us)
{
	DWT -> CYCCNT = 0;
  uint32_t t0 =  DWT->CYCCNT;
  uint32_t us_count_tick =  us * (SystemCoreClock/1000000);
  while (((DWT->CYCCNT) - t0) <= us_count_tick) {};
}

//---end-----code---"HAL_DelayMicros();"
//======================================
//---start---code---"map();"

int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//---end-----code---"map();"
//======================================
//---start---code---"randomSeed();"

int32_t randomSeed(int32_t min, int32_t max)
{
	int32_t randSeed = DWT->CYCCNT;
	return map(randSeed, -2147483648, 2147483648, min, max);
}

//---end-----code---"randomSeed();"
//======================================