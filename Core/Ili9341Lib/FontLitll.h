#ifndef ILI9341LIB_FONTLITLL_H_
#define ILI9341LIB_FONTLITLL_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include <stdint.h>

//----------------------- дефайним значения ----------------------------------//



//----------------------- объявим функции ------------------------------------//



//----------------------- объявим структуры ----------------------------------//

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint16_t *data;
} FontDef;


extern FontDef Font_7x10;
extern FontDef Font_11x18;
extern FontDef Font_16x26;


#ifdef __cplusplus
}
#endif

#endif /* ILI9341LIB_FONTLITLL_H_ */
