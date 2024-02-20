#include "GUI.h"

//----------------------- переменные из других файлов --------------------------------//
extern uint32_t globalFlag;
extern uint32_t timToEndOperation,timToOvercurrent;
extern struct ChangParamDevice ParamDevice;
//----------------------- переменные из этого файла ----------------------------------//
char bufSpi[40] = { };
char *unitTXT[3] = { "us", "ms", "s   ", };
char *unitFreq[3] = { "Hz ", "kHz", "MHz", };
uint32_t multiplicationFreq[3] = { 1000000, 1000, 1 };
uint16_t x, y, countSpeed = 1;
uint32_t timBigArea = 0, timButtonPress = 0, timHoldButtonPress = 0;
//------------------------------ функции ---------------------------------------------//
void screenSaver (void) {                                                                      // заставка
	ILI9341_FillScreen(ILI9341_BLACK);                                                         // очистить экран
	strcpy(bufSpi, "PULSE");                                                                   // написать название
	ILI9341_WriteMyString(105, 76, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
	strcpy(bufSpi, "GENERATOR");
	ILI9341_WriteMyString(65, 120, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
	ILI9341_WriteString(250, 220, "Ver1.1", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
	drawSomePixelRoundRect(40, 66, 240, 108, 4, 2, ILI9341_YELLOW);
	HAL_Delay(2000);
	buzzerSet(100);                                                                            // пикнуть
}

void GUICalibration(uint8_t pozition) {                                                        // калибровка графическое отображение
	switch (pozition) {
	case LEFTUP:                                                                               // левая точка
		ILI9341_FillScreen(ILI9341_BLACK);
		ILI9341_WriteString(15, 50, "Display calibration, click", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);      // а так же пишем что калибруемся
		ILI9341_WriteString(15, 70, "on all the circles in turn", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		drawCircle(10, 10, 10, ILI9341_YELLOW);
		drawCircle(10, 10, 9, ILI9341_YELLOW);                                                  // точка в которую нажать
		break;
	case RIGHTUP:
		ILI9341_FillRectangle(0, 0, 25, 25, ILI9341_BLACK);
		drawCircle(309, 10, 10, ILI9341_YELLOW);
		drawCircle(309, 10, 9, ILI9341_YELLOW);
		break;
	case LEFTDOWN:
		ILI9341_FillRectangle(299, 0, 25, 25, ILI9341_BLACK);
		drawCircle(10, 229, 10, ILI9341_YELLOW);
		drawCircle(10, 229, 9, ILI9341_YELLOW);
		break;
	case RIGHTDOWN:
		ILI9341_FillRectangle(0, 219, 25, 25, ILI9341_BLACK);
		drawCircle(309, 229, 10, ILI9341_YELLOW);
		drawCircle(309, 229, 9, ILI9341_YELLOW);
		break;
	case CHECKCALIB:
		ILI9341_FillRectangle(299, 219, 25, 25, ILI9341_BLACK);                                  // проверка калибровки
		ILI9341_FillRectangle(15, 50, 290, 40, ILI9341_BLACK);
		ILI9341_FillRectangle(140, 100, 60, 20, ILI9341_BLACK);
		ILI9341_WriteString(60, 20, "Calibration check", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		drawCircle(160, 120, 10, ILI9341_YELLOW);
		drawCircle(160, 120, 9, ILI9341_YELLOW);
		break;
	case CALIBOK:
		ILI9341_FillRectangle(60, 20, 260, 20, ILI9341_BLACK);
		ILI9341_FillRectangle(150, 110, 30, 30, ILI9341_BLACK);
		ILI9341_WriteString(75, 20, "Calibration ok", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		break;
	case ERRCALIB:
		ILI9341_FillRectangle(60, 50, 260, 20, ILI9341_BLACK);
		ILI9341_FillRectangle(150, 110, 30, 30, ILI9341_BLACK);
		ILI9341_WriteString(60, 20, "Invalid calibration", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		break;
	}
}

void setOK(uint8_t flag) {                                                                     // при калибровке показывать действие
	if (flag) {
		ILI9341_WriteString(140, 100, " OK    ", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
	} else {
		ILI9341_WriteString(140, 100, "Wait", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
	}
}

void startDisplay(void) {                                                                      // инициализация дисплея
	ILI9341_TouchUnselect();
	ILI9341_Unselect();
	HAL_Delay(10);
	SET_BIT(SPI1->CR1, SPI_CR1_SPE);                                                           // включить SPI
	ILI9341_Init();
	ILI9341_FillScreen(ILI9341_BLACK);
	HAL_Delay(100);
}

void printFreeq(void) {                                                                        // пересчет и вывод текущей частоты
	uint8_t count = 0;
	float freq = 0;
	freq = (1 / (((float) ParamDevice.impuls / (float) multiplicationFreq[ParamDevice.unitImpuls]) +
			((float) ParamDevice.pause / (float) multiplicationFreq[ParamDevice.unitPause])));
	if (freq >= 1000000) {                                                                     // если частоты больше 1000000
		count = 2;                                                                             // ставим пометку с какой ячейки читать
		freq = freq / 1000000;                                                                 // уменьшаем нули
	}
	if (freq >= 1000) {
		count = 1;
		freq = freq / 1000;
	}
	strcpy(bufSpi, "Freq=");                                                                  // ну и печать
	ILI9341_WriteString(10, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
	sprintf(bufSpi, "%06.2f%s", freq, unitFreq[count]);                                       // помним что 6 это общее количество символов
	ILI9341_WriteString(65, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
}

void printCurrent (float current) {                                                            // принт текущего значения тока
	strcpy(bufSpi, "Iout: ");                                                                  // это тупо, можно где то один раз нарисовать
	ILI9341_WriteString(190, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
	sprintf(bufSpi, "%05.3f%s ", current, "A");
	ILI9341_WriteString(245, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
}

/*void printTypeOutput(void) {                                                                 // устарело // отображение какой выход используется
	ILI9341_FillRectangle(190, 0, 160, 22, ILI9341_BLUE);                                      // сначала стираем, потом пишем
	if (ParamDevice.NPNTranzistor && !ParamDevice.PNPTranzistor) {
		strcpy(bufSpi, "Out:NPN");
		ILI9341_WriteString(190, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
	}
	if (ParamDevice.NPNTranzistor && ParamDevice.PNPTranzistor) {
		strcpy(bufSpi, "Out:NPN+PNP");
		ILI9341_WriteString(190, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
	}
	if (!ParamDevice.NPNTranzistor && ParamDevice.PNPTranzistor) {
		strcpy(bufSpi, "Out:PNP");
		ILI9341_WriteString(190, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
	}
	if (!ParamDevice.NPNTranzistor && !ParamDevice.PNPTranzistor) {
		strcpy(bufSpi, "Out:No out");
		ILI9341_WriteString(190, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
	}
}*/

void printTImpulse(void) {                                                                     // переписать длительность импульса
	strcpy(bufSpi, "T imp:");
	ILI9341_WriteMyString(12, 30, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
	sprintf(bufSpi, "%-3d %s  ", ParamDevice.impuls, unitTXT[ParamDevice.unitImpuls]);
	ILI9341_WriteMyString(125, 30, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
}

void printTPause(void) {                                                                       // переписать длительность паузы
	strcpy(bufSpi, "T paus:");
	ILI9341_WriteMyString(12, 78, bufSpi, ILI9341_YELLOW, ILI9341_BLACK);
	sprintf(bufSpi, "%-3d %s  ", ParamDevice.pause, unitTXT[ParamDevice.unitPause]);
	ILI9341_WriteMyString(125, 78, bufSpi, ILI9341_YELLOW, ILI9341_BLACK);
}

void printCount(void) {                                                                        // переписать количество повторений
	strcpy(bufSpi, "Count:");
	ILI9341_WriteMyString(12, 126, bufSpi, ILI9341_PURPLE, ILI9341_BLACK);
	if (ParamDevice.count) {
		sprintf(bufSpi, "%-3d %s  ", ParamDevice.count, "rp");
		ILI9341_WriteMyString(125, 126, bufSpi, ILI9341_PURPLE, ILI9341_BLACK);
	} else {
		sprintf(bufSpi, "~   %s  ", "rp");                                                     // в символах я заменил ~ знаком бесконечности
		ILI9341_WriteMyString(125, 126, bufSpi, ILI9341_PURPLE, ILI9341_BLACK);
	}
}

void printColorImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h,                           // печать цветной картинки по координатам + статус нажато
		uint16_t status, const uint16_t *data) {
	if (status == NO_PRESSED) {
		drawRect(x - 1, y - 1, w + 2, h + 2, ILI9341_BLACK);                                   // печатаем со смещением чтоб стереть старое
		ILI9341_DrawImage(x, y, w, h, data);
	}
	if (status == PRESSED) {
		drawRect(x, y, w + 2, h + 2, ILI9341_BLACK);
		ILI9341_DrawImage(x + 1, y + 1, w, h, data);                                           // печатаем со смещением для эффекта нажатия
	}
}

void mainDisplayPrint(void) {                                                                  // стартовая печать на экране
	ILI9341_FillScreen(ILI9341_BLACK);
	ILI9341_FillRectangle(0, 0, 320, 22, ILI9341_BLUE);
	//printTypeOutput();
	printFreeq();
	printTImpulse();
	printTPause();
	printCount();
	printColorImage(24, 182, 50, 50, NO_PRESSED, image_Plus);
	printColorImage(98, 182, 50, 50, NO_PRESSED, image_Arrow);
	printColorImage(172, 182, 50, 50, NO_PRESSED, image_Minus);
	printColorImage(246, 182, 50, 50, NO_PRESSED, image_powerGreen);
	ILI9341_DrawMonochromeImage(260, 43, ILI9341_YELLOW, ILI9341_BLACK, tranzistor);
	NPN_PNPButton(NPN, PRESSED);
	NPN_PNPButton(PNP, NO_PRESSED);
    /*if(ILI9341_TouchGetCoordinates(&x, &y)) {                                                // это рисовалка на дисплее)
	 ILI9341_DrawPixel(x, y, ILI9341_WHITE);
	 }*/
}

uint8_t checkAreaTouch(uint16_t xTouch, uint16_t yTouch, uint16_t xScan, uint16_t yScan, uint16_t weight, uint16_t height) { // проверка нажата кнопка или не
	if (xTouch >= xScan && xTouch <= xScan + weight && yTouch >= yScan && yTouch <= yScan + height) return true;  // если мы на клавише вернуть ок
	return false;
}

void checkstrokeArea(void) {                                                                   // проверка нажатия на параметры ( импульс, пауза)
	if (!READ_FLAG(AREA1_PRESS, globalFlag)) {                                                 // если область активна то рисуем желтый прямоугольник
		drawSomePixelRoundRect(7, 28, 242, 48, 4, 2, ILI9341_BLACK);                           // а если нет то черным закрашиваем
	} else {
		drawSomePixelRoundRect(7, 28, 242, 48, 4, 2, ILI9341_YELLOW);
	}
	if (!READ_FLAG(AREA2_PRESS, globalFlag)) {
		drawSomePixelRoundRect(7, 76, 242, 48, 4, 2, ILI9341_BLACK);
	} else {
		drawSomePixelRoundRect(7, 76, 242, 48, 4, 2, ILI9341_YELLOW);
	}
	if (!READ_FLAG(AREA3_PRESS, globalFlag)) {
		drawSomePixelRoundRect(7, 124, 242, 48, 4, 2, ILI9341_BLACK);
	} else {
		drawSomePixelRoundRect(7, 124, 242, 48, 4, 2, ILI9341_YELLOW);
	}
}

void endOperationWindow(uint8_t onOff) {                                                       // табличка генерация завершена
	if (onOff) {
		ILI9341_FillRectangle(40, 60, 180, 60, ILI9341_BLACK);
		drawSomePixelRoundRect(38, 58, 182, 62, 3, 2, ILI9341_YELLOW);
		strcpy(bufSpi, "COMPLETE");
		ILI9341_WriteMyString(48, 65, bufSpi, ILI9341_RED, ILI9341_BLACK);
	} else {
		ILI9341_FillRectangle(38, 58, 182, 62, ILI9341_BLACK);                                 // или же вернуть обратно изображение на дисплее
		printTImpulse();
		printTPause();
		checkstrokeArea();
	}
}

void overCurrent (uint8_t onOff) {                                                            // табличка превышение тока!
	if (onOff) {
		ILI9341_FillRectangle(40, 60, 180, 60, ILI9341_BLACK);
		drawSomePixelRoundRect(38, 58, 182, 62, 3, 2, ILI9341_YELLOW);
		strcpy(bufSpi, "OVER CUR");
		ILI9341_WriteMyString(48, 65, bufSpi, ILI9341_RED, ILI9341_BLACK);
	} else {
		ILI9341_FillRectangle(38, 58, 182, 62, ILI9341_BLACK);                                 // или же вернуть обратно изображение на дисплее
		printTImpulse();
		printTPause();
		checkstrokeArea();
	}
}

void powerButton(void) {                                                                       // включаем/выключаем кнопку повер
	if (!READ_FLAG(ONE_TOUCH, globalFlag) && !timToEndOperation && !timToOvercurrent) {        // единичное нажатие + пока показывает комплит не нажимать
		SET_FLAG(ONE_TOUCH, globalFlag);
		RESET_FLAG(AREA1_PRESS|AREA2_PRESS|AREA3_PRESS, globalFlag);                           // уберем выбор области при пуске
		checkstrokeArea();
		if (ParamDevice.NPNTranzistor || ParamDevice.PNPTranzistor) {                          // если хоть один из транзисторов включен
			if (ParamDevice.power) {                                                           // если питание включено
				ParamDevice.power = false;                                                     // выключим
				printColorImage(246, 182, 50, 50, NO_PRESSED, image_powerGreen);
			} else {
				ParamDevice.power = true;                                                      // а если выключено то включим
				printColorImage(246, 182, 50, 50, PRESSED, image_powerRed);
			}
		}
	}
}

void externalPowerOff(void) {                                                                 // перерисовать кнопку включения из вне
	printColorImage(246, 182, 50, 50, NO_PRESSED, image_powerGreen);
}

void rangeMinMax(uint16_t *data, uint16_t count, uint16_t plus_minus, uint16_t min, uint16_t max) {   // ограничить максимальное количество ввода
	if (plus_minus == PLUS) {
		if (*data + count < max) {
			*data += count;
		} else {
			if (*data < max)
				*data += 1;
		}
	} else {
		if (*data - count > min) {
			*data -= count;
		} else {
			if (*data > min)
				*data -= 1;
		}
	}
}

void changeData(uint16_t count, uint16_t plus_minus) {                                        // изменить параметры импульса
	if (READ_FLAG(AREA1_PRESS, globalFlag)) {                                                 // в зависимости от выбранной области
		if (ParamDevice.unitImpuls != 2) {                                                    // если мы не на секундах
			rangeMinMax(&ParamDevice.impuls, count, plus_minus, 1, 999);                      // то можем изменяться до 999
		} else {
			rangeMinMax(&ParamDevice.impuls, count, plus_minus, 1, 20);                       // а если на секундах то только до 20
		}
		printTImpulse();                                                                      // и перерисуем
		printFreeq();                                                                         // и перепишем частоту
	}
	if (READ_FLAG(AREA2_PRESS, globalFlag)) {
		if (ParamDevice.unitPause != 2) {
			rangeMinMax(&ParamDevice.pause, count, plus_minus, 1, 999);
		} else {
			rangeMinMax(&ParamDevice.pause, count, plus_minus, 1, 20);
		}
		printTPause();
		printFreeq();
	}
	if (READ_FLAG(AREA3_PRESS, globalFlag)) {                                                 // чуть проще для количества повторов
		rangeMinMax(&ParamDevice.count, count, plus_minus, 0, 255);
		printCount();
	}
}

void speedControl(void) {                                                                     // инкремент в зависимости от длительности нажатия
	if (timHoldButtonPress < SPPED4 && timHoldButtonPress > SPPED3) {
		countSpeed = 2;
	}
	if (timHoldButtonPress < SPPED3 && timHoldButtonPress > SPPED2) {
		countSpeed = 5;
	}
	if (timHoldButtonPress < SPPED2 && timHoldButtonPress > SPPED1) {
		countSpeed = 10;
	}
	if (timHoldButtonPress < SPPED1) {
		countSpeed = 25;
	}
}

void changeParamPlusMinus(uint16_t plus_minus) {                                             // обработка нажатий плюс минуса
	if (!READ_FLAG(TOUCH_DISPLAY, globalFlag)) {                                             // одно касание одно нажатие
		SET_FLAG(TOUCH_DISPLAY, globalFlag);
		timHoldButtonPress = SPPED5;                                                         // сбросим время для инкремента
	}
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {                                                 // чтоб можео было нажимать по одному разу
		changeData(1, plus_minus);
	} else {
		if (countSpeed >= 2) {                                                               // спустя время когда у нас счетчик отсчитает увеличиваем на большее количество
			changeData(countSpeed, plus_minus);
			buzzerSet(100 - countSpeed);
		}
	}
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {                                                 // поднимем флаг что один раз уже нажали
		SET_FLAG(ONE_TOUCH, globalFlag);
	}
	speedControl();
}

void togleUnits(void) {                                                                      // переключалка единиц
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {                                                 // так же запрещаем множественное нажатие
		SET_FLAG(ONE_TOUCH, globalFlag);

		if (READ_FLAG(AREA1_PRESS, globalFlag)) {                                            // в зависимости от того в какой мы области
			if (ParamDevice.unitImpuls < 2)
				ParamDevice.unitImpuls++;                                                    // меняем единицы времени
			else
				ParamDevice.unitImpuls = 0;
			printTImpulse();
			if (ParamDevice.unitImpuls == 2 && ParamDevice.impuls > 20) {
				ParamDevice.impuls = 20;
			}
			printTImpulse();                                                                // и обновляем надписи
			printFreeq();
		}
		if (READ_FLAG(AREA2_PRESS, globalFlag)) {
			if (ParamDevice.unitPause < 2)
				ParamDevice.unitPause++;
			else
				ParamDevice.unitPause = 0;
			if (ParamDevice.unitPause == 2 && ParamDevice.pause > 20) {
				ParamDevice.pause = 20;
			}
			printTPause();
			printFreeq();
		}
	}
}

void NPN_PNPButton(uint8_t type, uint8_t status) {                                               // выбираем каким транзистором подавать импульс
	if (type) {
		if (status) {
			ParamDevice.NPNTranzistor = true;                                                    // включаем транзистор
			strcpy(bufSpi, "NPN");
			fillRoundRect(260, 102, 50, 26, 3, ILI9341_YELLOW);                                  // делаем заливку
			ILI9341_WriteString(270, 106, bufSpi, Font_11x18, ILI9341_BLACK, ILI9341_YELLOW);    // печатаем тип транзистора
		} else {
			ParamDevice.NPNTranzistor = false;
			strcpy(bufSpi, "NPN");
			fillRoundRect(260, 102, 50, 26, 3, ILI9341_BLUE);
			ILI9341_WriteString(270, 106, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
		}

	} else {
		if (status) {
			ParamDevice.PNPTranzistor = true;
			strcpy(bufSpi, "PNP");
			fillRoundRect(260, 140, 50, 26, 3, ILI9341_YELLOW);
			ILI9341_WriteString(270, 144, bufSpi, Font_11x18, ILI9341_BLACK, ILI9341_YELLOW);
		} else {
			ParamDevice.PNPTranzistor = false;
			strcpy(bufSpi, "PNP");
			fillRoundRect(260, 140, 50, 26, 3, ILI9341_BLUE);
			ILI9341_WriteString(270, 144, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
		}
	}
	//printTypeOutput();                                                                           // дополнительно вверху переписываем типы транзисторов
}

void setParamNPN_PNP(uint8_t type) {                                                             // отслеживаем нажатие по кнопкам выбора транзистора
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {                                                     // единичное нажатие
		SET_FLAG(ONE_TOUCH, globalFlag);
		if (type == NPN) {                                                                       // ну и дергаем вывод
			if (ParamDevice.NPNTranzistor) {
				NPN_PNPButton(NPN, NO_PRESSED);
			} else {
				NPN_PNPButton(NPN, PRESSED);
			}
		}
		if (type == PNP) {
			if (ParamDevice.PNPTranzistor) {
				NPN_PNPButton(PNP, NO_PRESSED);
			} else {
				NPN_PNPButton(PNP, PRESSED);
			}
		}
	}
}

void checkButtonPress(void) {                                                                    // отслеживаем нажатие кнопок
	if (!READ_TOUCH_IRQ) {                                                                       // считываем нажатие
		if (ILI9341_TouchGetCoordinates(&x, &y)) {                                               // считываем данные из SPI

			if (!READ_FLAG(ONE_BUZZER, globalFlag)) {                                            // ставим флаг чтоб один раз пикнуть бузером
				SET_FLAG(ONE_BUZZER, globalFlag);
				buzzerSet(100);
			}

			if (checkAreaTouch(x, y, 246, 182, 50, 50)) {                                        // считываем не нажата ли кнопка пуск
				powerButton();
			}
			if (!ParamDevice.power) {                                                            // запрещаем что либо менять пока идут импульсы
				if (checkAreaTouch(x, y, 15, 30, 235, 35)) {                                     // проверка и сброс соседних областей
					RESET_FLAG(AREA2_PRESS|AREA3_PRESS, globalFlag);
					SET_FLAG(AREA1_PRESS, globalFlag);
					checkstrokeArea();                                                           // нарисуем какая область нажата
				}

				if (checkAreaTouch(x, y, 15, 78, 235, 35)) {
					RESET_FLAG(AREA1_PRESS|AREA3_PRESS, globalFlag);
					SET_FLAG(AREA2_PRESS, globalFlag);
					checkstrokeArea();
				}

				if (checkAreaTouch(x, y, 15, 126, 235, 35)) {
					RESET_FLAG(AREA1_PRESS|AREA2_PRESS, globalFlag);
					SET_FLAG(AREA3_PRESS, globalFlag);
					checkstrokeArea();
				}

				if (checkAreaTouch(x, y, 24, 182, 50, 50)) {
					printColorImage(24, 182, 50, 50, PRESSED, image_Plus);
					changeParamPlusMinus(PLUS);
				}

				if (checkAreaTouch(x, y, 172, 182, 50, 50)) {
					printColorImage(172, 182, 50, 50, PRESSED, image_Minus);
					changeParamPlusMinus(MINUS);
				}

				if (checkAreaTouch(x, y, 98, 182, 50, 50)) {
					printColorImage(98, 182, 50, 50, PRESSED, image_Arrow);
					togleUnits();
				}

				if (checkAreaTouch(x, y, 260, 102, 50, 26)) {
					setParamNPN_PNP(NPN);
				}

				if (checkAreaTouch(x, y, 260, 140, 50, 26)) {
					setParamNPN_PNP(PNP);
				}
			}
		}
		timBigArea = 5000;                                                  // задержка на обводку области квадратом
		timButtonPress = 50;                                                // задержка для защиты от дребезга
	} else {
		RESET_FLAG(ONE_BUZZER, globalFlag);                                 // сбросим пищалку
	}
	GUIPostHandler();                                                       // обработаем сбросы
}

void GUIPostHandler(void) {
	if (timBigArea == 0 && (globalFlag & 0x38)) {
		RESET_FLAG(AREA1_PRESS|AREA2_PRESS|AREA3_PRESS, globalFlag);
		checkstrokeArea();
	}
	if (timButtonPress == 0 && READ_FLAG(ONE_TOUCH, globalFlag)) {          // сбросим нажатия на кнопки и защиту от множества нажатий и скорость
		printColorImage(24, 182, 50, 50, NO_PRESSED, image_Plus);
		printColorImage(172, 182, 50, 50, NO_PRESSED, image_Minus);
		printColorImage(98, 182, 50, 50, NO_PRESSED, image_Arrow);
		RESET_FLAG(TOUCH_DISPLAY, globalFlag);
		RESET_FLAG(ONE_TOUCH, globalFlag);
		countSpeed = 1;
	}
}

//------------------------------ примечания --------------------------------------------//
