#ifndef ILI9341LIB_ILI9341LIBTOUCH_H_
#define ILI9341LIB_ILI9341LIBTOUCH_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include "stm32f4xx.h"
#include <stdbool.h>
#include "saportAndData.h"
//----------------------- дефайним значения ----------------------------------//

// Warning! Use SPI bus with < 1.3 Mbit speed, better ~650 Kbit to be save.
#define ILI9341_TOUCH_SPI_PORT hspi2
extern SPI_HandleTypeDef ILI9341_TOUCH_SPI_PORT;

#define ILI9341_TOUCH_IRQ_Pin       GPIO_PIN_12
#define ILI9341_TOUCH_IRQ_GPIO_Port GPIOB
#define ILI9341_TOUCH_CS_Pin        GPIO_PIN_8
#define ILI9341_TOUCH_CS_GPIO_Port  GPIOA

// change depending on screen orientation
#define ILI9341_TOUCH_SCALE_X 320
#define ILI9341_TOUCH_SCALE_Y 240
#define READ_X 0x90
#define READ_Y 0xD0

// to calibrate uncomment UART_Printf line in ili9341_touch.c
#define ILI9341_TOUCH_MIN_RAW_X 362
#define ILI9341_TOUCH_MAX_RAW_X 3935
#define ILI9341_TOUCH_MIN_RAW_Y 210
#define ILI9341_TOUCH_MAX_RAW_Y 3862



//----------------------- объявим функции ------------------------------------//

// call before initializing any SPI devices
void ILI9341_TouchUnselect();

bool ILI9341_TouchPressed();
bool ILI9341_TouchGetCoordinates(uint16_t* x, uint16_t* y);
uint8_t calibTouch (uint8_t poz);
void ILI9341_ToucInit (void);
//----------------------- объявим структуры ----------------------------------//



#ifdef __cplusplus
}
#endif

#endif /* ILI9341LIB_ILI9341LIBTOUCH_H_ */
