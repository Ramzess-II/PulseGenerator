#include "GUI.h"

//----------------------- переменные из других файлов --------------------------------//
extern uint32_t globalFlag;
extern struct ChangParamDevice ParamDevice;
//----------------------- переменные из этого файла ----------------------------------//
char bufSpi[40] = { };
char *unitTXT[3] = { "us", "ms", "s   ", };
char *unitFreq[3] = { "Hz ", "kHz", "MHz", };
uint32_t multiplicationFreq[3] = { 1000000, 1000, 1 };
uint16_t x, y, countSpeed = 1;
uint32_t timBigArea = 0, timButtonPress = 0, timHoldButtonPress = 0;
//------------------------------ функции ---------------------------------------------//
void screenSaver (void) {
	ILI9341_FillScreen(ILI9341_BLACK);
	strcpy(bufSpi, "PULSE");
	ILI9341_WriteMyString(105, 76, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
	strcpy(bufSpi, "GENERATOR");
	ILI9341_WriteMyString(65, 120, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
	ILI9341_WriteString(250, 220, "Ver1.1", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
	drawSomePixelRoundRect(40, 66, 240, 108, 4, 2, ILI9341_YELLOW);
	HAL_Delay(2000);
	buzzerSet(100);
}

void GUICalibration(uint8_t pozition) {
	switch (pozition) {
	case LEFTUP:
		ILI9341_FillScreen(ILI9341_BLACK);
		ILI9341_WriteString(15, 50, "Display calibration, click", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		ILI9341_WriteString(15, 70, "on all the circles in turn", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		drawCircle(10, 10, 10, ILI9341_YELLOW);
		drawCircle(10, 10, 9, ILI9341_YELLOW);
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
		ILI9341_FillRectangle(299, 219, 25, 25, ILI9341_BLACK);
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

void setOK(uint8_t flag) {
	if (flag) {
		ILI9341_WriteString(140, 100, " OK    ", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
	} else {
		ILI9341_WriteString(140, 100, "Wait", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
	}
}

void startDisplay(void) {
	ILI9341_TouchUnselect();
	ILI9341_Unselect();
	HAL_Delay(10);
	SET_BIT(SPI1->CR1, SPI_CR1_SPE);
	ILI9341_Init();
	ILI9341_Select();
	ILI9341_FillScreen(ILI9341_BLACK);
	HAL_Delay(100);
}

void printFreeq(void) {
	uint8_t count = 0;
	float freq = 0;
	freq = (1 / (((float) ParamDevice.impuls / (float) multiplicationFreq[ParamDevice.unitImpuls]) +
			((float) ParamDevice.pause / (float) multiplicationFreq[ParamDevice.unitPause])));
	if (freq >= 1000000) {
		count = 2;
		freq = freq / 1000000;
	}
	if (freq >= 1000) {
		count = 1;
		freq = freq / 1000;
	}
	strcpy(bufSpi, "Freq=");
	ILI9341_WriteString(10, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
	sprintf(bufSpi, "%06.2f%s", freq, unitFreq[count]);
	ILI9341_WriteString(65, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
}

void printTypeOutput(void) {
	ILI9341_FillRectangle(190, 0, 160, 22, ILI9341_BLUE);
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
}

void printTImpulse(void) {
	strcpy(bufSpi, "T imp:");
	ILI9341_WriteMyString(12, 30, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
	sprintf(bufSpi, "%-3d %s  ", ParamDevice.impuls, unitTXT[ParamDevice.unitImpuls]);
	ILI9341_WriteMyString(125, 30, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
}

void printTPause(void) {
	strcpy(bufSpi, "T paus:");
	ILI9341_WriteMyString(12, 78, bufSpi, ILI9341_YELLOW, ILI9341_BLACK);
	sprintf(bufSpi, "%-3d %s  ", ParamDevice.pause, unitTXT[ParamDevice.unitPause]);
	ILI9341_WriteMyString(125, 78, bufSpi, ILI9341_YELLOW, ILI9341_BLACK);
}

void printCount(void) {
	strcpy(bufSpi, "Count:");
	ILI9341_WriteMyString(12, 126, bufSpi, ILI9341_PURPLE, ILI9341_BLACK);
	if (ParamDevice.count) {
		sprintf(bufSpi, "%-3d %s  ", ParamDevice.count, "rp");
		ILI9341_WriteMyString(125, 126, bufSpi, ILI9341_PURPLE, ILI9341_BLACK);
	} else {
		sprintf(bufSpi, "~   %s  ", "rp");
		ILI9341_WriteMyString(125, 126, bufSpi, ILI9341_PURPLE, ILI9341_BLACK);
	}
}

void printColorImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		uint16_t status, const uint16_t *data) {
	if (status == NO_PRESSED) {
		drawRect(x - 1, y - 1, w + 2, h + 2, ILI9341_BLACK);
		ILI9341_DrawImage(x, y, w, h, data);
	}
	if (status == PRESSED) {
		drawRect(x, y, w + 2, h + 2, ILI9341_BLACK);
		ILI9341_DrawImage(x + 1, y + 1, w, h, data);
	}
}

void mainDisplayPrint(void) {
	ILI9341_FillScreen(ILI9341_BLACK);
	ILI9341_FillRectangle(0, 0, 320, 22, ILI9341_BLUE);
	printTypeOutput();
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
    /*if(ILI9341_TouchGetCoordinates(&x, &y)) {
	 ILI9341_DrawPixel(x, y, ILI9341_WHITE);
	 }*/
}

uint8_t checkAreaTouch(uint16_t xTouch, uint16_t yTouch, uint16_t xScan, uint16_t yScan, uint16_t weight, uint16_t height) {
	if (xTouch >= xScan && xTouch <= xScan + weight && yTouch >= yScan && yTouch <= yScan + height)
		return true;
	return false;
}

void checkstrokeArea(void) {
	if (!READ_FLAG(AREA1_PRESS, globalFlag)) {
		drawSomePixelRoundRect(7, 28, 242, 48, 4, 2, ILI9341_BLACK);
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

void endOperationWindow(uint8_t onOff) {
	if (onOff) {
		ILI9341_FillRectangle(40, 60, 180, 60, ILI9341_BLACK);
		drawSomePixelRoundRect(38, 58, 182, 62, 3, 2, ILI9341_YELLOW);
		strcpy(bufSpi, "COMPLETE");
		ILI9341_WriteMyString(48, 65, bufSpi, ILI9341_RED, ILI9341_BLACK);
	} else {
		ILI9341_FillRectangle(38, 58, 182, 62, ILI9341_BLACK);
		printTImpulse();
		printTPause();
		checkstrokeArea();
	}
}

void powerButton(void) {
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {
		SET_FLAG(ONE_TOUCH, globalFlag);
		if (ParamDevice.NPNTranzistor || ParamDevice.PNPTranzistor) {
			if (ParamDevice.power) {
				ParamDevice.power = false;
				printColorImage(246, 182, 50, 50, NO_PRESSED, image_powerGreen);
			} else {
				ParamDevice.power = true;
				printColorImage(246, 182, 50, 50, PRESSED, image_powerRed);
			}
		}
	}
}

void externalPowerOff(void) {
	printColorImage(246, 182, 50, 50, NO_PRESSED, image_powerGreen);
}

void rangeMinMax(uint16_t *data, uint16_t count, uint16_t plus_minus, uint16_t min, uint16_t max) {
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

void changeData(uint16_t count, uint16_t plus_minus) {
	if (READ_FLAG(AREA1_PRESS, globalFlag)) {
		if (ParamDevice.unitImpuls != 2) {
			rangeMinMax(&ParamDevice.impuls, count, plus_minus, 1, 999);
		} else {
			rangeMinMax(&ParamDevice.impuls, count, plus_minus, 1, 20);
		}
		printTImpulse();
		printFreeq();
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
	if (READ_FLAG(AREA3_PRESS, globalFlag)) {
		rangeMinMax(&ParamDevice.count, count, plus_minus, 0, 255);
		printCount();
	}
}

void speedControl(void) {
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

void changeParamPlusMinus(uint16_t plus_minus) {
	if (!READ_FLAG(TOUCH_DISPLAY, globalFlag)) {
		SET_FLAG(TOUCH_DISPLAY, globalFlag);
		timHoldButtonPress = SPPED5;
	}
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {
		changeData(1, plus_minus);
	} else {
		if (countSpeed >= 2) {
			changeData(countSpeed, plus_minus);
			buzzerSet(100 - countSpeed);
		}
	}
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {
		SET_FLAG(ONE_TOUCH, globalFlag);
	}
	speedControl();
}

void togleUnits(void) {
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {
		SET_FLAG(ONE_TOUCH, globalFlag);

		if (READ_FLAG(AREA1_PRESS, globalFlag)) {
			if (ParamDevice.unitImpuls < 2)
				ParamDevice.unitImpuls++;
			else
				ParamDevice.unitImpuls = 0;
			printTImpulse();
			if (ParamDevice.unitImpuls == 2 && ParamDevice.impuls > 20) {
				ParamDevice.impuls = 20;
			}
			printTImpulse();
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

void NPN_PNPButton(uint8_t type, uint8_t status) {
	if (type) {
		if (status) {
			ParamDevice.NPNTranzistor = true;
			strcpy(bufSpi, "NPN");
			fillRoundRect(260, 102, 50, 26, 3, ILI9341_YELLOW);
			ILI9341_WriteString(270, 106, bufSpi, Font_11x18, ILI9341_BLACK, ILI9341_YELLOW);
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
	printTypeOutput();
}

void setParamNPN_PNP(uint8_t type) {
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {
		SET_FLAG(ONE_TOUCH, globalFlag);
		if (type == NPN) {
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

void checkButtonPress(void) {
	if (!READ_BIT(GPIOB->IDR, GPIO_IDR_ID12)) {
		if (ILI9341_TouchGetCoordinates(&x, &y)) {

			if (!READ_FLAG(ONE_BUZZER, globalFlag)) {
				SET_FLAG(ONE_BUZZER, globalFlag);
				buzzerSet(100);
			}

			if (checkAreaTouch(x, y, 246, 182, 50, 50)) {
				powerButton();
			}
			if (!ParamDevice.power) {
				if (checkAreaTouch(x, y, 15, 30, 235, 35)) {
					RESET_FLAG(AREA2_PRESS|AREA3_PRESS, globalFlag);
					SET_FLAG(AREA1_PRESS, globalFlag);
					checkstrokeArea();
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
		timBigArea = 5000;
		timButtonPress = 50;
		//ParamDevice.changeParametrs = true;
	} else {
		RESET_FLAG(ONE_BUZZER, globalFlag);
	}
	GUIPostHandler();
}

void GUIPostHandler(void) {
	if (timBigArea == 0 && (globalFlag & 0x38)) {
		RESET_FLAG(AREA1_PRESS|AREA2_PRESS|AREA3_PRESS, globalFlag);
		checkstrokeArea();
	}
	if (timButtonPress == 0 && READ_FLAG(ONE_TOUCH, globalFlag)) {
		printColorImage(24, 182, 50, 50, NO_PRESSED, image_Plus);
		printColorImage(172, 182, 50, 50, NO_PRESSED, image_Minus);
		printColorImage(98, 182, 50, 50, NO_PRESSED, image_Arrow);
		RESET_FLAG(TOUCH_DISPLAY, globalFlag);
		RESET_FLAG(ONE_TOUCH, globalFlag);
		countSpeed = 1;
	}
}

//------------------------------ примечания --------------------------------------------//
