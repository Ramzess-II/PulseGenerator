#include "ili9341Lib.h"

//----------------------- переменные из этого файла ----------------------------------//

//------------------------------ функции ---------------------------------------------//
/**************************************************************************
 @brief     функция для отправки в SPI. + ожидание окончания передачи.
 @param    buff указатель на буфер отправки
 @param    buff_size размер буфера
 **************************************************************************/
void mySPISend(uint8_t *buff, uint16_t buff_size) {
	while (buff_size > 0) {
		SPI1->DR = *buff;
		while (!READ_BIT(SPI1->SR, SPI_SR_TXE))
			;
		buff++;
		buff_size--;
	}
	while (READ_BIT(SPI1->SR, SPI_SR_BSY))
		;
}

/**************************************************************************
 @brief     drive pin CS to GND
 **************************************************************************/
void ILI9341_Select() {
	CS_RESET;
	//HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, GPIO_PIN_RESET);
}

/**************************************************************************
 @brief     drive pin CS to UP
 **************************************************************************/
void ILI9341_Unselect() {
	CS_SET;
	//HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, GPIO_PIN_SET);
}

/**************************************************************************
 @brief     drive pin Reset
 **************************************************************************/
static void ILI9341_Reset() {
	HAL_GPIO_WritePin(ILI9341_RES_GPIO_Port, ILI9341_RES_Pin, GPIO_PIN_RESET);
	HAL_Delay(5);
	HAL_GPIO_WritePin(ILI9341_RES_GPIO_Port, ILI9341_RES_Pin, GPIO_PIN_SET);
}

/**************************************************************************
 @brief     write comand to display
 @param    cmd number comand
 **************************************************************************/
static void ILI9341_WriteCommand(uint8_t cmd) {
	DC_RESET;                      // данные или команда
	mySPISend(&cmd, 1);
}

static void ILI9341_WriteData(uint8_t *buff, size_t buff_size) {
	DC_SET;                        // данные или команда
	// split data in small chunks because HAL can't send more then 64K at once
	while (buff_size > 0) {
		uint16_t chunk_size = buff_size > 32768 ? 32768 : buff_size;
		mySPISend(buff, chunk_size);
		buff += chunk_size;
		buff_size -= chunk_size;
	}
}

static void ILI9341_SetAddressWindow(uint16_t x0, uint16_t y0, uint16_t x1,
		uint16_t y1) {
	// column address set
	ILI9341_WriteCommand(0x2A); // CASET
	{
		uint8_t data[] = { (x0 >> 8) & 0xFF, x0 & 0xFF, (x1 >> 8) & 0xFF, x1
				& 0xFF };
		ILI9341_WriteData(data, sizeof(data));
	}
	// row address set
	ILI9341_WriteCommand(0x2B); // RASET
	{
		uint8_t data[] = { (y0 >> 8) & 0xFF, y0 & 0xFF, (y1 >> 8) & 0xFF, y1
				& 0xFF };
		ILI9341_WriteData(data, sizeof(data));
	}
	// write to RAM
	ILI9341_WriteCommand(0x2C); // RAMWR
}

