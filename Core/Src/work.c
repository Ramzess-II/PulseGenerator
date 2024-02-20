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
		.flagInfinity = 0,
		.NPNTranzistor = 1,
		.PNPTranzistor = 0,
		.power = 0,
};
uint32_t timToOvercurrent = 0;
uint32_t timToCurrent = 0;
uint32_t timToEndOperation = 0;
uint32_t* memADR = (uint32_t*)ADR_DATA_MIN_X;
//------------------------------ функции ---------------------------------------------//

void doWork (void){
	startDisplay ();                                        // старт дисплея
	calibration();                                          // проверим нужна калибровка или нет
	ILI9341_ToucInit();                                     // инициализация после калибровки
	screenSaver();                                          // заставка
	mainDisplayPrint();                                     // первоначальный принт
	zeroCurrent = adcBuf [0];                               // получим точку нуля АЦП
}

void Work (void){                                                                       // меин
	checkButtonPress();                                                                 // проверим нажатие кнопок
	if (ParamDevice.power && !READ_FLAG(WORKING, globalFlag)){                          // проверим включен выход или нет
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
	}
	filtrADC ();
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


//------------------------------ примечания --------------------------------------------//
