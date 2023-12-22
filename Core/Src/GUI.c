#include "GUI.h"

//----------------------- переменные из других файлов --------------------------------//
extern uint32_t globalFlag;
extern uint32_t globalGUIFlag;
extern struct ChangParamDevice ParamDevice;
//----------------------- переменные из этого файла ----------------------------------//
char bufSpi[20] = { };
char *unitTXT[3] = { "us", "ms", "s  ", };

uint16_t x, y, countSpeed = 1;
uint32_t timBigArea = 0, timButtonPress = 0, timHoldButtonPress = 0;
//------------------------------ функции ---------------------------------------------//
void GUICalibration (uint8_t pozition){
	ILI9341_FillRectangle (0,0,25,25,ILI9341_BLACK);
	ILI9341_FillRectangle (299,0,25,25,ILI9341_BLACK);
	ILI9341_FillRectangle (0,219,25,25,ILI9341_BLACK);
	ILI9341_FillRectangle (299,219,25,25,ILI9341_BLACK);
	switch (pozition) {
	case 0:
		ILI9341_WriteString(15, 50, "Display calibration, click", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		ILI9341_WriteString(15, 70, "on all the circles in turn", Font_11x18, ILI9341_YELLOW, ILI9341_BLACK);
		drawCircle (10,10,10,ILI9341_YELLOW);
		drawCircle (10,10,9,ILI9341_YELLOW);
		break;
	case 1:
		drawCircle (309,10,10,ILI9341_YELLOW);
		drawCircle (309,10,9,ILI9341_YELLOW);
		break;
	case 2:
		drawCircle (10,229,10,ILI9341_YELLOW);
		drawCircle (10,229,9,ILI9341_YELLOW);
		break;
	case 3:
		drawCircle (309,229,10,ILI9341_YELLOW);
		drawCircle (309,229,9,ILI9341_YELLOW);
		break;
	}
}

void setOK (uint8_t flag) {
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
	ILI9341_FillScreen(ILI9341_YELLOW);
	ILI9341_WriteString(20, 0, "Note!(')", Font_16x26, ILI9341_YELLOW,
	ILI9341_BLACK);
	ILI9341_WriteMyString(20, 50, "Note!(~)", ILI9341_YELLOW, ILI9341_BLACK);
	ILI9341_FillScreen(ILI9341_BLACK);
}

void workDisplay(void) {
	//mainDisplayPrint();
    if(ILI9341_TouchGetCoordinates(&x, &y)) {
        ILI9341_DrawPixel(x, y, ILI9341_WHITE);
    }
}

void printStaticText(void) {
	fillRect(0, 0, 320, 22, ILI9341_BLUE);
	strcpy(bufSpi, "Freq = 25Mh");
	ILI9341_WriteString(10, 2, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
}

void printTImpulse() {
	strcpy(bufSpi, "T imp:");
	ILI9341_WriteMyString(12, 30, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
	sprintf(bufSpi, "%-3d %s  ", ParamDevice.impuls, unitTXT[ParamDevice.unitImpuls]);
	ILI9341_WriteMyString(125, 30, bufSpi, ILI9341_GREEN, ILI9341_BLACK);
}

void printTPause() {
	strcpy(bufSpi, "T paus:");
	ILI9341_WriteMyString(12, 78, bufSpi, ILI9341_YELLOW, ILI9341_BLACK);
	sprintf(bufSpi, "%-3d %s  ", ParamDevice.pause, unitTXT[ParamDevice.unitPause]);
	ILI9341_WriteMyString(125, 78, bufSpi, ILI9341_YELLOW, ILI9341_BLACK);
}

void printCount() {
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

void checkstrokeArea(void) {
	if (!READ_FLAG(AREA1_PRESS, globalGUIFlag)) {
		drawSomePixelRoundRect(7, 28, 242, 48, 4, 2, ILI9341_BLACK);
	} else {
		drawSomePixelRoundRect(7, 28, 242, 48, 4, 2, ILI9341_YELLOW);
	}
	if (!READ_FLAG(AREA2_PRESS, globalGUIFlag)) {
		drawSomePixelRoundRect(7, 76, 242, 48, 4, 2, ILI9341_BLACK);
	} else {
		drawSomePixelRoundRect(7, 76, 242, 48, 4, 2, ILI9341_YELLOW);
	}
	if (!READ_FLAG(AREA3_PRESS, globalGUIFlag)) {
		drawSomePixelRoundRect(7, 124, 242, 48, 4, 2, ILI9341_BLACK);
	} else {
		drawSomePixelRoundRect(7, 124, 242, 48, 4, 2, ILI9341_YELLOW);
	}
}

void mainDisplayPrint(void) {
	printStaticText();
	printTImpulse();
	printTPause();
	printCount();
	printColorImage(24, 182, 50, 50, NO_PRESSED, image_Plus);
	printColorImage(98, 182, 50, 50, NO_PRESSED, image_Arrow);
	printColorImage(172, 182, 50, 50, NO_PRESSED, image_Minus);
	printColorImage(246, 182, 50, 50, NO_PRESSED, image_powerGreen);

	ILI9341_DrawMonochromeImage(260, 43, ILI9341_YELLOW, ILI9341_BLACK, tranzistor);
	strcpy(bufSpi, "NPN");
	fillRoundRect(260, 102, 50, 26, 3, ILI9341_BLUE);
	ILI9341_WriteString(270, 106, bufSpi, Font_11x18, ILI9341_WHITE,
	ILI9341_BLUE);
	strcpy(bufSpi, "PNP");
	fillRoundRect(260, 140, 50, 26, 3, ILI9341_BLUE);
	ILI9341_WriteString(270, 144, bufSpi, Font_11x18, ILI9341_WHITE, ILI9341_BLUE);
}

uint8_t checkAreaTouch(uint16_t xTouch, uint16_t yTouch, uint16_t xScan, uint16_t yScan, uint16_t weight, uint16_t height) {
	if (xTouch >= xScan && xTouch <= xScan + weight && yTouch >= yScan && yTouch <= yScan + height)
		return true;
	return false;
}

void powerButton(void) {
	if (!READ_FLAG(ONE_TOUCH, globalFlag)) {
		SET_FLAG(ONE_TOUCH, globalFlag);
		if (ParamDevice.power) {
			ParamDevice.power = false;
			printColorImage(246, 182, 50, 50, PRESSED, image_powerGreen);
		} else {
			ParamDevice.power = true;
			printColorImage(246, 182, 50, 50, NO_PRESSED, image_powerRed);
		}
	}
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
	if (READ_FLAG(AREA1_PRESS, globalGUIFlag)) {
		rangeMinMax(&ParamDevice.impuls, count, plus_minus, 1, 999);
		printTImpulse();
	}
	if (READ_FLAG(AREA2_PRESS, globalGUIFlag)) {
		rangeMinMax(&ParamDevice.pause, count, plus_minus, 1, 999);
		printTPause();
	}
	if (READ_FLAG(AREA3_PRESS, globalGUIFlag)) {
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

void setFlagOneTouch(uint16_t plus_minus) {
	if (!READ_FLAG(TOUCH_DISPLAY, globalFlag)) {
		SET_FLAG(TOUCH_DISPLAY, globalFlag);
		timHoldButtonPress = SPPED5;
	}
	if (!READ_FLAG(ONE_TOUCH, globalFlag) && countSpeed < 2) {
		changeData(1, plus_minus);
	} else {
		if (countSpeed >= 2) {
			changeData(countSpeed, plus_minus);
			if (globalGUIFlag & 0x07)
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
		if (READ_FLAG(AREA1_PRESS, globalGUIFlag)) {
			if (ParamDevice.unitImpuls < 2)
				ParamDevice.unitImpuls++;
			else
				ParamDevice.unitImpuls = 0;
			printTImpulse();
		}
		if (READ_FLAG(AREA2_PRESS, globalGUIFlag)) {
			if (ParamDevice.unitPause < 2)
				ParamDevice.unitPause++;
			else
				ParamDevice.unitPause = 0;
			printTPause();
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

			if (checkAreaTouch(x, y, 15, 30, 235, 35)) {
				RESET_FLAG(AREA2_PRESS|AREA3_PRESS, globalGUIFlag);
				SET_FLAG(AREA1_PRESS, globalGUIFlag);
				checkstrokeArea();
			}

			if (checkAreaTouch(x, y, 15, 78, 235, 35)) {
				RESET_FLAG(AREA1_PRESS|AREA3_PRESS, globalGUIFlag);
				SET_FLAG(AREA2_PRESS, globalGUIFlag);
				checkstrokeArea();
			}

			if (checkAreaTouch(x, y, 15, 126, 235, 35)) {
				RESET_FLAG(AREA1_PRESS|AREA2_PRESS, globalGUIFlag);
				SET_FLAG(AREA3_PRESS, globalGUIFlag);
				checkstrokeArea();
			}

			if (checkAreaTouch(x, y, 24, 182, 50, 50)) {
				SET_FLAG(BUTTON1_PRESS, globalGUIFlag);
				printColorImage(24, 182, 50, 50, PRESSED, image_Plus);
				setFlagOneTouch(PLUS);
			}

			if (checkAreaTouch(x, y, 98, 182, 50, 50)) {
				SET_FLAG(BUTTON2_PRESS, globalGUIFlag);
				printColorImage(98, 182, 50, 50, PRESSED, image_Arrow);
				togleUnits();
			}

			if (checkAreaTouch(x, y, 172, 182, 50, 50)) {
				SET_FLAG(BUTTON3_PRESS, globalGUIFlag);
				printColorImage(172, 182, 50, 50, PRESSED, image_Minus);
				setFlagOneTouch(MINUS);
			}
			if (checkAreaTouch(x, y, 246, 182, 50, 50)) {
				SET_FLAG(BUTTON4_PRESS, globalGUIFlag);
				powerButton();
			}
		}
		timBigArea = 5000;
		timButtonPress = 50;
		ParamDevice.changeParametrs = true;
	} else {
		RESET_FLAG(ONE_BUZZER, globalFlag);
	}
	GUIPostHandler();
}

void GUIPostHandler(void) {
	if (timBigArea == 0 && (globalGUIFlag & 0x07)) {
		RESET_FLAG(AREA1_PRESS|AREA2_PRESS|AREA3_PRESS, globalGUIFlag);
		checkstrokeArea();
	}
	if (timButtonPress == 0 && (globalGUIFlag & 0x3F8)) {
		RESET_FLAG(BUTTON1_PRESS|BUTTON2_PRESS|BUTTON3_PRESS, globalGUIFlag);
		printColorImage(24, 182, 50, 50, NO_PRESSED, image_Plus);
		printColorImage(172, 182, 50, 50, NO_PRESSED, image_Minus);
		printColorImage(98, 182, 50, 50, NO_PRESSED, image_Arrow);
		RESET_FLAG(TOUCH_DISPLAY, globalFlag);
		RESET_FLAG(ONE_TOUCH, globalFlag);
		countSpeed = 1;
	}
}

//------------------------------ примечания --------------------------------------------//
