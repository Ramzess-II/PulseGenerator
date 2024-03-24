#include "work.h"
//----------------------- переменные из других файлов --------------------------------//
extern uint32_t globalFlag;
extern uint16_t adcBuf [FILTRADC];
uint16_t zeroCurrent = 0;
//----------------------- переменные из этого файла ----------------------------------//
struct ChangParamDevice ParamDevice = {
		.impuls = 100,
		.pause = 100,
		.count = 0,
		.changeCount = 0,
		.unitImpuls = 0,
		.unitPause = 0,
		.unitCount = 0,
		.flagInfinity = 0,
		.NPNTranzistor = 1,
		.PNPTranzistor = 0,
		.power = 0,
};
struct _memoryParam memoryParam = {0};
uint32_t timToOvercurrent = 0;
uint32_t timToCurrent = 0;
uint32_t timToEndOperation = 0;
uint32_t* memADR = (uint32_t*)ADR_DATA_MIN_X;
//------------------------------ функции ---------------------------------------------//

void doWork (void){
	startDisplay ();                                        // старт дисплея
	calibration();                                          // проверим нужна калибровка или нет
	ILI9341_ToucInit();                                     // инициализация после калибровки
	readEEPROM();
	screenSaver();                                          // заставка
	mainDisplayPrint();                                     // первоначальный принт
	zeroCurrent = adcBuf [0];                               // получим точку нуля АЦП
}

void Work (void){                                                                       // меин
	checkButtonPress();                                                                 // проверим нажатие кнопок
	if (ParamDevice.power && !READ_FLAG(WORKING, globalFlag)){                          // проверим включен выход или нет
		saveEEPROM ();
		SET_FLAG(WORKING, globalFlag);                                                  // если включен запретим повторный вход
		setTimAndStart ();                                                              // запустим выход
	}
	if (READ_FLAG(END_OPERATION, globalFlag) && READ_FLAG(WORKING, globalFlag)){        // если поднялся флаг окончания
		RESET_FLAG(END_OPERATION, globalFlag);                                          // сбросим конец операции
		endOperationWindow (true);                                                      // покажем окно комплит
		timToEndOperation = 1000;                                                       // взведем таймер показа окна
		buzzerSet(100);
	}
	if (READ_FLAG(WORKING, globalFlag) && timToEndOperation == 1){                      // когда отсчитали время
		timToEndOperation = 0;                                                          // сбросим полностью
		RESET_FLAG(WORKING, globalFlag);                                                // выключим флаг работы
		externalPowerOff ();                                                            // погасим клавишу повер
		ParamDevice.power = false;                                                      // и снимем флаг работы
		endOperationWindow (false);                                                     // уберем показ комплит
	}
	if (!ParamDevice.power && READ_FLAG(WORKING, globalFlag) ){                         // если мы нажали кнопку повер при выполнении
		timerOff ();                                                                    // остановить
		RESET_FLAG(WORKING, globalFlag);                                                // сбросить
		printCount (1);                                                                 // перерисовать количество повторений
	}
	filtrADC ();
	if (READ_FLAG(WORKING, globalFlag)) {
		printReversCount (ParamDevice.changeCount);
	}
}

void filtrADC (void) {
	int32_t filtrAdc = 0;
	float current = 0;
	for (int i = 0; i < FILTRADC; i ++) {
		filtrAdc += adcBuf [i];
	}
	filtrAdc = filtrAdc / FILTRADC;
	if ((filtrAdc - zeroCurrent) <= 0) filtrAdc = 0;
	else filtrAdc = filtrAdc - zeroCurrent;
	current = (((float)filtrAdc * 0.0008)*1.52)*11 ;      // 1.52 k , 0.0008 LSB ADC, 1 вольт = 10А +-
	if (!timToCurrent){
		timToCurrent = 500;
		printCurrent (current);
	}
	if (current > MAX_CURRENT) {                                                        // если перегруз по току
		timerOff ();                                                                    // остановим таймер
		overCurrent (true);                                                             // покажем табличку
		timToOvercurrent = 1000;
		buzzerSet(100);                                                                 // пик
	}
	if (timToOvercurrent == 1) {
		timToOvercurrent = 0;
		overCurrent (false);
		RESET_FLAG(WORKING, globalFlag);                                                // выключим флаг работы
		externalPowerOff ();                                                            // погасим клавишу повер
		ParamDevice.power = false;                                                      // и снимем флаг работы
	}
}

