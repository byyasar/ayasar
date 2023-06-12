// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_turkish_q.h"
#include "sendstring_turkish_q.h"
// #include "/Users/yasar/qmk_firmware/quantum/keymap_extras/keymap_turkish_f.h"
// #include "/Users/yasar/qmk_firmware/quantum/keymap_extras/sendstring_turkish_q.h"

int  myLayer       = 0;
int  mouseMode     = 1; // 1-SCROLL 2-LEFT-RİGHT 3- UP-DOWN
int  fusion360Mode = 1; // 1-zoom 2-pan
int  menuSayisi    = 5;
bool winMac        = false; // false durumunda windows true durumunda mac tuşları çalışacak

enum custom_keycodes { SHUT = SAFE_RANGE, MYCHANGELAYER, FUSIONZOOM, FUSIONPAN, TUSLARSERBEST, MOSEMODECHANGE, FUSIONROTATE, PLAYPAUSE, PENCEREGECIS, WINMAC, SUSLUPARANTEZ, CIFTTIRNAK, KUCUKTUR,CMDSHTP };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Lt basılı tuttuğumda layera git
    /* Ana Menu
     * ┌───┬───┬───────┐
     * │Ent│Esc│V- x V+│
     * ├───┼───┼───┬───┤
     * │ 1 │ 2 │ 3 │WxM│
     * ├───┼───┼───┼───┤
     * │Tab│ {}│ ""│Slp│
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_numpad_4x3( // ana
        KC_ENTER, KC_ESCAPE, MYCHANGELAYER, XXXXXXX, LT(1, KC_P1), CMDSHTP, LT(3, KUCUKTUR), WINMAC, PENCEREGECIS, SUSLUPARANTEZ, CIFTTIRNAK, KC_SYSTEM_SLEEP),

    /* Fusion 360
     * ┌───┬───┬───────┐
     * │Mod│Esc│>Scrool│
     * ├───┼───┼───┬───┤
     * │Zom│Rot│Pan│ 4 │
     * ├───┼───┼───┼───┤
     * │Tab│ 6 │ 7 │ 8 │
     * └───┴───┴───┴───┘
     */

    [1] = LAYOUT_numpad_4x3( // fusion 360
        MOSEMODECHANGE, TUSLARSERBEST, _______, XXXXXXX, FUSIONZOOM, FUSIONROTATE, FUSIONPAN, KC_P4, _______, KC_P6, KC_P7, KC_P8),

    /* Youtube
     * ┌───┬───┬───────┐
     * │Ply│Esc│İlr-Ger│
     * ├───┼───┼───┬───┤
     * │FlS│ 2 │ 3 │ V+│
     * ├───┼───┼───┼───┤
     * │Tab│ 6 │ 7 │ V-│
     * └───┴───┴───┴───┘
     */
    [2] = LAYOUT_numpad_4x3( // youtube
        KC_K, KC_ESCAPE, _______, XXXXXXX, KC_F, KC_P2, KC_P3, KC_AUDIO_VOL_UP, _______, KC_P6, KC_P7, KC_AUDIO_VOL_DOWN),
    /* VLC
     * ┌───┬───┬───────┐
     * │Ply│Esc│İlr-Ger│
     * ├───┼───┼───┬───┤
     * │FlS│ 2 │ 3 │ V+│
     * ├───┼───┼───┼───┤
     * │Tab│ 6 │ 7 │ V-│
     * └───┴───┴───┴───┘
     */
    [3] = LAYOUT_numpad_4x3( // VLC
        KC_SPACE, KC_ESCAPE, _______, XXXXXXX, LGUI(KC_F), KC_P5, KC_P6, KC_AUDIO_VOL_UP, _______, KC_P1, KC_P2, KC_AUDIO_VOL_DOWN),
    /*
     * ┌───┬───┬───────┐
     * │Ent│Esc│V- x V+│
     * ├───┼───┼───┬───┤
     * │ 1 │Rec│Pau│Stp│
     * ├───┼───┼───┼───┤
     * │Tab│Mic│Cam│Scn│
     * └───┴───┴───┴───┘
     */
    [4] = LAYOUT_numpad_4x3( // OBS
        _______, KC_ESCAPE, _______, XXXXXXX, LALT(KC_F9), LALT(KC_F10), LALT(KC_F11), LALT(KC_F12), _______, LSFT(KC_F10), LSFT(KC_F11), LSFT(KC_F12)),
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    oled_clear();
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
        case CMDSHTP: // oturum kapatır
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LEFT_SHIFT);
                register_code(KC_P);
                unregister_code(KC_LGUI);
                unregister_code(KC_LEFT_SHIFT);
                unregister_code(KC_P);
                tap_code(KC_ENT);
            }
            break;
        case FUSIONZOOM: // oturum kapatır
            if (record->event.pressed) {
                unregister_code(KC_MS_BTN3);
                unregister_code(KC_LEFT_SHIFT);
            }
            fusion360Mode = 1; //
            mouseMode     = 1;
            break;
        case FUSIONROTATE: // oturum kapatır
            if (record->event.pressed) {
                unregister_code(KC_LEFT_SHIFT);
                unregister_code(KC_MS_BTN3);
            }
            mouseMode     = 2;
            fusion360Mode = 2;
            register_code(KC_LEFT_SHIFT);
            register_code(KC_MS_BTN3);
            break;
        case FUSIONPAN: // oturum kapatır
            if (record->event.pressed) {
                unregister_code(KC_MS_BTN3);
                unregister_code(KC_LEFT_SHIFT);
            }
            fusion360Mode = 3;
            mouseMode     = 2;
            register_code(KC_MS_BTN3);
            break;
        case SUSLUPARANTEZ:
            if (record->event.pressed) {
                SEND_STRING("{");
            }
            break;
        case CIFTTIRNAK:
            if (record->event.pressed) {
                register_code(TR_DQUO);
                unregister_code(TR_DQUO);
            }
            break;
        case KUCUKTUR:
            if (record->event.pressed) {
                SEND_STRING("<");
            }
            break;
        case PENCEREGECIS: //
            if (record->event.pressed) {
                if (winMac) {
                    register_code(KC_LGUI);
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                    unregister_code(KC_LGUI);
                } else {
                    register_code(KC_LEFT_ALT);
                    register_code(KC_TAB);
                    unregister_code(KC_TAB);
                    unregister_code(KC_LEFT_ALT);
                }
            }
            break;
        case WINMAC: //
            if (record->event.pressed) {
                winMac = !winMac;
            }

            break;
        case TUSLARSERBEST: // KC_TAB
            if (record->event.pressed) {
                unregister_code(KC_MS_BTN3);
                unregister_code(KC_LEFT_SHIFT);
                fusion360Mode = 1; //
                mouseMode     = 1;
            }
            break;
        case MOSEMODECHANGE: // 1-SCROLL 2-LEFT-RİGHT 3- UP-DOWN   44444
            if (record->event.pressed) {
                if (mouseMode == 1) {
                    mouseMode++;
                } else if (mouseMode == 2) {
                    mouseMode++;
                } else {
                    mouseMode--;
                }
            }
            break;
        case MYCHANGELAYER:
            if (record->event.pressed) {
                layer_off(myLayer);
                myLayer++;
                myLayer = myLayer % menuSayisi;
                layer_on(myLayer);
            }
            break;
    }
    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case 0: // AnaMENÜ
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case 1: // Fusion 360 MENÜ
            if (clockwise) {
                if (mouseMode == 1) // zoom  in
                {
                    tap_code(KC_MS_WH_UP);
                } else if (mouseMode == 2) // left
                {
                    tap_code(KC_MS_RIGHT);
                } else {
                    tap_code(KC_MS_UP); // down
                }

            } else {
                if (mouseMode == 1) {
                    tap_code(KC_MS_WH_DOWN);
                } else if (mouseMode == 2) {
                    tap_code(KC_MS_LEFT);
                } else {
                    tap_code(KC_MS_DOWN);
                }
            }
            break;
        case 2:              // youtube menu
            if (clockwise) { // KC_MS_BTN1 KC_LEFT_SHIFT
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
            break;
        case 3:              // VLC
            if (clockwise) { // KC_MS_BTN1 KC_LEFT_SHIFT
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
            break;
        case 4: // OBS
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
    }
    return false;
}