void ILI9341_Init() {
	HAL_GPIO_WritePin(Led_Display_GPIO_Port, Led_Display_Pin, GPIO_PIN_SET);
	ILI9341_Select();
	ILI9341_Reset();
	// command list is based on https://github.com/martnak/STM32-ILI9341
	ILI9341_WriteCommand(0x01); // SOFTWARE RESET
	HAL_Delay(1000);
	ILI9341_WriteCommand(0xCB); // POWER CONTROL A
	{
		uint8_t data[] = { 0x39, 0x2C, 0x00, 0x34, 0x02 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xCF); // POWER CONTROL B
	{
		uint8_t data[] = { 0x00, 0xC1, 0x30 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xE8); // DRIVER TIMING CONTROL A
	{
		uint8_t data[] = { 0x85, 0x00, 0x78 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xEA); // DRIVER TIMING CONTROL B
	{
		uint8_t data[] = { 0x00, 0x00 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xED);  // POWER ON SEQUENCE CONTROL
	{
		uint8_t data[] = { 0x64, 0x03, 0x12, 0x81 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xF7);  // PUMP RATIO CONTROL
	{
		uint8_t data[] = { 0x20 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xC0); // POWER CONTROL,VRH[5:0]
	{
		uint8_t data[] = { 0x23 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xC1); // POWER CONTROL,SAP[2:0];BT[3:0]
	{
		uint8_t data[] = { 0x10 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xC5); // VCM CONTROL
	{
		uint8_t data[] = { 0x3E, 0x28 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xC7);  // VCM CONTROL 2
	{
		uint8_t data[] = { 0x86 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0x36); // MEMORY ACCESS CONTROL
	{
		uint8_t data[] = { 0x48 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0x3A); // PIXEL FORMAT
	{
		uint8_t data[] = { 0x55 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xB1); // FRAME RATIO CONTROL, STANDARD RGB COLOR
	{
		uint8_t data[] = { 0x00, 0x18 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xB6); // DISPLAY FUNCTION CONTROL
	{
		uint8_t data[] = { 0x08, 0x82, 0x27 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xF2); // 3GAMMA FUNCTION DISABLE
	{
		uint8_t data[] = { 0x00 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0x26); // GAMMA CURVE SELECTED
	{
		uint8_t data[] = { 0x01 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xE0); // POSITIVE GAMMA CORRECTION
	{
		uint8_t data[] = { 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37,
				0x07, 0x10, 0x03, 0x0E, 0x09, 0x00 };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0xE1); // NEGATIVE GAMMA CORRECTION
	{
		uint8_t data[] = { 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48,
				0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_WriteCommand(0x11); // EXIT SLEEP
	HAL_Delay(120);
	ILI9341_WriteCommand(0x29); // TURN ON DISPLAY
	ILI9341_WriteCommand(0x36); // MADCTL
	{
		uint8_t data[] = { ILI9341_ROTATION };
		ILI9341_WriteData(data, sizeof(data));
	}
	ILI9341_Unselect();
}

void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
	if ((x >= ILI9341_WIDTH) || (y >= ILI9341_HEIGHT))
		return;
	ILI9341_Select();

	ILI9341_SetAddressWindow(x, y, x + 1, y + 1);
	uint8_t data[] = { color >> 8, color & 0xFF };
	ILI9341_WriteData(data, sizeof(data));

	ILI9341_Unselect();
}

void ILI9341_FillRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		uint16_t color) {
	// clipping
	if ((x >= ILI9341_WIDTH) || (y >= ILI9341_HEIGHT))
		return;
	if ((x + w - 1) >= ILI9341_WIDTH)
		w = ILI9341_WIDTH - x;
	if ((y + h - 1) >= ILI9341_HEIGHT)
		h = ILI9341_HEIGHT - y;

	ILI9341_Select();
	ILI9341_SetAddressWindow(x, y, x + w - 1, y + h - 1);

	uint8_t data[] = { color >> 8, color & 0xFF };
	HAL_GPIO_WritePin(ILI9341_DC_GPIO_Port, ILI9341_DC_Pin, GPIO_PIN_SET);
	for (y = h; y > 0; y--) {
		for (x = w; x > 0; x--) {
			mySPISend(data, sizeof(data));
		}
	}

	ILI9341_Unselect();
}

void ILI9341_FillScreen(uint16_t color) {
	ILI9341_FillRectangle(0, 0, ILI9341_WIDTH, ILI9341_HEIGHT, color);
}

static void ILI9341_WriteMyChar(uint16_t x, uint16_t y, char ch, uint16_t color,
		uint16_t bgcolor) {
	uint16_t i, j, value;
	uint32_t devider, b;

	ILI9341_SetAddressWindow(x, y,
			x + Font24x36_array[(ch - 32)].image->width - 1,
			y + Font24x36_array[(ch - 32)].image->height - 1);
	value = 1;
	devider = 0x80;
	if ((Font24x36_array[(ch - 32)].image->width) > 8) {
		value = 2;
		devider = 0x8000;
	}
	if ((Font24x36_array[(ch - 32)].image->width) > 16) {
		value = 3;
		devider = 0x800000;
	}
	if ((Font24x36_array[(ch - 32)].image->width) > 24) {
		value = 4;
		devider = 0x80000000;
	}
	for (i = 0; i < (Font24x36_array[(ch - 32)].image->height) * value; i +=
			value) {
		b = Font24x36_array[(ch - 32)].image->data[i];
		if (value >= 2) {
			b = b << 8;
			b |= Font24x36_array[(ch - 32)].image->data[i + 1];
		}
		if (value >= 3) {
			b = b << 8;
			b |= Font24x36_array[(ch - 32)].image->data[i + 2];
		}
		if (value >= 4) {
			b = b << 8;
			b |= Font24x36_array[(ch - 32)].image->data[i + 3];
		}
		for (j = 0; j < Font24x36_array[(ch - 32)].image->width; j++) {
			if ((b << j) & devider) {
				uint8_t data[] = { color >> 8, color & 0xFF };
				ILI9341_WriteData(data, sizeof(data));
			} else {
				uint8_t data[] = { bgcolor >> 8, bgcolor & 0xFF };
				ILI9341_WriteData(data, sizeof(data));
			}
		}
	}
}

void ILI9341_WriteMyString(uint16_t x, uint16_t y, const char *str,
		uint16_t color, uint16_t bgcolor) {
	ILI9341_Select();
	while (*str) {
		if (x + Font24x36_array[(*str - 32)].image->width >= ILI9341_WIDTH) {
			x = 0;
			y += Font24x36_array[(*str - 32)].image->height;
			if (y + Font24x36_array[(*str - 32)].image->height >= ILI9341_HEIGHT) {
				break;
			}
			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}
		ILI9341_WriteMyChar(x, y, *str, color, bgcolor);
		x += Font24x36_array[(*str - 32)].image->width;
		str++;
	}
	ILI9341_Unselect();
}

static void ILI9341_WriteChar(uint16_t x, uint16_t y, char ch, FontDef font,
		uint16_t color, uint16_t bgcolor) {
	uint32_t i, b, j;
	ILI9341_SetAddressWindow(x, y, x + font.width - 1, y + font.height - 1);
	for (i = 0; i < font.height; i++) {
		b = font.data[(ch - 32) * font.height + i];
		for (j = 0; j < font.width; j++) {
			if ((b << j) & 0x8000) {
				uint8_t data[] = { color >> 8, color & 0xFF };
				ILI9341_WriteData(data, sizeof(data));
			} else {
				uint8_t data[] = { bgcolor >> 8, bgcolor & 0xFF };
				ILI9341_WriteData(data, sizeof(data));
			}
		}
	}
}

void ILI9341_WriteString(uint16_t x, uint16_t y, const char *str, FontDef font,
		uint16_t color, uint16_t bgcolor) {
	ILI9341_Select();

	while (*str) {
		if (x + font.width >= ILI9341_WIDTH) {
			x = 0;
			y += font.height;
			if (y + font.height >= ILI9341_HEIGHT) {
				break;
			}
			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}
		ILI9341_WriteChar(x, y, *str, font, color, bgcolor);
		x += font.width;
		str++;
	}

	ILI9341_Unselect();
}

void ILI9341_DeleteString(uint16_t x, uint16_t y, const char *str, FontDef font, uint16_t color, uint16_t bgcolor) {
	ILI9341_FillRectangle (x,y, strlen(str) * font.width, font.height, bgcolor);
}

void ILI9341_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h,
		const uint16_t *data) {
	if ((x >= ILI9341_WIDTH) || (y >= ILI9341_HEIGHT))
		return;
	if ((x + w - 1) >= ILI9341_WIDTH)
		return;
	if ((y + h - 1) >= ILI9341_HEIGHT)
		return;

	ILI9341_Select();
	ILI9341_SetAddressWindow(x, y, x + w - 1, y + h - 1);
	ILI9341_WriteData((uint8_t*) data, sizeof(uint16_t) * w * h);
	ILI9341_Unselect();
}

void ILI9341_DrawMonochromeImage(uint16_t x, uint16_t y, uint16_t color,
		uint16_t bgcolor, tImage image) {
	uint16_t b, devider, siz, count;
	if ((x >= ILI9341_WIDTH) || (y >= ILI9341_HEIGHT))
		return;
	devider = wholeDevider(image.height, 8);
	siz = devider * image.width;
	ILI9341_Select();
	ILI9341_SetAddressWindow(x, y, x + image.width - 1, y + image.height - 1);

	for (int i = 0; i < siz; i += devider) {
		count = image.width;
		for (int u = 0; u < devider; u++) {
			b = image.data[i + u];
			for (int j = 0; j < 8; j++) {
				if (count == 0) break;
				count --;
				if ((b << j) & 0x80) {
					uint8_t data[] = { color >> 8, color & 0xFF };
					ILI9341_WriteData(data, sizeof(data));
				} else {
					uint8_t data[] = { bgcolor >> 8, bgcolor & 0xFF };
					ILI9341_WriteData(data, sizeof(data));
				}
			}
		}
	}
	ILI9341_Unselect();
}

void ILI9341_InvertColors(bool invert) {
	ILI9341_Select();
	ILI9341_WriteCommand(invert ? 0x21 /* INVON */: 0x20 /* INVOFF */);
	ILI9341_Unselect();
}

/**************************************************************************
 @brief    Write a line.  Bresenham's algorithm - thx wikpedia
 @param    x0  Start point x coordinate
 @param    y0  Start point y coordinate
 @param    x1  End point x coordinate
 @param    y1  End point y coordinate
 @param    color 16-bit 5-6-5 Color to draw with
 **************************************************************************/
void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
	int16_t steep = myAbs(y1 - y0) > myAbs(x1 - x0);
	if (steep) {
		swap_int16_t(&x0, &y0);
		swap_int16_t(&x1, &y1);
	}

	if (x0 > x1) {
		swap_int16_t(&x0, &x1);
		swap_int16_t(&y0, &y1);
	}

	int16_t dx, dy;
	dx = x1 - x0;
	dy = myAbs(y1 - y0);

	int16_t err = dx / 2;
	int16_t ystep;

	if (y0 < y1) {
		ystep = 1;
	} else {
		ystep = -1;
	}
	ILI9341_Select();
	for (; x0 <= x1; x0++) {
		if (steep) {
			ILI9341_DrawPixel(y0, x0, color);
		} else {
			ILI9341_DrawPixel(x0, y0, color);
		}
		err -= dy;
		if (err < 0) {
			y0 += ystep;
			err += dx;
		}
	}
	ILI9341_Unselect();
}

/**************************************************************************
 @brief    Write a perfectly vertical line, overwrite in subclasses ifstartWrite is defined!
 @param    x   Top-most x coordinate
 @param    y   Top-most y coordinate
 @param    h   Height in pixels
 @param    color 16-bit 5-6-5 Color to fill with
 **************************************************************************/
void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
	ILI9341_Select();
	ILI9341_FillRectangle(x, y, 1, h, color);
	//writeLine(x, y, x, y + h - 1, color);
	ILI9341_Unselect();
}

/**************************************************************************
 @brief    Write a perfectly horizontal line, overwrite in subclasses ifstartWrite is defined!
 @param    x   Left-most x coordinate
 @param    y   Left-most y coordinate
 @param    w   Width in pixels
 @param    color 16-bit 5-6-5 Color to fill with
 **************************************************************************/
void writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
	ILI9341_Select();
	ILI9341_FillRectangle(x, y, w, 1, color);
	//writeLine(x, y, x + w - 1, y, color);
	ILI9341_Unselect();
}

/**************************************************************************
 @brief   Draw a rectangle with no fill color
 @param    x   Top left corner x coordinate
 @param    y   Top left corner y coordinate
 @param    w   Width in pixels
 @param    h   Height in pixels
 @param    color 16-bit 5-6-5 Color to draw with
 **************************************************************************/
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
	writeFastHLine(x, y, w, color);
	writeFastHLine(x, y + h - 1, w, color);
	writeFastVLine(x, y, h, color);
	writeFastVLine(x + w - 1, y, h, color);
}

/**************************************************************************
 @brief    Quarter-circle drawer, used to do circles and roundrects
 @param    x0   Center-point x coordinate
 @param    y0   Center-point y coordinate
 @param    r   Radius of circle
 @param    cornername  Mask bit #1 or bit #2 to indicate which quarters of the circle we're doing
 @param    color 16-bit 5-6-5 Color to draw with
 **************************************************************************/
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
		uint16_t color) {
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;
		if (cornername & 0x4) {
			ILI9341_DrawPixel(x0 + x, y0 + y, color);
			ILI9341_DrawPixel(x0 + y, y0 + x, color);
		}
		if (cornername & 0x2) {
			ILI9341_DrawPixel(x0 + x, y0 - y, color);
			ILI9341_DrawPixel(x0 + y, y0 - x, color);
		}
		if (cornername & 0x8) {
			ILI9341_DrawPixel(x0 - y, y0 + x, color);
			ILI9341_DrawPixel(x0 - x, y0 + y, color);
		}
		if (cornername & 0x1) {
			ILI9341_DrawPixel(x0 - y, y0 - x, color);
			ILI9341_DrawPixel(x0 - x, y0 - y, color);
		}
	}
}

/**************************************************************************
 @brief  Quarter-circle drawer with fill, used for circles and roundrects
 @param  x0       Center-point x coordinate
 @param  y0       Center-point y coordinate
 @param  r        Radius of circle
 @param  corners  Mask bits indicating which quarters we're doing
 @param  delta    Offset from center-point, used for round-rects
 @param  color    16-bit 5-6-5 Color to fill with
 **************************************************************************/
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t corners,
		int16_t delta, uint16_t color) {
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;
	int16_t px = x;
	int16_t py = y;

	delta++; // Avoid some +1's in the loop

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;
		// These checks avoid double-drawing certain lines, important
		// for the SSD1306 library which has an INVERT drawing mode.
		if (x < (y + 1)) {
			if (corners & 1)
				writeFastVLine(x0 + x, y0 - y, 2 * y + delta, color);
			if (corners & 2)
				writeFastVLine(x0 - x, y0 - y, 2 * y + delta, color);
		}
		if (y != py) {
			if (corners & 1)
				writeFastVLine(x0 + py, y0 - px, 2 * px + delta, color);
			if (corners & 2)
				writeFastVLine(x0 - py, y0 - px, 2 * px + delta, color);
			py = y;
		}
		px = x;
	}
}

/**************************************************************************
 @brief   Draw a rounded rectangle with fill color
 @param    x   Top left corner x coordinate
 @param    y   Top left corner y coordinate
 @param    w   Width in pixels
 @param    h   Height in pixels
 @param    r   Radius of corner rounding
 @param    color 16-bit 5-6-5 Color to draw/fill with
 **************************************************************************/
void drawRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r,
		uint16_t color) {
	int16_t max_radius = 0;
	if (w < h)
		max_radius = w / 2;
	else
		max_radius = h / 2;              // 1/2 minor axis
	if (r > max_radius)
		r = max_radius;
// smarter version
	ILI9341_Select();
	writeFastHLine(x + r, y, w - 2 * r, color);         // Top
	writeFastHLine(x + r, y + h - 1, w - 2 * r, color); // Bottom
	writeFastVLine(x, y + r, h - 2 * r, color);         // Left
	writeFastVLine(x + w - 1, y + r, h - 2 * r, color); // Right
// draw four corners
	drawCircleHelper(x + r, y + r, r, 1, color);
	drawCircleHelper(x + w - r - 1, y + r, r, 2, color);
	drawCircleHelper(x + w - r - 1, y + h - r - 1, r, 4, color);
	drawCircleHelper(x + r, y + h - r - 1, r, 8, color);
	ILI9341_Unselect();
}

void drawSomePixelRoundRect(int16_t x, int16_t y, int16_t w, int16_t h,
		int16_t r, int16_t countPixel, uint16_t color) {
	if (countPixel < 1)
		return;
	for (int i = 0; i < countPixel; i++) {
		if (i == 0) {
			drawRoundRect(x, y, w, h, r, color);
			continue;
		}
		drawRoundRect(x + i, y + i, w - i * 2, h - i * 2, r, color);
	}
}

/**************************************************************************
 @brief    Fill a rectangle completely with one color. Update in subclasses if
 desired!
 @param    x   Top left corner x coordinate
 @param    y   Top left corner y coordinate
 @param    w   Width in pixels
 @param    h   Height in pixels
 @param    color 16-bit 5-6-5 Color to fill with
 **************************************************************************/
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
	for (int16_t i = x; i < x + w; i++) {
		writeFastVLine(i, y, h, color);
	}
}

/**************************************************************************
 @brief   Draw a rounded rectangle with fill color
 @param    x   Top left corner x coordinate
 @param    y   Top left corner y coordinate
 @param    w   Width in pixels
 @param    h   Height in pixels
 @param    r   Radius of corner rounding
 @param    color 16-bit 5-6-5 Color to draw/fill with
 **************************************************************************/
void fillRoundRect(int16_t x, int16_t y, int16_t w, int16_t h, int16_t r,
		uint16_t color) {
	int16_t max_radius = ((w < h) ? w : h) / 2; // 1/2 minor axis
	if (r > max_radius)
		r = max_radius;
	ILI9341_Select();
// smarter version
	fillRect(x + r, y, w - 2 * r, h, color);
// draw four corners
	fillCircleHelper(x + w - r - 1, y + r, r, 1, h - 2 * r - 1, color);
	fillCircleHelper(x + r, y + r, r, 2, h - 2 * r - 1, color);
	ILI9341_Unselect();
}

/**************************************************************************
 @brief    Draw a circle outline
 @param    x0   Center-point x coordinate
 @param    y0   Center-point y coordinate
 @param    r   Radius of circle
 @param    color 16-bit 5-6-5 Color to draw with
 **************************************************************************/
void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
	int16_t f = 1 - r;
	int16_t ddF_x = 1;
	int16_t ddF_y = -2 * r;
	int16_t x = 0;
	int16_t y = r;

	ILI9341_Select();
	ILI9341_DrawPixel(x0, y0 + r, color);
	ILI9341_DrawPixel(x0, y0 - r, color);
	ILI9341_DrawPixel(x0 + r, y0, color);
	ILI9341_DrawPixel(x0 - r, y0, color);

	while (x < y) {
		if (f >= 0) {
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x;

		ILI9341_DrawPixel(x0 + x, y0 + y, color);
		ILI9341_DrawPixel(x0 - x, y0 + y, color);
		ILI9341_DrawPixel(x0 + x, y0 - y, color);
		ILI9341_DrawPixel(x0 - x, y0 - y, color);
		ILI9341_DrawPixel(x0 + y, y0 + x, color);
		ILI9341_DrawPixel(x0 - y, y0 + x, color);
		ILI9341_DrawPixel(x0 + y, y0 - x, color);
		ILI9341_DrawPixel(x0 - y, y0 - x, color);
	}
	ILI9341_Unselect();
}

//------------------------------ примечания --------------------------------------------//

