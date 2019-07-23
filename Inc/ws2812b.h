#ifndef _WS2812B_H_
#define _WS2812B_H_

#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

//Количество светодиодов
#define LED_COUNT 30
//Длинна преамбулы, для задержки между обновлениями ленты
#define PREAMBLESIZE 60
//количество бит на 1 светодиод
#define LED_BIT_COUNT 24
// длительность бита 0
#define LED_BIT_0 26
// длительность бита 1
#define LED_BIT_1 65
// размер буфера
#define BUF_SIZE (PREAMBLESIZE+LED_COUNT*LED_BIT_COUNT)
#define MATRIX_WIDTH 6
#define MATRIX_HEIGHT 5

	void LED_Init(void);
	void showLed(void);
	void rainbowCycle(uint16_t bright, uint8_t wait, uint8_t step);
	void Ball(uint32_t hexRGB, float xs, float grav, float fade);
	void stripFill(uint8_t red, uint8_t green, uint8_t blue);
	void matrixRoutine(uint16_t delay);
	void effect_Sparkls(uint8_t dence);
	uint32_t getHexRGB(uint32_t numLed);
	uint32_t getHexRGB_XY(uint32_t x, uint32_t y);
	void setHexPixel(uint32_t pixelNum, uint32_t hexRGB);
	void setHexPixel_XY(uint32_t x, uint32_t y, uint32_t hexRGB);
	void snowRoutine(uint16_t SNOW_DENCE, uint16_t delay);
	uint32_t HSV(uint16_t hue, uint8_t sat, uint8_t val);
	void effectDiagonalRainbow(uint16_t delay, uint16_t value);

#endif /* _WS2812B_H_ */