#ifdef OLED_ENABLE

// Rotate OLEDv
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// Draw to OLED
bool oled_task_user() {
    // Rotate OLED

    oled_set_cursor(0, 0);
    // oled_write_P(myLayer == 1 ? PSTR("1->") : (myLayer == 2 ? PSTR("2->") : (myLayer == 3 ? PSTR("3->") : PSTR("0->"))), false);
    oled_write_P(winMac == false ? PSTR(" Win ") : PSTR(" Mac "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            // oled_write("----- Ana Menu -----", true);
            // oled_write("----------> Ana Menu", true);
            oled_write("      ", true);
            // oled_write_P(fusion360Mode == 1 ? PSTR("\nZOOM ") : (fusion360Mode == 2 ? PSTR("\nDONDUR ") : (fusion360Mode == 3 ? PSTR("\nTASI ") : PSTR("    "))), false);
            oled_write(" Ana Menu", false);
            oled_write("\n Ent| Esc|-> V- x V+\n  1 |  2 |  < | WxM|\n Tab| {} | '' | Slp|", true);
            break;
        case 1:
            oled_write("    ", true);
            oled_write(" Fusion 360", false);
            // oled_write(" Fusion 360->SC\nMMD|Esc|   |   |\nZom|Rot|Pan| 4 |\n 5 | 6 | 7 | 8 |", true);
            if (mouseMode == 1) {
                // oled_write("Scroll ", false);
                oled_write("\n Mod| Esc| -> Scroll\n Zom| Rot| Pan|  4 |\n Tab|  6 |  7 |  8 |", true);
            } else if (mouseMode == 2) {
                // oled_write("Left-Right ", false);
                oled_write("\n Mod| Esc|->Sol xSag\n Zom| Rot| Pan|  4 |\n Tab|  6 |  7 |  8 |", true);
            } else {
                // oled_write("Up-Down ", false);
                oled_write("\n Mod| Esc|->Asg xYuk\n Zom| Rot| Pan|  4 |\n Tab|  6 |  7 |  8 |", true);
            }
            // oled_write_P(fusion360Mode == 1 ? PSTR("\nZOOM ") : (fusion360Mode == 2 ? PSTR("\nDONDUR ") : (fusion360Mode == 3 ? PSTR("\nTASI ") : PSTR("    "))), false);
            break;
        case 2:
            oled_write("       ", true);
            oled_write(" Youtube", false);
            oled_write("\n Ply| Esc|->Iler-Ger\n FlS|  2 |  3 |  V+|\n Tab|  6 |  7 |  V-|", true);
            break;
        case 3:
            oled_write("    ", true);
            oled_write(" Vlc Player", false);
            oled_write("\n Ply| Esc|->Iler-Ger\n FlS|  2 |  3 |  V+|\n Tab|  6 |  7 |  V-|", true);
            break;
        case 4:
            oled_write("           ", true);
            oled_write(" OBS", false);
            oled_write("\n Ent| Esc|-> V- x V+\n  1 | Rec| Pau| Stp|\n Tab| Mic| Cam| Scn|", true);
            break;
    }

    return false;
}

#endif

/*bool oled_task_user(void) {
    oled_set_cursor(0, 0);
    render_logo();""""
    return false;
}*/
/*
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf0, 0xf8, 0x78, 0x3c, 0x3c, 0x1c, 0x1c,
    0x0c, 0x0c, 0x0c, 0x08, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0xc0, 0xc0, 0x80,
    0xc0, 0xc0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x60, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0,
    0xe1, 0xef, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xbf, 0x9f, 0x9f, 0x9f, 0x9f, 0x1f, 0x3f, 0x3f, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x9f, 0x9f, 0x9f, 0x9f, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3f, 0xbf, 0x9f, 0x9f, 0x9f, 0x9f, 0x1f, 0x3f, 0x3f, 0x7f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x1f, 0x1f, 0xff, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0c, 0x0e, 0x0f, 0x1f, 0xff,
    0x3f, 0x0f, 0x0e, 0x0c, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0x3f, 0xff, 0xfc, 0xe0, 0x00, 0x80, 0xf0, 0xfe, 0xff,
    0x1f, 0x03, 0x00, 0x03, 0x1f, 0x3f, 0x1f, 0x8f, 0xcf, 0xef, 0xe7, 0xe7, 0xe7, 0xe6, 0x00, 0x00,
    0x03, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xe0, 0xe7, 0xc7, 0xcf, 0x8f, 0x1f, 0x3f, 0x7f, 0xff,
    0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x8f, 0xcf, 0xef, 0xe7, 0xe7, 0xe7, 0xe6, 0x00, 0x00, 0x03, 0xff,
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x03, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x80,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xc7, 0xff, 0xff, 0x7f, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xa3, 0xe7, 0xe7, 0xe7, 0xf7, 0xf3, 0xf9, 0xf0, 0xe0,
    0xe0, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xe3, 0xe7, 0x27, 0x07, 0x67, 0xf3, 0xf0, 0xf8, 0xfe, 0xff,
    0xff, 0xff, 0xfc, 0xf0, 0xf0, 0xe3, 0xe7, 0xe7, 0xe7, 0xf7, 0xf3, 0xf9, 0xf0, 0xe0, 0xe0, 0xff,
    0xff, 0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f,
    0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0xfc, 0xfe, 0xff, 0xff, 0xf7, 0xfb, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc,
    0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf7, 0xf3, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

    //oled_write_P(qmk_logo, sizeof(qmk_logo));
     oled_write_raw_P(qmk_logo, sizeof(qmk_logo));
}

*/
