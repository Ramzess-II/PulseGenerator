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

#define NPN                             1
#define PNP                             0

#define TOUCH_DISPLAY                   0x00000001
#define ONE_TOUCH                       0x00000002
#define ONE_BUZZER                      0x00000004
#define AREA1_PRESS                     0x00000008
#define AREA2_PRESS                     0x00000010
#define AREA3_PRESS                     0x00000020
#define BUTTON_HOLD                     0x00000040
#define END_OPERATION                   0x00000080
#define WORKING                         0x00000100  //??

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
    	uint16_t changeCount;
    	uint8_t  unitImpuls;
    	uint8_t  unitPause;
    	uint8_t  flagInfinity;
    	uint8_t  NPNTranzistor;
    	uint8_t  PNPTranzistor;
    	uint8_t  power;
   };

enum {
	LEFTUP,
	RIGHTUP,
	LEFTDOWN,
	RIGHTDOWN,
	CHECKCALIB,
	CALIBOK,
	ERRCALIB,
};

//------------------------------ примечания ------------------------------------------//
/*
Pinout:
A0  -   Buzzer
A1  -   NPN
A2  -   PNP
B12 -   T_IRQ
B14 -   T_DO
B15 -   T_DIN
A8  -   T_CS
B13 -   T_CLK
A6  -   SDO
A4  -   LED
A5  -   SCK
A7  -   SDI
B0  -   DC
B1  -   RESET
B2  -   CS


*/

#ifdef __cplusplus
}
#endif

#endif /* INC_SAPORTANDDATA_H_ */
