#include "saportAndData.h"

//----------------------- переменные из этого файла ----------------------------------//
uint32_t globalFlag = 0;
uint32_t globalGUIFlag = 0;
uint32_t timBuzzer = 0;
//------------------------------ функции ---------------------------------------------//

/**************************************************************************
   @brief     will return the modulus of the num like abs in C
    @param    num  incoming number
**************************************************************************/
int16_t myAbs(int num) {
    if (num < 0) {
        return -num;
    } else {
        return num;
    }
}

/**************************************************************************
   @brief     swaps values in variables
    @param    a  num first
    @param    a  num two
**************************************************************************/
void swap_int16_t(int16_t *a, int16_t *b) {
    int16_t temp = *a;
    *a = *b;
    *b = temp;
}

/**************************************************************************
   @brief     swaps values in variables
    @param    a  num first
    @param    a  num two
**************************************************************************/
int16_t wholeDevider (int16_t data, int16_t devider) {
	int16_t result = 0;
	int16_t max = (data / devider) + 1;
	for (int i = 0; i < max; i ++) {
		if (data <= devider) break;
		data -= devider;
		result ++;
	}
	result ++;
	return result;
}

void buzzerSet (int16_t time) {
	if (!timBuzzer){
		timBuzzer = time;
		BUZER_SET;
	}
}

void writeDataToMemory(uint32_t address, uint32_t data) {
	HAL_FLASH_Unlock();
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
	                         FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
	  FLASH_Erase_Sector(FLASH_SECTOR_7, VOLTAGE_RANGE_3);
	  HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, data);
	  HAL_FLASH_Lock();
}

int32_t map(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int32_t constrain(int32_t value, int32_t in_min, int32_t in_max) {
    if(value < in_min) {
        return in_min;
    }
    else if(in_max < value) {
        return in_max;
    }
    else
        return value;
}

//------------------------------ примечания --------------------------------------------//

