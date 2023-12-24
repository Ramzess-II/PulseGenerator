#include "timers.h"

//----------------------- переменные из других файлов --------------------------------//
extern uint32_t globalFlag;
extern struct ChangParamDevice ParamDevice;
extern TIM_HandleTypeDef htim5;
//----------------------- переменные из этого файла ----------------------------------//
uint32_t multiplicationFactor[3] = { 100, 100000, 100000000 };
//------------------------------ функции ---------------------------------------------//
void setTimAndStart(void) {
	ParamDevice.changeCount = ParamDevice.count;
	CLEAR_BIT(TIM5->SR, TIM_SR_CC2IF|TIM_SR_CC3IF); // очищаем флаг
	//__HAL_TIM_CLEAR_FLAG(&htim5, TIM_SR_UIF);     // очищаем флаг
	TIM5->ARR = (ParamDevice.impuls * multiplicationFactor[ParamDevice.unitImpuls]) + (ParamDevice.pause * multiplicationFactor[ParamDevice.unitPause]);
	TIM5->CCR2 = (ParamDevice.impuls * multiplicationFactor[ParamDevice.unitImpuls]);
	TIM5->CCR3 = (ParamDevice.impuls * multiplicationFactor[ParamDevice.unitImpuls]);
	//TIM5->CNT = TIM5->ARR;
	TIM5->CNT = 0;
	SET_BIT(TIM5->EGR, TIM_EGR_UG);  // применим данные
	if (!ParamDevice.changeCount) {
		ParamDevice.flagInfinity = true;
	}
	if (ParamDevice.PNPTranzistor && !ParamDevice.NPNTranzistor) {
		if (!ParamDevice.flagInfinity) SET_BIT(TIM5->DIER, TIM_DIER_CC3IE);
		SET_BIT(TIM5->CCER, TIM_CCER_CC3E);
		//HAL_TIM_PWM_Start_IT(&htim5, TIM_CHANNEL_3);
	}
	if (ParamDevice.NPNTranzistor) {
		if (!ParamDevice.flagInfinity) SET_BIT(TIM5->DIER, TIM_DIER_CC2IE);
		SET_BIT(TIM5->CCER, TIM_CCER_CC2E);
		//HAL_TIM_PWM_Start_IT(&htim5, TIM_CHANNEL_2);
	}
	if (ParamDevice.PNPTranzistor && ParamDevice.NPNTranzistor) {
		SET_BIT(TIM5->CCER, TIM_CCER_CC3E);
		//HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
	}
	SET_BIT(TIM5->CR1, TIM_CR1_CEN);  // запустим таймер
	//HAL_TIM_Base_Start(&htim5); гавно хал
}

void timerOff(void) {
	CLEAR_BIT(TIM5->CCER, TIM_CCER_CC2E|TIM_CCER_CC3E);
	CLEAR_BIT(TIM5->DIER, TIM_DIER_CC2IE|TIM_DIER_CC3IE);
	CLEAR_BIT(TIM5->CR1, TIM_CR1_CEN);
	ParamDevice.flagInfinity = false;
}
//------------------------------ примечания ------------------------------------------//
