#ifndef ILI9341LIB_MONOCHROMIMG_H_
#define ILI9341LIB_MONOCHROMIMG_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include "stm32f4xx.h"
#include "saportAndData.h"
//----------------------- дефайним значения ----------------------------------//



//----------------------- объявим функции ------------------------------------//



//----------------------- объявим структуры ----------------------------------//
extern const tImage plus;
extern const tImage minus;
extern const tImage ArrowUp;
extern const tImage pnp;
extern const tImage npn;
extern const tImage power;
extern const tImage tranzistor;

#ifdef __cplusplus
}
#endif

#endif /* ILI9341LIB_MONOCHROMIMG_H_ */
