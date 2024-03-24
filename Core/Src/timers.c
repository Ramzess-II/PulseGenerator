#include "timers.h"
//----------------------- переменные из других файлов --------------------------------//
extern uint32_t globalFlag;
extern struct ChangParamDevice ParamDevice;
extern TIM_HandleTypeDef htim5;
//----------------------- переменные из этого файла ----------------------------------//
uint32_t multiplicationFactor[3] = { 100, 100000, 100000000 };   //множитель
//------------------------------ функции ---------------------------------------------//
void setTimAndStart(void) {
	ParamDevice.changeCount = ParamDevice.count * ((ParamDevice.unitCount * 1000) + 1);       // копируем из статических счетчиков в динамические и умножаем чтоб получить 1к
	CLEAR_BIT(TIM5->CCMR1, TIM_CCMR1_OC2M);                 // очистим регистр
	CLEAR_BIT(TIM5->CCMR2, TIM_CCMR2_OC3M);                 // очистим регистр
	CLEAR_BIT(TIM5->SR, TIM_SR_CC2IF|TIM_SR_CC3IF);         // очищаем флаг
	//__HAL_TIM_CLEAR_FLAG(&htim5, TIM_SR_UIF);             // очищаем флаг
	TIM5->ARR = (ParamDevice.impuls * multiplicationFactor[ParamDevice.unitImpuls]) + (ParamDevice.pause * multiplicationFactor[ParamDevice.unitPause]);
	TIM5->CCR2 = (ParamDevice.impuls * multiplicationFactor[ParamDevice.unitImpuls]);
	TIM5->CCR3 = (ParamDevice.impuls * multiplicationFactor[ParamDevice.unitImpuls]);
	// пересчитываем время паузы и время импульса исходя из того что частота 100МГц
	//TIM5->CNT = TIM5->ARR;
	TIM5->CNT = 0;
	//HAL_TIM_GenerateEvent(&htim5, TIM_EVENTSOURCE_UPDATE);
	SET_BIT(TIM5->EGR, TIM_EGR_UG);  // применим данные
	if (!ParamDevice.changeCount) {  // тут если ноль то ставим бесконечный импульс
		ParamDevice.flagInfinity = true;
	}
	if (ParamDevice.PNPTranzistor && !ParamDevice.NPNTranzistor) {            // смотрим какой транзистор включен и какой канал запускать
		if (!ParamDevice.flagInfinity) SET_BIT(TIM5->DIER, TIM_DIER_CC3IE);   // если не бесконечное количество запустим прерывания
		SET_BIT(TIM5->CCMR1, 0b110 << TIM_CCMR1_OC2M_Pos);                    // PWM mode 1
		//HAL_TIM_PWM_Start_IT(&htim5, TIM_CHANNEL_3);
	}
	if (ParamDevice.NPNTranzistor) {
		if (!ParamDevice.flagInfinity) SET_BIT(TIM5->DIER, TIM_DIER_CC2IE);   // если не бесконечное количество запустим прерывания
		SET_BIT(TIM5->CCMR2, 0b110 << TIM_CCMR2_OC3M_Pos);                    // PWM mode 1
		//HAL_TIM_PWM_Start_IT(&htim5, TIM_CHANNEL_2);
	}
	if (ParamDevice.PNPTranzistor && ParamDevice.NPNTranzistor) {
		SET_BIT(TIM5->CCMR1, 0b110 << TIM_CCMR1_OC2M_Pos);                    // PWM mode 1
		SET_BIT(TIM5->CCMR2, 0b110 << TIM_CCMR2_OC3M_Pos);                    // PWM mode 1
		//HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
	}
	// тут сложная логика, задача включить только одно прерывание от сравнения. и мы проверяем какой транзистор активный и от этого включаем прерывание
	SET_BIT(TIM5->CR1, TIM_CR1_CEN);  // запустим таймер
	//HAL_TIM_Base_Start(&htim5); гавно хал
}

void timerOff(void) {                                       // для вызова из программы
	CLEAR_BIT(TIM5->CCMR1, TIM_CCMR1_OC2M);                 // очистим регистр
	CLEAR_BIT(TIM5->CCMR2, TIM_CCMR2_OC3M);                 // очистим регистр
	SET_BIT(TIM5->CCMR1, 0b100 << TIM_CCMR1_OC2M_Pos);      // ноль на выходе Force inactive level
	SET_BIT(TIM5->CCMR2, 0b100 << TIM_CCMR2_OC3M_Pos);      // ноль на выходе Force inactive level
	CLEAR_BIT(TIM5->DIER, TIM_DIER_CC2IE|TIM_DIER_CC3IE);
	CLEAR_BIT(TIM5->CR1, TIM_CR1_CEN);
	ParamDevice.flagInfinity = false;
}
//------------------------------ примечания ------------------------------------------//