void calibration (void){                     // калибровка
	if (*memADR == 0xFFFFFFFF) {             // если в ячейке калибровки начальное значение значит нужно калибровать
		reset:                               // при неудаче вернуться в начало
		GUICalibration (LEFTUP);
		setOK (false);
		calibTouch(LEFTUP);
		setOK (true);
		HAL_Delay(1000);

		GUICalibration (RIGHTUP);
		setOK (false);
		calibTouch(RIGHTUP);
		setOK (true);
		HAL_Delay(1000);

		GUICalibration (LEFTDOWN);
		setOK (false);
		calibTouch(LEFTDOWN);
		setOK (true);
		HAL_Delay(1000);

		GUICalibration (RIGHTDOWN);
		setOK (false);
		calibTouch(RIGHTDOWN);
		setOK (true);
		HAL_Delay(1000);

		GUICalibration (CHECKCALIB);
		if (calibTouch(CHECKCALIB)) {
			GUICalibration(CALIBOK);
			HAL_Delay(1000);
		} else {
			GUICalibration(ERRCALIB);
			HAL_Delay(1000);
			goto reset;
		}
	}
}

void readEEPROM (void) {
	uint32_t count = 0;
	uint32_t* pozAdr = (uint32_t*)ADR_START_MEM;
	if (SAVE_EEPROM) {
		for (;count < MAX_RANGE; count ++) {
			if (*pozAdr == 0xFFFFFFFF) break;
			pozAdr += QUANTITY_SAVE;             //
		}
		if (count == 0) {                        // если память чистая взять по умолчанию
			ParamDevice.impuls = 100;
			ParamDevice.pause = 100;
			ParamDevice.count = 0;
			ParamDevice.unitImpuls = 0;
			ParamDevice.unitPause = 0;
			ParamDevice.unitCount = 0;
		} else {
			pozAdr = (uint32_t*) ADR_START_MEM + ((count - 1) * QUANTITY_SAVE );
			ParamDevice.impuls = (int32_t) *pozAdr;
			pozAdr ++;
			ParamDevice.pause = (int32_t) *pozAdr;
			pozAdr ++;
			ParamDevice.count = (int32_t) *pozAdr;
			pozAdr ++;
			ParamDevice.unitImpuls = (int32_t) *pozAdr;
			pozAdr ++;
			ParamDevice.unitPause = (int32_t) *pozAdr;
			pozAdr ++;
			ParamDevice.unitCount = (int32_t) *pozAdr;
		}
	}
}

void saveEEPROM (void) {
	uint32_t count = 0;
	uint32_t memSet = 0;
	uint32_t* pozAdr = (uint32_t*)ADR_START_MEM;
	if (SAVE_EEPROM) {
		for (;count < MAX_RANGE; count ++) {
			if (*pozAdr == 0xFFFFFFFF) break;
			pozAdr += QUANTITY_SAVE;             //
		}
		if (count == MAX_RANGE) {
			HAL_FLASH_Unlock();
			__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
			FLASH_Erase_Sector(FLASH_SECTOR_2, VOLTAGE_RANGE_3);
			HAL_FLASH_Lock();
			count = 0;
		}
		memSet = ADR_START_MEM + (count * (QUANTITY_SAVE * 4) );
		HAL_FLASH_Unlock();
		__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, memSet, ParamDevice.impuls);
		memSet += 4;
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, memSet, ParamDevice.pause);
		memSet += 4;
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, memSet, ParamDevice.count);
		memSet += 4;
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, memSet, ParamDevice.unitImpuls);
		memSet += 4;
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, memSet, ParamDevice.unitPause);
		memSet += 4;
		HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, memSet, ParamDevice.unitCount);
		HAL_FLASH_Lock();
	}
}

//------------------------------ примечания --------------------------------------------//
/*
Как работает считывание памяти. Если в ячейке есть какие то значения идем в следующую со смещением. Если там пусто  0xFFFFFFFF то вернемся на одну ячейку
назад и это будут самые актуальные данные.
При записи если видим что ячейка пустая пишем в нее, а если это была последняя ячейка, стереть страничку и записать в нулевой адресс.
*/

