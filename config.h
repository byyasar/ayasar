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
#define ENCODERS_PAD_A \
    { B13 }
#define ENCODERS_PAD_B \
    { B14 }
#define ENCODER_RESOLUTION 4
#endif

#define OLED_TIMEOUT 120000
#define OLED_BRIGHTNESS 120

