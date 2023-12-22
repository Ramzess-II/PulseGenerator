#ifndef ILI9341LIB_COLORIMG_H_
#define ILI9341LIB_COLORIMG_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include "stm32f4xx.h"
#include <stdint.h>
#include "saportAndData.h"
//----------------------- дефайним значения ----------------------------------//



//----------------------- объявим функции ------------------------------------//



//----------------------- объявим структуры ----------------------------------//

extern const uint16_t image_powerGreen[];
extern const uint16_t image_powerRed[];
extern const uint16_t image_Plus[];
extern const uint16_t image_Minus[];
extern const uint16_t image_Arrow[];

#ifdef __cplusplus
}
#endif


#endif /* ILI9341LIB_COLORIMG_H_ */
