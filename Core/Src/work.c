#include "work.h"
//----------------------- переменные из других файлов --------------------------------//
extern uint32_t globalFlag;

//----------------------- переменные из этого файла ----------------------------------//
struct ChangParamDevice ParamDevice = {100,100,0,0,0,0,0,0,0,};
uint32_t timToDisplay = 0;
uint32_t* memADR = (uint32_t*)ADR_DATA_MIN_X;
//------------------------------ функции ---------------------------------------------//



void calibration (void){
	if (*memADR == 0xFFFFFFFF) {
		setOK (false);
		GUICalibration (0);
		calibTouch(0);
		setOK (true);
		HAL_Delay(1000);
		setOK (false);
		GUICalibration (1);
		calibTouch(1);
		setOK (true);
		HAL_Delay(1000);
		setOK (false);
		GUICalibration (2);
		calibTouch(2);
		setOK (true);
		HAL_Delay(1000);
		setOK (false);
		GUICalibration (3);
		calibTouch(3);
		setOK (true);
		HAL_Delay(1000);
	}
}

void doWork (void){
	startDisplay ();
	workDisplay();
	calibration();
	ILI9341_ToucInit();
}

void Work (void){
	//checkButtonPress();
	workDisplay();
}


/**************************************************************************
   @brief     will return the modulus of the num like abs in C
    @param    num  incoming number
**************************************************************************/


/**************************************************************************
   @brief     swaps values in variables
    @param    a  num first
    @param    a  num two
**************************************************************************/




//------------------------------ примечания --------------------------------------------//
