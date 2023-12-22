#ifndef INC_GUI_H_
#define INC_GUI_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include "stm32f4xx.h"
#include "ili9341Lib.h"
#include "Ili9341LibTouch.h"
#include <stdio.h>
#include <string.h>
#include "ColorImg.h"
#include "saportAndData.h"
//----------------------- дефайним значения ----------------------------------//
#define SPPED1           2000
#define SPPED2           3000
#define SPPED3           4000
#define SPPED4           5000
#define SPPED5           5500

#define PLUS             1
#define MINUS            0

//----------------------- объявим функции ------------------------------------//
void mainDisplayPrint (void);
void checkButtonPress (void);
void workDisplay (void);
void startDisplay (void);
void GUIPostHandler (void);
void GUICalibration (uint8_t pozition);
void setOK (uint8_t flag);
//----------------------- объявим структуры ----------------------------------//




#ifdef __cplusplus
}
#endif

#endif /* INC_GUI_H_ */
