#include "monochromImg.h"


static const uint8_t image_data_ArrowUp[350] = {
		   // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙
		    // ∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙
		    // ∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙
		    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
		    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙████████████∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
		    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙████████████∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
		    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙██████████████∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
		    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙████████████████∙∙∙∙∙∙∙∙∙∙∙████∙∙
		    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙████████████████∙∙∙∙∙∙∙∙∙∙∙████∙∙
		    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙∙∙∙∙∙████████████████████∙∙∙∙∙∙∙∙∙∙███∙∙
		    // ∙████∙∙∙∙∙∙∙∙∙██████████████████████∙∙∙∙∙∙∙∙∙████∙
		    // ∙███∙∙∙∙∙∙∙∙∙∙██████████████████████∙∙∙∙∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙∙∙∙████████████████████████∙∙∙∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙∙∙██████████████████████████∙∙∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙∙∙██████████████████████████∙∙∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙
		    // ∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙
		    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
		    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
		    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
		    // ∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
		    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
		    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
		    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
		    // ∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙
		    // ∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙
		    // ∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙██████████████████████████∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00,
		    0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00,
		    0x00, 0x0f, 0xf8, 0x07, 0xfc, 0x00, 0x00,
		    0x00, 0x1f, 0xc0, 0x00, 0xff, 0x00, 0x00,
		    0x00, 0x7f, 0x00, 0x00, 0x1f, 0x80, 0x00,
		    0x00, 0xfc, 0x00, 0xc0, 0x0f, 0xc0, 0x00,
		    0x01, 0xf0, 0x01, 0xe0, 0x03, 0xe0, 0x00,
		    0x03, 0xe0, 0x03, 0xf0, 0x01, 0xf0, 0x00,
		    0x03, 0xc0, 0x03, 0xf0, 0x00, 0xf8, 0x00,
		    0x07, 0x80, 0x07, 0xf8, 0x00, 0x78, 0x00,
		    0x0f, 0x00, 0x0f, 0xfc, 0x00, 0x3c, 0x00,
		    0x0f, 0x00, 0x1f, 0xfe, 0x00, 0x3c, 0x00,
		    0x1e, 0x00, 0x1f, 0xfe, 0x00, 0x1e, 0x00,
		    0x1e, 0x00, 0x3f, 0xff, 0x00, 0x1e, 0x00,
		    0x3c, 0x00, 0x7f, 0xff, 0x80, 0x0f, 0x00,
		    0x3c, 0x00, 0x7f, 0xff, 0x80, 0x0f, 0x00,
		    0x38, 0x00, 0xff, 0xff, 0xc0, 0x07, 0x00,
		    0x38, 0x01, 0xff, 0xff, 0xe0, 0x07, 0x00,
		    0x78, 0x03, 0xff, 0xff, 0xf0, 0x07, 0x80,
		    0x70, 0x03, 0xff, 0xff, 0xf0, 0x03, 0x80,
		    0x70, 0x07, 0xff, 0xff, 0xf8, 0x03, 0x80,
		    0x70, 0x0f, 0xff, 0xff, 0xfc, 0x03, 0x80,
		    0x70, 0x0f, 0xff, 0xff, 0xfc, 0x03, 0x80,
		    0x70, 0x00, 0x0f, 0xfc, 0x00, 0x03, 0x80,
		    0x70, 0x00, 0x0f, 0xfc, 0x00, 0x03, 0x80,
		    0x70, 0x00, 0x0f, 0xfc, 0x00, 0x03, 0x80,
		    0x70, 0x00, 0x0f, 0xfc, 0x00, 0x03, 0x80,
		    0x78, 0x00, 0x0f, 0xfc, 0x00, 0x07, 0x80,
		    0x38, 0x00, 0x0f, 0xfc, 0x00, 0x07, 0x00,
		    0x38, 0x00, 0x0f, 0xfc, 0x00, 0x07, 0x00,
		    0x3c, 0x00, 0x0f, 0xfc, 0x00, 0x0f, 0x00,
		    0x3c, 0x00, 0x0f, 0xfc, 0x00, 0x0f, 0x00,
		    0x1c, 0x00, 0x0f, 0xfc, 0x00, 0x1e, 0x00,
		    0x1e, 0x00, 0x0f, 0xfc, 0x00, 0x1e, 0x00,
		    0x0f, 0x00, 0x0f, 0xfc, 0x00, 0x3c, 0x00,
		    0x0f, 0x00, 0x0f, 0xfc, 0x00, 0x3c, 0x00,
		    0x07, 0x80, 0x0f, 0xfc, 0x00, 0x78, 0x00,
		    0x07, 0xc0, 0x0f, 0xfc, 0x00, 0xf8, 0x00,
		    0x03, 0xe0, 0x0f, 0xfc, 0x01, 0xf0, 0x00,
		    0x01, 0xf0, 0x0f, 0xfc, 0x03, 0xe0, 0x00,
		    0x00, 0xfc, 0x07, 0xf8, 0x0f, 0xc0, 0x00,
		    0x00, 0x7e, 0x00, 0x00, 0x3f, 0x80, 0x00,
		    0x00, 0x3f, 0x80, 0x00, 0xff, 0x00, 0x00,
		    0x00, 0x0f, 0xff, 0xff, 0xfc, 0x00, 0x00,
		    0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00,
		    0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00,
		    0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage ArrowUp = { image_data_ArrowUp, 50, 50,
    8 };

static const uint8_t image_data_plus[350] = {
		  // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙
		    // ∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙
		    // ∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙
		    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
		    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
		    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
		    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
		    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
		    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
		    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
		    // ∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙
		    // ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙██████████████████████████████∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙████████████████████████████████∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙████████████████████████████████∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙████████████████████████████████∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙████████████████████████████████∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙██████████████████████████████∙∙∙∙∙∙███∙
		    // ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙
		    // ∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙
		    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
		    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
		    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
		    // ∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
		    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
		    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
		    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
		    // ∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙
		    // ∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙
		    // ∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00,
		    0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00,
		    0x00, 0x0f, 0xf8, 0x07, 0xfc, 0x00, 0x00,
		    0x00, 0x1f, 0xc0, 0x00, 0xff, 0x00, 0x00,
		    0x00, 0x7f, 0x00, 0x00, 0x1f, 0x80, 0x00,
		    0x00, 0xfc, 0x00, 0x00, 0x0f, 0xc0, 0x00,
		    0x01, 0xf0, 0x00, 0x00, 0x03, 0xe0, 0x00,
		    0x03, 0xe0, 0x01, 0xe0, 0x01, 0xf0, 0x00,
		    0x03, 0xc0, 0x03, 0xf0, 0x00, 0xf8, 0x00,
		    0x07, 0x80, 0x03, 0xf0, 0x00, 0x78, 0x00,
		    0x0f, 0x00, 0x03, 0xf0, 0x00, 0x3c, 0x00,
		    0x0f, 0x00, 0x03, 0xf0, 0x00, 0x3c, 0x00,
		    0x1e, 0x00, 0x03, 0xf0, 0x00, 0x1e, 0x00,
		    0x1e, 0x00, 0x03, 0xf0, 0x00, 0x1e, 0x00,
		    0x3c, 0x00, 0x03, 0xf0, 0x00, 0x0f, 0x00,
		    0x3c, 0x00, 0x03, 0xf0, 0x00, 0x0f, 0x00,
		    0x38, 0x00, 0x03, 0xf0, 0x00, 0x07, 0x00,
		    0x38, 0x00, 0x03, 0xf0, 0x00, 0x07, 0x00,
		    0x78, 0x00, 0x03, 0xf0, 0x00, 0x07, 0x80,
		    0x70, 0x00, 0x03, 0xf0, 0x00, 0x03, 0x80,
		    0x70, 0x3f, 0xff, 0xff, 0xff, 0x03, 0x80,
		    0x70, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x80,
		    0x70, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x80,
		    0x70, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x80,
		    0x70, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x80,
		    0x70, 0x3f, 0xff, 0xff, 0xff, 0x03, 0x80,
		    0x70, 0x00, 0x03, 0xf0, 0x00, 0x03, 0x80,
		    0x78, 0x00, 0x03, 0xf0, 0x00, 0x07, 0x80,
		    0x38, 0x00, 0x03, 0xf0, 0x00, 0x07, 0x00,
		    0x38, 0x00, 0x03, 0xf0, 0x00, 0x07, 0x00,
		    0x3c, 0x00, 0x03, 0xf0, 0x00, 0x0f, 0x00,
		    0x3c, 0x00, 0x03, 0xf0, 0x00, 0x0f, 0x00,
		    0x1c, 0x00, 0x03, 0xf0, 0x00, 0x1e, 0x00,
		    0x1e, 0x00, 0x03, 0xf0, 0x00, 0x1e, 0x00,
		    0x0f, 0x00, 0x03, 0xf0, 0x00, 0x3c, 0x00,
		    0x0f, 0x00, 0x03, 0xf0, 0x00, 0x3c, 0x00,
		    0x07, 0x80, 0x03, 0xf0, 0x00, 0x78, 0x00,
		    0x07, 0xc0, 0x03, 0xf0, 0x00, 0xf8, 0x00,
		    0x03, 0xe0, 0x01, 0xe0, 0x01, 0xf0, 0x00,
		    0x01, 0xf0, 0x00, 0x00, 0x03, 0xe0, 0x00,
		    0x00, 0xfc, 0x00, 0x00, 0x0f, 0xc0, 0x00,
		    0x00, 0x7f, 0x00, 0x00, 0x3f, 0x80, 0x00,
		    0x00, 0x3f, 0xc0, 0x00, 0xff, 0x00, 0x00,
		    0x00, 0x0f, 0xf8, 0x07, 0xfc, 0x00, 0x00,
		    0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00,
		    0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00,
		    0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage plus = { image_data_plus, 50, 50,
    8 };

static const uint8_t image_data_minus[350] = {
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙
    // ∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙
    // ∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙
    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙
    // ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙
    // ∙███∙∙∙∙∙∙██████████████████████████████∙∙∙∙∙∙███∙
    // ∙███∙∙∙∙∙████████████████████████████████∙∙∙∙∙███∙
    // ∙███∙∙∙∙∙████████████████████████████████∙∙∙∙∙███∙
    // ∙███∙∙∙∙∙████████████████████████████████∙∙∙∙∙███∙
    // ∙███∙∙∙∙∙████████████████████████████████∙∙∙∙∙███∙
    // ∙███∙∙∙∙∙∙██████████████████████████████∙∙∙∙∙∙███∙
    // ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙
    // ∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙
    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
    // ∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
    // ∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
    // ∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙
    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
    // ∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
    // ∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙
    // ∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙
    // ∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00,
    0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00,
    0x00, 0x0f, 0xf8, 0x07, 0xfc, 0x00, 0x00,
    0x00, 0x1f, 0xc0, 0x00, 0xff, 0x00, 0x00,
    0x00, 0x7f, 0x00, 0x00, 0x1f, 0x80, 0x00,
    0x00, 0xfc, 0x00, 0x00, 0x0f, 0xc0, 0x00,
    0x01, 0xf0, 0x00, 0x00, 0x03, 0xe0, 0x00,
    0x03, 0xe0, 0x00, 0x00, 0x01, 0xf0, 0x00,
    0x03, 0xc0, 0x00, 0x00, 0x00, 0xf8, 0x00,
    0x07, 0x80, 0x00, 0x00, 0x00, 0x78, 0x00,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00,
    0x1e, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00,
    0x1e, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00,
    0x3c, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,
    0x3c, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,
    0x38, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
    0x38, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
    0x78, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80,
    0x70, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80,
    0x70, 0x3f, 0xff, 0xff, 0xff, 0x03, 0x80,
    0x70, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x80,
    0x70, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x80,
    0x70, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x80,
    0x70, 0x7f, 0xff, 0xff, 0xff, 0x83, 0x80,
    0x70, 0x3f, 0xff, 0xff, 0xff, 0x03, 0x80,
    0x70, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80,
    0x78, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80,
    0x38, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
    0x38, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00,
    0x3c, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,
    0x3c, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00,
    0x1c, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00,
    0x1e, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00,
    0x07, 0x80, 0x00, 0x00, 0x00, 0x78, 0x00,
    0x07, 0xc0, 0x00, 0x00, 0x00, 0xf8, 0x00,
    0x03, 0xe0, 0x00, 0x00, 0x01, 0xf0, 0x00,
    0x01, 0xf0, 0x00, 0x00, 0x03, 0xe0, 0x00,
    0x00, 0xfc, 0x00, 0x00, 0x0f, 0xc0, 0x00,
    0x00, 0x7f, 0x00, 0x00, 0x3f, 0x80, 0x00,
    0x00, 0x3f, 0xc0, 0x00, 0xff, 0x00, 0x00,
    0x00, 0x0f, 0xf8, 0x07, 0xfc, 0x00, 0x00,
    0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage minus = { image_data_minus, 50, 50,
    8 };


static const uint8_t image_data_pnp[350] = {
	    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		// ∙████████████████████████████████████████████████∙
		// ∙████████████████████████████████████████████████∙
		// ∙████████████████████████████████████████████████∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████████████∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙██∙∙████████∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙███∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙████∙∙∙∙∙████∙∙∙∙█████∙∙∙∙∙∙███∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙███∙∙∙∙∙∙████∙∙∙██████∙∙∙∙∙∙███∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙███∙∙∙∙∙∙∙████∙∙∙██████∙∙∙∙∙∙∙███∙∙∙∙███∙
		// ∙███∙∙∙∙∙███∙∙∙∙∙∙∙████∙∙████████∙∙∙∙∙∙∙██∙∙∙∙███∙
		// ∙███∙∙∙∙███∙∙∙∙∙∙∙∙████∙∙████████∙∙∙∙∙∙∙███∙∙∙███∙
		// ∙███∙∙∙∙███∙∙∙∙∙∙∙∙████∙█████∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙███∙
		// ∙███∙∙∙∙██∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙███∙
		// ∙███∙∙∙∙██∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙███∙
		// ∙███∙∙∙∙██∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙███∙
		// ∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙███∙
		// ∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙███∙
		// ∙██████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙███∙
		// ∙███∙∙∙███∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙███∙
		// ∙███∙∙∙∙██∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙███∙
		// ∙███∙∙∙∙██∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙███∙
		// ∙███∙∙∙∙██∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙███∙
		// ∙███∙∙∙∙███∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙███∙
		// ∙███∙∙∙∙∙██∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙███∙
		// ∙███∙∙∙∙∙███∙∙∙∙∙∙∙████∙█████∙∙∙∙∙∙∙∙∙∙███∙∙∙∙███∙
		// ∙███∙∙∙∙∙████∙∙∙∙∙∙████∙∙∙█████∙∙∙∙∙∙∙∙███∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙███∙∙∙∙∙∙████∙∙∙∙█████∙∙∙∙∙∙███∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙███∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙████∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙███████████████████∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████████████∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████∙∙∙██∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙███∙
		// ∙████████████████████████████████████████████████∙
		// ∙████████████████████████████████████████████████∙
		// ∙████████████████████████████████████████████████∙
		// ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x07, 0xfc, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x1f, 0xff, 0xf0, 0x00, 0x00,
		    0x00, 0x00, 0x7f, 0xff, 0xf0, 0x00, 0x00,
		    0x00, 0x01, 0xfc, 0x07, 0xf0, 0x00, 0x00,
		    0x00, 0x03, 0xf0, 0x00, 0xf8, 0x00, 0x00,
		    0x00, 0x07, 0xc0, 0x00, 0xfc, 0x00, 0x00,
		    0x00, 0x0f, 0x00, 0x19, 0xfe, 0x00, 0x00,
		    0x00, 0x1e, 0x00, 0x1f, 0x87, 0x00, 0x00,
		    0x00, 0x3c, 0x1e, 0x1f, 0x07, 0x80, 0x00,
		    0x00, 0x38, 0x1e, 0x3f, 0x03, 0x80, 0x00,
		    0x00, 0x70, 0x1e, 0x3f, 0x01, 0xc0, 0x00,
		    0x00, 0x70, 0x1e, 0x7f, 0x81, 0xe0, 0x00,
		    0x00, 0xe0, 0x1e, 0x7f, 0x80, 0xe0, 0x00,
		    0x00, 0xe0, 0x1e, 0xf8, 0x00, 0xe0, 0x00,
		    0x00, 0xe0, 0x1f, 0xe0, 0x00, 0x70, 0x00,
		    0x00, 0xc0, 0x1f, 0x80, 0x00, 0x70, 0x00,
		    0x01, 0xc0, 0x1f, 0x00, 0x00, 0x70, 0x00,
		    0x3f, 0xff, 0xfe, 0x00, 0x00, 0x70, 0x00,
		    0x3f, 0xff, 0xfe, 0x00, 0x00, 0x70, 0x00,
		    0x3f, 0xff, 0xfe, 0x00, 0x00, 0x70, 0x00,
		    0x01, 0xc0, 0x1e, 0x00, 0x00, 0x70, 0x00,
		    0x01, 0xc0, 0x1e, 0x00, 0x00, 0x70, 0x00,
		    0x00, 0xc0, 0x1f, 0x00, 0x00, 0x70, 0x00,
		    0x00, 0xe0, 0x1f, 0x80, 0x00, 0x70, 0x00,
		    0x00, 0xe0, 0x1f, 0xc0, 0x00, 0xe0, 0x00,
		    0x00, 0xf0, 0x1f, 0xf0, 0x00, 0xe0, 0x00,
		    0x00, 0x70, 0x1e, 0xf8, 0x01, 0xc0, 0x00,
		    0x00, 0x78, 0x1e, 0x7e, 0x03, 0xc0, 0x00,
		    0x00, 0x38, 0x1e, 0x1f, 0x03, 0x80, 0x00,
		    0x00, 0x1c, 0x00, 0x07, 0xc7, 0x80, 0x00,
		    0x00, 0x1e, 0x00, 0x03, 0xff, 0x00, 0x00,
		    0x00, 0x0f, 0x80, 0x00, 0xfe, 0x00, 0x00,
		    0x00, 0x07, 0xe0, 0x00, 0xfc, 0x00, 0x00,
		    0x00, 0x03, 0xf8, 0x01, 0xf8, 0x00, 0x00,
		    0x00, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00,
		    0x00, 0x00, 0x7f, 0xff, 0xf0, 0x00, 0x00,
		    0x00, 0x00, 0x0f, 0xfe, 0xf0, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage pnp = { image_data_pnp, 50, 50,
    8 };

static const uint8_t image_data_npn[350] = {
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████████████████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙████∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙████∙∙∙██████∙∙∙∙∙████∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙████∙∙██████∙∙∙∙∙∙∙████∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙████∙█████∙∙∙∙∙∙∙∙∙∙████∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙
    // ∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙
    // ∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙
    // ∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙████████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙████████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙████████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙
    // ∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙█∙∙∙∙∙∙∙∙∙███∙∙∙
    // ∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙██████████∙██∙∙∙∙∙∙∙∙∙███∙∙∙
    // ∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙████∙█████████∙∙∙∙∙∙∙∙███∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙████∙∙∙███████∙∙∙∙∙∙∙███∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙████∙∙∙∙███████∙∙∙∙∙∙███∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙████∙∙∙████████∙∙∙∙∙████∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙████∙∙∙█████████∙∙∙████∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙████∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙∙∙∙█████████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████████████████∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████████∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7e, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xff, 0xe7, 0x00, 0x00,
    0x00, 0x00, 0x1f, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x7f, 0x81, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xfc, 0x00, 0x3f, 0x00, 0x00,
    0x00, 0x01, 0xf0, 0x00, 0x1f, 0xc0, 0x00,
    0x00, 0x03, 0xc0, 0x00, 0x7f, 0xe0, 0x00,
    0x00, 0x07, 0x80, 0x01, 0xf9, 0xe0, 0x00,
    0x00, 0x0f, 0x03, 0xc7, 0xe0, 0xf0, 0x00,
    0x00, 0x1e, 0x03, 0xcf, 0xc0, 0x78, 0x00,
    0x00, 0x1c, 0x03, 0xdf, 0x00, 0x3c, 0x00,
    0x00, 0x38, 0x03, 0xfc, 0x00, 0x1c, 0x00,
    0x00, 0x38, 0x03, 0xf0, 0x00, 0x1c, 0x00,
    0x00, 0x70, 0x03, 0xe0, 0x00, 0x0e, 0x00,
    0x00, 0x70, 0x03, 0xc0, 0x00, 0x0e, 0x00,
    0x00, 0x70, 0x03, 0xc0, 0x00, 0x0f, 0x00,
    0x00, 0xe0, 0x03, 0xc0, 0x00, 0x07, 0x00,
    0x00, 0xe0, 0x03, 0xc0, 0x00, 0x07, 0x00,
    0x00, 0xe0, 0x03, 0xc0, 0x00, 0x07, 0x00,
    0x3f, 0xff, 0xff, 0xc0, 0x00, 0x07, 0x00,
    0x3f, 0xff, 0xff, 0xc0, 0x00, 0x07, 0x00,
    0x3f, 0xff, 0xff, 0xc0, 0x00, 0x07, 0x00,
    0x00, 0xe0, 0x03, 0xc0, 0x00, 0x07, 0x00,
    0x00, 0xe0, 0x03, 0xc0, 0x00, 0x07, 0x00,
    0x00, 0xe0, 0x03, 0xf0, 0x00, 0x07, 0x00,
    0x00, 0x70, 0x03, 0xfc, 0x20, 0x0e, 0x00,
    0x00, 0x70, 0x03, 0xff, 0x60, 0x0e, 0x00,
    0x00, 0x70, 0x03, 0xdf, 0xf0, 0x0e, 0x00,
    0x00, 0x38, 0x03, 0xc7, 0xf0, 0x1c, 0x00,
    0x00, 0x38, 0x03, 0xc3, 0xf8, 0x1c, 0x00,
    0x00, 0x1c, 0x03, 0xc7, 0xf8, 0x3c, 0x00,
    0x00, 0x1e, 0x03, 0xc7, 0xfc, 0x78, 0x00,
    0x00, 0x0f, 0x00, 0x00, 0x7e, 0xf0, 0x00,
    0x00, 0x07, 0x80, 0x00, 0x0f, 0xe0, 0x00,
    0x00, 0x03, 0xc0, 0x00, 0x07, 0xe0, 0x00,
    0x00, 0x01, 0xf0, 0x00, 0x0f, 0xc0, 0x00,
    0x00, 0x00, 0xfc, 0x00, 0x3f, 0x00, 0x00,
    0x00, 0x00, 0x7f, 0x81, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x1f, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xff, 0xe7, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x7e, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage npn = { image_data_npn, 50, 50,
    8 };

static const uint8_t image_data_power[350] = {
		 // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙
		    // ∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙
		    // ∙∙∙∙∙███∙∙∙∙∙∙∙∙██∙∙∙∙██████∙∙∙∙██∙∙∙∙∙∙∙∙███∙∙∙∙∙
		    // ∙∙∙∙∙███∙∙∙∙∙∙∙████∙∙∙██████∙∙∙████∙∙∙∙∙∙∙███∙∙∙∙∙
		    // ∙∙∙∙███∙∙∙∙∙∙∙█████∙∙∙██████∙∙∙█████∙∙∙∙∙∙∙███∙∙∙∙
		    // ∙∙∙∙██∙∙∙∙∙∙∙██████∙∙∙██████∙∙∙██████∙∙∙∙∙∙∙██∙∙∙∙
		    // ∙∙∙███∙∙∙∙∙∙███████∙∙∙██████∙∙∙███████∙∙∙∙∙∙███∙∙∙
		    // ∙∙∙███∙∙∙∙∙∙██████∙∙∙∙██████∙∙∙∙██████∙∙∙∙∙∙███∙∙∙
		    // ∙∙∙██∙∙∙∙∙∙██████∙∙∙∙∙██████∙∙∙∙∙██████∙∙∙∙∙∙██∙∙∙
		    // ∙∙∙██∙∙∙∙∙∙██████∙∙∙∙∙██████∙∙∙∙∙██████∙∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙∙█████∙∙∙∙∙∙██████∙∙∙∙∙∙█████∙∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙██████∙∙∙∙∙∙██████∙∙∙∙∙∙██████∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙██████∙∙∙∙∙∙██████∙∙∙∙∙∙∙█████∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙██████∙∙∙∙∙∙██████∙∙∙∙∙∙∙█████∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙██████∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙█████∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙██████∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙███∙∙
		    // ∙∙███∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙███∙∙
		    // ∙∙∙██∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙███∙∙
		    // ∙∙∙██∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙██∙∙∙
		    // ∙∙∙███∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙███∙∙∙
		    // ∙∙∙███∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙███∙∙∙
		    // ∙∙∙∙███∙∙∙∙∙∙████████∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙███∙∙∙∙
		    // ∙∙∙∙███∙∙∙∙∙∙∙█████████∙∙∙∙█████████∙∙∙∙∙∙∙███∙∙∙∙
		    // ∙∙∙∙∙███∙∙∙∙∙∙∙█████████████████████∙∙∙∙∙∙███∙∙∙∙∙
		    // ∙∙∙∙∙███∙∙∙∙∙∙∙∙██████████████████∙∙∙∙∙∙∙∙███∙∙∙∙∙
		    // ∙∙∙∙∙∙███∙∙∙∙∙∙∙∙████████████████∙∙∙∙∙∙∙∙███∙∙∙∙∙∙
		    // ∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙████████████∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00,
		    0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x00,
		    0x00, 0x07, 0xe0, 0x01, 0xf8, 0x00, 0x00,
		    0x00, 0x1f, 0x00, 0x00, 0x7e, 0x00, 0x00,
		    0x00, 0x3e, 0x00, 0xc0, 0x1f, 0x00, 0x00,
		    0x00, 0x78, 0x01, 0xe0, 0x07, 0x80, 0x00,
		    0x00, 0xf0, 0x03, 0xf0, 0x03, 0xc0, 0x00,
		    0x01, 0xe0, 0x03, 0xf0, 0x01, 0xe0, 0x00,
		    0x03, 0xc0, 0x03, 0xf0, 0x00, 0xf0, 0x00,
		    0x03, 0x80, 0x03, 0xf0, 0x00, 0x70, 0x00,
		    0x07, 0x00, 0xc3, 0xf0, 0xc0, 0x38, 0x00,
		    0x07, 0x01, 0xe3, 0xf1, 0xe0, 0x38, 0x00,
		    0x0e, 0x03, 0xe3, 0xf1, 0xf0, 0x1c, 0x00,
		    0x0c, 0x07, 0xe3, 0xf1, 0xf8, 0x0c, 0x00,
		    0x1c, 0x0f, 0xe3, 0xf1, 0xfc, 0x0e, 0x00,
		    0x1c, 0x0f, 0xc3, 0xf0, 0xfc, 0x0e, 0x00,
		    0x18, 0x1f, 0x83, 0xf0, 0x7e, 0x06, 0x00,
		    0x18, 0x1f, 0x83, 0xf0, 0x7e, 0x07, 0x00,
		    0x38, 0x1f, 0x03, 0xf0, 0x3e, 0x07, 0x00,
		    0x38, 0x3f, 0x03, 0xf0, 0x3f, 0x07, 0x00,
		    0x38, 0x3f, 0x03, 0xf0, 0x1f, 0x07, 0x00,
		    0x38, 0x3f, 0x03, 0xf0, 0x1f, 0x07, 0x00,
		    0x38, 0x3f, 0x01, 0xe0, 0x1f, 0x07, 0x00,
		    0x38, 0x3f, 0x00, 0xc0, 0x1f, 0x07, 0x00,
		    0x38, 0x3f, 0x00, 0x00, 0x3f, 0x07, 0x00,
		    0x38, 0x1f, 0x00, 0x00, 0x3e, 0x07, 0x00,
		    0x18, 0x1f, 0x80, 0x00, 0x3e, 0x07, 0x00,
		    0x18, 0x1f, 0x80, 0x00, 0x7e, 0x06, 0x00,
		    0x1c, 0x0f, 0xc0, 0x00, 0xfc, 0x0e, 0x00,
		    0x1c, 0x0f, 0xe0, 0x01, 0xfc, 0x0e, 0x00,
		    0x0e, 0x07, 0xf8, 0x03, 0xf8, 0x1c, 0x00,
		    0x0e, 0x03, 0xfe, 0x1f, 0xf0, 0x1c, 0x00,
		    0x07, 0x01, 0xff, 0xff, 0xf0, 0x38, 0x00,
		    0x07, 0x00, 0xff, 0xff, 0xc0, 0x38, 0x00,
		    0x03, 0x80, 0x7f, 0xff, 0x80, 0x70, 0x00,
		    0x03, 0xc0, 0x1f, 0xfe, 0x00, 0xf0, 0x00,
		    0x01, 0xe0, 0x03, 0xf0, 0x01, 0xe0, 0x00,
		    0x00, 0xf0, 0x00, 0x00, 0x03, 0xc0, 0x00,
		    0x00, 0x78, 0x00, 0x00, 0x07, 0x80, 0x00,
		    0x00, 0x3e, 0x00, 0x00, 0x1f, 0x00, 0x00,
		    0x00, 0x1f, 0x00, 0x00, 0x7e, 0x00, 0x00,
		    0x00, 0x07, 0xe0, 0x01, 0xf8, 0x00, 0x00,
		    0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x00,
		    0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00,
		    0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage power = { image_data_power, 50, 50,
    8 };

static const uint8_t image_data_tranzistor[350] = {
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙████∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙█∙∙██∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████████∙∙∙███∙∙∙∙█∙∙∙██∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████████████∙∙∙∙█∙∙∙∙█∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████████████████∙∙∙∙█∙∙∙∙█∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙██████∙∙∙∙█∙∙∙∙█∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙█∙∙∙██∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████████∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙███∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙███∙∙███∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙███∙∙∙███∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙███∙∙∙███∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙██████████████∙∙∙∙███∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙██████████████∙∙∙∙███∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙
    // ∙∙∙███∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙
    // ∙██∙∙∙█∙∙∙██∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙
    // ∙█∙∙∙∙█∙∙∙██∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙
    // ██∙∙∙∙∙∙∙∙██∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙
    // ██∙∙∙██∙∙∙██∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙
    // ██∙∙∙∙█∙∙∙██∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙
    // ∙█∙∙∙∙█∙∙∙██∙∙∙∙∙█∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙
    // ∙∙█████∙∙∙██∙∙∙∙██∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙██∙∙∙███∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██∙∙∙∙∙
    // ∙∙████████████████████████████████████∙∙∙∙∙██∙∙∙∙∙
    // ∙∙████████████████████████████████████∙∙∙∙███∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙██∙∙███∙∙∙∙∙∙███∙∙∙∙∙∙∙∙███∙∙∙███∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙███∙∙██∙∙∙∙∙∙███∙∙∙∙∙∙∙∙███∙∙∙███∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙███∙∙█∙∙∙∙∙∙███∙∙∙∙∙∙∙∙███∙∙███∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙███∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙████∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████∙∙███∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙██████∙∙∙∙∙∙∙∙∙██████∙∙∙██∙∙█∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███████████████████∙∙∙█∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████████████∙∙∙███∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙█████████∙∙∙███∙∙∙∙∙███∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙█∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙█∙∙∙█∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙████∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙███∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    // ∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙∙
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x78, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x26, 0x00,
    0x00, 0x00, 0x00, 0xff, 0x1c, 0x23, 0x00,
    0x00, 0x00, 0x07, 0xff, 0xfc, 0x21, 0x00,
    0x00, 0x00, 0x1f, 0xff, 0xfc, 0x21, 0x00,
    0x00, 0x00, 0x7e, 0x00, 0xfc, 0x21, 0x00,
    0x00, 0x00, 0xf8, 0x00, 0x1f, 0x23, 0x00,
    0x00, 0x01, 0xe0, 0x00, 0x1f, 0xfc, 0x00,
    0x00, 0x03, 0xc0, 0x00, 0x1f, 0xc0, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x1d, 0xc0, 0x00,
    0x00, 0x0e, 0x00, 0xe0, 0x1c, 0xe0, 0x00,
    0x00, 0x0e, 0x00, 0xe0, 0x1c, 0x70, 0x00,
    0x00, 0x1c, 0x00, 0xe0, 0x1c, 0x70, 0x00,
    0x00, 0x18, 0x00, 0xff, 0xfc, 0x38, 0x00,
    0x00, 0x18, 0x00, 0xff, 0xfc, 0x38, 0x00,
    0x00, 0x38, 0x00, 0xe0, 0x00, 0x18, 0x00,
    0x00, 0x30, 0x00, 0xe0, 0x00, 0x1c, 0x00,
    0x1c, 0x30, 0x00, 0xe0, 0x00, 0x1c, 0x00,
    0x62, 0x30, 0x00, 0xe0, 0x00, 0x0c, 0x00,
    0x42, 0x30, 0x00, 0xe0, 0x00, 0x0c, 0x00,
    0xc0, 0x30, 0x00, 0xe0, 0x00, 0x0c, 0x00,
    0xc6, 0x30, 0x00, 0xe0, 0x00, 0x0c, 0x00,
    0xc2, 0x30, 0x00, 0xe0, 0x00, 0x0c, 0x00,
    0x42, 0x30, 0x40, 0xe0, 0x00, 0x1c, 0x00,
    0x3e, 0x30, 0xc0, 0xe0, 0x00, 0x1c, 0x00,
    0x00, 0x31, 0xc0, 0xe0, 0x00, 0x18, 0x00,
    0x3f, 0xff, 0xff, 0xff, 0xfc, 0x18, 0x00,
    0x3f, 0xff, 0xff, 0xff, 0xfc, 0x38, 0x00,
    0x00, 0x19, 0xc0, 0xe0, 0x1c, 0x70, 0x00,
    0x00, 0x1c, 0xc0, 0xe0, 0x1c, 0x70, 0x00,
    0x00, 0x0e, 0x40, 0xe0, 0x1c, 0xe0, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x1d, 0xc0, 0x00,
    0x00, 0x03, 0x80, 0x00, 0x1f, 0xc0, 0x00,
    0x00, 0x01, 0xe0, 0x00, 0x1f, 0x80, 0x00,
    0x00, 0x00, 0xf8, 0x00, 0x1f, 0x38, 0x00,
    0x00, 0x00, 0x7e, 0x00, 0xfc, 0x64, 0x00,
    0x00, 0x00, 0x1f, 0xff, 0xfc, 0x40, 0x00,
    0x00, 0x00, 0x07, 0xff, 0xfc, 0x70, 0x00,
    0x00, 0x00, 0x01, 0xff, 0x1c, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x04, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x44, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x78, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const tImage tranzistor = { image_data_tranzistor, 50, 50,
    8 };
