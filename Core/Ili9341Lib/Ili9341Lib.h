#ifndef ILI9341LIB_ILI9341LIB_H_
#define ILI9341LIB_ILI9341LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include "stm32f4xx.h"
#include "FontLitll.h"
#include "FontBig.h"
#include <stdbool.h>
#include <string.h>
#include "saportAndData.h"
#include "monochromImg.h"
#include "ColorImg.h"
//----------------------- дефайним значения ----------------------------------//
#define ILI9341_MADCTL_MY  0x80
#define ILI9341_MADCTL_MX  0x40
#define ILI9341_MADCTL_MV  0x20
#define ILI9341_MADCTL_ML  0x10
#define ILI9341_MADCTL_RGB 0x00
#define ILI9341_MADCTL_BGR 0x08
#define ILI9341_MADCTL_MH  0x04

/*** Redefine if necessary ***/
#define ILI9341_SPI_PORT hspi1
extern SPI_HandleTypeDef ILI9341_SPI_PORT;

#define ILI9341_RES_Pin       GPIO_PIN_1
#define ILI9341_RES_GPIO_Port GPIOB
#define ILI9341_CS_Pin        GPIO_PIN_2
#define ILI9341_CS_GPIO_Port  GPIOB
#define ILI9341_DC_Pin        GPIO_PIN_0
#define ILI9341_DC_GPIO_Port  GPIOB
#define Led_Display_Pin       GPIO_PIN_12
#define Led_Display_GPIO_Port GPIOB

#define CS_SET                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS_2)
#define CS_RESET              SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR_2)
#define DC_SET                SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS_0)
#define DC_RESET              SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR_0)

// default orientation
/*
#define ILI9341_WIDTH  240
#define ILI9341_HEIGHT 320
#define ILI9341_ROTATION (ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR)
*/

// rotate right
#define ILI9341_WIDTH  320
#define ILI9341_HEIGHT 240
#define ILI9341_ROTATION (ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR)

// rotate left
/*
#define ILI9341_WIDTH  320
#define ILI9341_HEIGHT 240
#define ILI9341_ROTATION (ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR)
*/

// upside down
/*
#define ILI9341_WIDTH  240
#define ILI9341_HEIGHT 320
#define ILI9341_ROTATION (ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR)
*/

/****************************/

// Color definitions
#define	ILI9341_BLACK   0x0000
#define	ILI9341_BLUE    0x001F
#define	ILI9341_RED     0xF800
#define	ILI9341_GREEN   0x07E0
#define ILI9341_CYAN    0x07FF
#define ILI9341_MAGENTA 0xF81F
#define ILI9341_YELLOW  0xFFE0
#define ILI9341_WHITE   0xFFFF
#define ILI9341_PURPLE  0xF81F
#define ILI9341_CAPRI   0x05FF
#define ILI9341_COLOR565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

//----------------------- объявим функции ------------------------------------//

// call before initializing any SPI devices
void ILI9341_Unselect();
void ILI9341_Select();

void ILI9341_Init(void);
void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void ILI9341_WriteString(uint16_t x, uint16_t y, const char* str, FontDef font, uint16_t color, uint16_t bgcolor);
void ILI9341_DeleteString(uint16_t x, uint16_t y, const char *str, FontDef font, uint16_t color, uint16_t bgcolor);
void ILI9341_WriteMyString(uint16_t x, uint16_t y, const char* str,  uint16_t color, uint16_t bgcolor);
void ILI9341_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void ILI9341_FillScreen(uint16_t color);
void ILI9341_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t* data);
void ILI9341_DrawMonochromeImage(uint16_t x, uint16_t y, uint16_t color, uint16_t bgcolor, tImage image);
void ILI9341_InvertColors(bool invert);
void drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void drawSomePixelRoundRect (int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, int16_t countPixel, uint16_t color);
void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r, uint16_t color);
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void drawCircle(int16_t x0, int16_t y0, int16_t r,uint16_t color);
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);

//----------------------- объявим структуры ----------------------------------//


#ifdef __cplusplus
}
#endif

#endif /* ILI9341LIB_ILI9341LIB_H_ */
