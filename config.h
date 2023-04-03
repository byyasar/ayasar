// Copyright 2023 byyasar (@byyasar)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

//A VE B kanalı çok önemli değil, eğer yanlış bağlarsan bunları yer değiştir.
#ifdef ENCODER_ENABLE

#define ENCODER_RESOLUTION 4
#endif


//#define MY_I2C_ADDRESS (0x3C << 1)

#ifdef OLED_ENABLE
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define OLED_BRIGHTNESS 128
#define OLED_DISPLAY_ADDRESS 0x3C
//#define I2C1_I2C_ADDRESS 0xBC

//#define OLED_FONT_H "keyboards/mlego/m65/lib/glcdfont.c"
#endif

