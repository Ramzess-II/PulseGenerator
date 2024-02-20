#ifndef INC_WORK_H_
#define INC_WORK_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include "stm32f4xx_hal.h"
#include "saportAndData.h"
#include "Ili9341LibTouch.h"
#include "GUI.h"
#include "timers.h"
//----------------------- дефайним значения ----------------------------------//


//----------------------- объявим функции ------------------------------------//
void doWork (void);
void Work (void);
void calibration (void);
void filtrADC (void);
//----------------------- объявим структуры ----------------------------------//




#ifdef __cplusplus
}
#endif

#endif /* INC_WORK_H_ */
