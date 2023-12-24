#ifndef INC_TIMERS_H_
#define INC_TIMERS_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include "stm32f4xx_hal.h"
#include "saportAndData.h"
#include <stdbool.h>
//----------------------- дефайним значения ----------------------------------//


//----------------------- объявим функции ------------------------------------//
void setTimAndStart(void);
void timerOff (void);
//----------------------- объявим структуры ----------------------------------//



#ifdef __cplusplus
}
#endif

#endif /* INC_TIMERS_H_ */
