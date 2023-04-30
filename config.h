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

/*#ifdef OLED_ENABLE
//#define OLED_DISPLAY_WIDTH 128
//#define OLED_DISPLAY_HEIGHT 32
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define OLED_DISPLAY_ADDRESS 0x3C    //
#define OLED_TIMEOUT 0
#endif*/

#ifdef OLED_ENABLE
#define OLED_DISPLAY_WIDTH 128
#define OLED_DISPLAY_HEIGHT 64
#define OLED_IC OLED_IC_SH11067
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define OLED_DISPLAY_ADDRESS 0x3C    
#define OLED_FONT_WIDTH 6
#define OLED_FONT_HEIGHT 8
#define OLED_TIMEOUT 0 
#define OLED_MATRIX_SIZE 1024

#endif
/*    0x10, // Width: 16
    0x13, // Height: 19
    0x20, // First Char: 32
    0xE0, // Numbers of Chars: 224
#define OLED_FONT_H "font/glcdfont.c"
 //5*7
#define OLED_FONT_WIDTH 19
#define OLED_FONT_HEIGHT 16
#define OLED_FONT_START 32
#define OLED_FONT_END 224*/
