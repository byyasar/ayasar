// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_turkish_f.h"
#include "sendstring_turkish_f.h"

int myLayer = 0;

enum custom_keycodes {
    SHUT = SAFE_RANGE,
    MYCHANGELAYER,
};

void i2c_init(void) {
    setPinInput(B6); // Try releasing special pins for a short time
    setPinInput(B7);
    wait_ms(10); // Wait for the release to happen
 }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┤ + │
     * │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │   │
     * ├───┴───┼───┤Ent│
     * │   0   │ . │   │
     * └───────┴───┴───┘
     */
    //[0] = LAYOUT_numpad_4x4(KC_P7, KC_P8, TG(ChangeLayer), KC_PPLS, KC_P4, KC_P5, LT(1,KC_P6), KC_P1, KC_P2, KC_P3, KC_PENT, KC_P0, KC_PDOT),
    [0] = LAYOUT_numpad_4x3(
        KC_P8,KC_P9,XXXXXXX, XXXXXXX,
        KC_P4, KC_P5, KC_P6, KC_P7,
        KC_P0, KC_P1, KC_P2, KC_P3)
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SHUT: // oturum kapatır
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(TR_R);
                unregister_code(TR_R);
                unregister_code(KC_LGUI);
                tap_code_delay(KC_WH_U, 1000);
                SEND_STRING(" logoff");
                tap_code(KC_ENT);
            }
            break;

        case MYCHANGELAYER:
            if (record->event.pressed) {
                layer_off(myLayer);
                myLayer++;
                myLayer=myLayer % 2;
                layer_on(myLayer);
               
            }
            break;
    }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            // rgblight_setrgb (0x00,  0x00, 0xFF);
            break;
        case 1:
            // rgblight_setrgb (0xFF,  0x00, 0x00);
            break;

        default: //  for any other layers, or the default layer
            // rgblight_setrgb (0x00,  0xFF, 0xFF);
            break;
    }
    return state;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            if (clockwise) {
               tap_code(KC_VOLU);
     
            } else {
                tap_code(KC_VOLD);

            }
            break;
        case 1:
            if (clockwise) {
               tap_code(KC_VOLU);
     

            } else {
                tap_code(KC_VOLD);

            }
            break;
        case 2:
            if (clockwise) {
               tap_code(KC_VOLU);
     

            } else {
                tap_code(KC_VOLD);

            }
            break;
         
        
    }
    return false;
}


static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return false;
}