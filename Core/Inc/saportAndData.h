#ifndef INC_SAPORTANDDATA_H_
#define INC_SAPORTANDDATA_H_

#ifdef __cplusplus
extern "C" {
#endif

//----------------------- подключим файлы ------------------------------------//
#include "stm32f4xx.h"


//----------------------- дефайним значения ----------------------------------//
#define NO_PRESSED                      0
#define PRESSED                         1

#define TOUCH_DISPLAY                   0x00000001
#define ONE_TOUCH                       0x00000002
#define ONE_BUZZER                      0x00000004

#define AREA1_PRESS                     0x00000001
#define AREA2_PRESS                     0x00000002
#define AREA3_PRESS                     0x00000004
#define BUTTON1_PRESS                   0x00000008
#define BUTTON2_PRESS                   0x00000010
#define BUTTON3_PRESS                   0x00000020
#define BUTTON4_PRESS                   0x00000040
#define BUTTON5_PRESS                   0x00000080
#define BUTTON6_PRESS                   0x00000100
#define BUTTON7_PRESS                   0x00000200


#define SET_FLAG(numFlag, variable)    (variable |= numFlag)
#define RESET_FLAG(numFlag, variable)  (variable &= ~(numFlag))
#define READ_FLAG(numFlag, variable)   (variable & (numFlag))

#define BUZER_SET             SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS_0)
#define BUZER_RESET           SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR_0)

#define ADR_DATA_MIN_X      0x0807FFF0
#define ADR_DATA_MAX_X      0x0807FFF4
#define ADR_DATA_MIN_Y      0x0807FFF8
#define ADR_DATA_MAX_Y      0x0807FFFC

//----------------------- объявим функции ------------------------------------//
int16_t myAbs(int num);
void swap_int16_t(int16_t *a, int16_t *b);
int16_t wholeDevider (int16_t data, int16_t devider);
void buzzerSet (int16_t time);
void writeDataToMemory(uint32_t address, uint32_t data);
int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
int32_t constrain(int32_t value, int32_t in_min, int32_t in_max);
//----------------------- объявим структуры ----------------------------------//

typedef struct {
    const uint8_t *data;
    uint16_t width;
    uint16_t height;
    uint8_t dataSize;
    } tImage;

typedef struct {
    long int code;
    const tImage *image;
    } tChar;

    struct ChangParamDevice {
    	uint16_t impuls;
    	uint16_t pause;
    	uint16_t count;
    	uint8_t  unitImpuls;
    	uint8_t  unitPause;
    	uint8_t  flagInfinity;
    	uint8_t  NPN_PNP;
    	uint8_t  power;
    	uint8_t  changeParametrs;
   };

#ifdef __cplusplus
}
#endif

#endif /* INC_SAPORTANDDATA_H_ */
