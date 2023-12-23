#include "Ili9341LibTouch.h"

//----------------------- переменные из этого файла ----------------------------------//
uint32_t minRawX;
uint32_t maxRawX;
uint32_t minRawY;
uint32_t maxRawY;
uint32_t minX, maxX, minY, maxY;
//------------------------------ функции ---------------------------------------------//

void ILI9341_ToucInit(void) {
	uint32_t *tempAdr = (uint32_t*) ADR_DATA_MIN_X;
	minRawX = *tempAdr;
	tempAdr = (uint32_t*) ADR_DATA_MAX_X;
	maxRawX = *tempAdr;
	tempAdr = (uint32_t*) ADR_DATA_MIN_Y;
	minRawY = *tempAdr;
	tempAdr = (uint32_t*) ADR_DATA_MAX_Y;
	maxRawY = *tempAdr;
}
/**************************************************************************
 @brief     will return the modulus of the num like abs in C
 @param    num  incoming number
 **************************************************************************/
static void ILI9341_TouchSelect() {
	HAL_GPIO_WritePin(ILI9341_TOUCH_CS_GPIO_Port, ILI9341_TOUCH_CS_Pin, GPIO_PIN_RESET);
}

/**************************************************************************
 @brief     swaps values in variables
 @param    a  num first
 @param    a  num two
 **************************************************************************/
void ILI9341_TouchUnselect() {
	HAL_GPIO_WritePin(ILI9341_TOUCH_CS_GPIO_Port, ILI9341_TOUCH_CS_Pin, GPIO_PIN_SET);
}

bool ILI9341_TouchPressed() {
	return HAL_GPIO_ReadPin(ILI9341_TOUCH_IRQ_GPIO_Port, ILI9341_TOUCH_IRQ_Pin) == GPIO_PIN_RESET;
}

bool ILI9341_TouchGetCoordinates(uint16_t *x, uint16_t *y) {
	static const uint8_t cmd_read_x[] = { READ_X };
	static const uint8_t cmd_read_y[] = { READ_Y };
	static const uint8_t zeroes_tx[] = { 0x00, 0x00 };

	ILI9341_TouchSelect();

	uint32_t avg_x = 0;
	uint32_t avg_y = 0;
	uint8_t nsamples = 0;
	for (uint8_t i = 0; i < 16; i++) {
		if (!ILI9341_TouchPressed())
			break;

		nsamples++;

		HAL_SPI_Transmit(&ILI9341_TOUCH_SPI_PORT, (uint8_t*) cmd_read_y, sizeof(cmd_read_y), HAL_MAX_DELAY);
		uint8_t y_raw[2];
		HAL_SPI_TransmitReceive(&ILI9341_TOUCH_SPI_PORT, (uint8_t*) zeroes_tx, y_raw, sizeof(y_raw), HAL_MAX_DELAY);

		HAL_SPI_Transmit(&ILI9341_TOUCH_SPI_PORT, (uint8_t*) cmd_read_x, sizeof(cmd_read_x), HAL_MAX_DELAY);
		uint8_t x_raw[2];
		HAL_SPI_TransmitReceive(&ILI9341_TOUCH_SPI_PORT, (uint8_t*) zeroes_tx, x_raw, sizeof(x_raw), HAL_MAX_DELAY);

		uint32_t mirrorX = ((((uint16_t) x_raw[0]) << 8) | (uint16_t) x_raw[1]);
		avg_x += (mirrorX >> 3) & 0xFFF;
		uint32_t mirrorY = ((((uint16_t) y_raw[0]) << 8) | (uint16_t) y_raw[1]);
		avg_y += (mirrorY >> 3) & 0xFFF;
	}

	ILI9341_TouchUnselect();

	if (nsamples < 16)
		return false;

	uint32_t raw_x = (avg_x / 16);
	if (raw_x < minRawX)
		raw_x = minRawX;
	if (raw_x > maxRawX)
		raw_x = maxRawX;

	uint32_t raw_y = (avg_y / 16);
	if (raw_y < minRawY)
		raw_y = minRawY;
	if (raw_y > maxRawY)
		raw_y = maxRawY;

	// Uncomment this line to calibrate touchscreen:
	// UART_Printf("raw_x = %d, raw_y = %d\r\n", x, y);

	*x = (raw_x - minRawX) * ILI9341_TOUCH_SCALE_X / (maxRawX - minRawX);
	*y = (raw_y - minRawY) * ILI9341_TOUCH_SCALE_Y / (maxRawY - minRawY);

	return true;
}

