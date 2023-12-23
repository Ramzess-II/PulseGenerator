#include "work.h"
//----------------------- переменные из других файлов --------------------------------//
extern uint32_t globalFlag;
//----------------------- переменные из этого файла ----------------------------------//
struct ChangParamDevice ParamDevice = {
		.impuls = 100,
		.pause = 100,
		.count = 0,
		.changeCount = 0,
		.unitImpuls = 0,
		.unitPause = 0,
		//.flagInfinity = 0,
		.NPNTranzistor = 1,
		.PNPTranzistor = 0,
		.power = 0,
		//.changeParametrs = 0,
};
uint32_t timToDisplay = 0;
uint32_t* memADR = (uint32_t*)ADR_DATA_MIN_X;
//------------------------------ функции ---------------------------------------------//

void doWork (void){
	startDisplay ();
	calibration();
	ILI9341_ToucInit();
	workDisplay();
}

void Work (void){
	checkButtonPress();
}

void setPowerOffButton (void) {

}


void calibration (void){
	if (*memADR == 0xFFFFFFFF) {
		reset:
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