void figuringData(void) {
	uint32_t multiplicationFactorX, multiplicationFactorY;
	minX = minX / 2;
	minY = minY / 2;
	maxX = maxX / 2;
	maxY = maxY / 2;
	multiplicationFactorX = (maxX - minX) / 300;   // так как у нас отступ с обоих сторон 10 то рабочая область 300
	multiplicationFactorY = (maxY - minY) / 220;   // узнаем сколько единиц тача на 1 пиксель
	multiplicationFactorX = multiplicationFactorX * 10;  // так как нужно узнать сколько на 10 пикселей примерно отсчетов тача
	multiplicationFactorY = multiplicationFactorY * 10;
	minRawX = minX - multiplicationFactorX;
	maxRawX = maxX + multiplicationFactorX;
	minRawY = minY - multiplicationFactorY;
	maxRawY = maxY + multiplicationFactorY;
}

uint8_t calibTouch(uint8_t poz) {
	static const uint8_t cmd_read_x[] = { READ_X };
	static const uint8_t cmd_read_y[] = { READ_Y };
	static const uint8_t zeroes_tx[] = { 0x00, 0x00 };
	repit: while (!ILI9341_TouchPressed())
		ILI9341_TouchSelect();
	uint32_t avg_x = 0;
	uint32_t avg_y = 0;
	uint8_t nsamples = 0;
	for (uint8_t i = 0; i < 16; i++) {
		if (!ILI9341_TouchPressed())
			break;
		nsamples++;
		HAL_SPI_Transmit(&ILI9341_TOUCH_SPI_PORT, (uint8_t*) cmd_read_y, sizeof(cmd_read_y), HAL_MAX_DELAY);
		uint8_t y_raw[2];
		HAL_SPI_TransmitReceive(&ILI9341_TOUCH_SPI_PORT, (uint8_t*) zeroes_tx, y_raw, sizeof(y_raw), HAL_MAX_DELAY);

		HAL_SPI_Transmit(&ILI9341_TOUCH_SPI_PORT, (uint8_t*) cmd_read_x, sizeof(cmd_read_x), HAL_MAX_DELAY);
		uint8_t x_raw[2];
		HAL_SPI_TransmitReceive(&ILI9341_TOUCH_SPI_PORT, (uint8_t*) zeroes_tx, x_raw, sizeof(x_raw), HAL_MAX_DELAY);

		uint32_t mirrorX = ((((uint16_t) x_raw[0]) << 8) | (uint16_t) x_raw[1]);
		avg_x += (mirrorX >> 3) & 0xFFF;
		uint32_t mirrorY = ((((uint16_t) y_raw[0]) << 8) | (uint16_t) y_raw[1]);
		avg_y += (mirrorY >> 3) & 0xFFF;
	}
	ILI9341_TouchUnselect();
	if (nsamples < 16)
		goto repit;
	uint32_t raw_x = (avg_x / 16);
	uint32_t raw_y = (avg_y / 16);
	switch (poz) {
	case LEFTUP:
		minX = raw_x;
		minY = raw_y;
		buzzerSet(100);
		break;
	case RIGHTUP:
		maxX = raw_x;
		minY += raw_y;
		buzzerSet(100);
		break;
	case LEFTDOWN:
		minX += raw_x;
		maxY = raw_y;
		buzzerSet(100);
		break;
	case RIGHTDOWN:
		maxX += raw_x;
		maxY += raw_y;
		buzzerSet(100);
		figuringData();
		break;
	case CHECKCALIB:
		buzzerSet(100);
		if ((((raw_y - minRawY) * ILI9341_TOUCH_SCALE_Y / (maxRawY - minRawY)) < 125 && ((raw_y - minRawY) * ILI9341_TOUCH_SCALE_Y / (maxRawY - minRawY)) > 115) \
		&& (((raw_x - minRawX) * ILI9341_TOUCH_SCALE_X / (maxRawX - minRawX)) < 165 && ((raw_x - minRawX) * ILI9341_TOUCH_SCALE_X / (maxRawX - minRawX)) > 155)){
			writeDataToMemory (ADR_DATA_MIN_X, minRawX);
			writeDataToMemory (ADR_DATA_MAX_X, maxRawX);
			writeDataToMemory (ADR_DATA_MIN_Y, minRawY);
			writeDataToMemory (ADR_DATA_MAX_Y, maxRawY);
		} else {
			return false;
		}
		break;
	}
	return true;
}

//------------------------------ примечания --------------------------------------------//
