/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    NUMBERS,
    SYM,
    NAV,
    FN,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
#define my_moonlander( k0,k1,k2,k3,k4,k5,k6,k7,k8,k9,k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,k20,k21,k22,k23,k24,k25,k26,k27,k28,k29,k30,k31,k32,k33) \
   LAYOUT_moonlander( \
        KC_NO,   k0,      k1,      k2,      k3,      k4,      KC_NO, KC_NO,   k5,      k6,      k7,      k8,      k9,      KC_NO, \
        KC_NO,   k10,     k11,     k12,     k13,     k14,     KC_NO, KC_NO,   k15,     k16,     k17,     k18,     k19,     KC_NO, \
        KC_NO,   k20,     k21,     k22,     k23,     k24,     KC_NO, KC_NO,   k25,     k26,     k27,     k28,     k29,     KC_NO, \
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   k30,     k31,                     k32,     k33,     KC_NO,   KC_NO,   KC_NO,   KC_NO, \
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO, KC_NO,            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
                                            KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO \
    )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = my_moonlander(
        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                           KC_Y,      KC_U,       KC_I,       KC_O,       KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                           KC_H,      LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN),
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                           KC_N,      KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,
                                 MO(NUMBERS),  LT(NAV,KC_BSPC),                         KC_LSFT,        LT(SYM,KC_SPC)
    ),
    [NUMBERS] = my_moonlander(
        RESET,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_ESC,         KC_7,            KC_8,             KC_9,             KC_0,
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_0,           KC_4,            KC_5,             KC_6,             KC_TAB,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_CAPS,        KC_1,            KC_2,             KC_3,             KC_DEL,
                                              KC_NO,    KC_NO,                        MO(FN),         KC_NO
    ),
    [SYM] = my_moonlander(
        KC_NO,    KC_NO,      KC_MINS,    KC_EQL,     KC_NO,                          KC_NO,        KC_NO,           KC_NO,            KC_NO,            KC_NO,
        KC_NO,    KC_LBRC,    KC_RBRC,    KC_QUOT,    KC_ENTER,                       KC_NO,        KC_LSFT,         KC_LCTL,          KC_LALT,          KC_LGUI,
        KC_NO,    KC_NO,      KC_BSLS,    KC_GRV,     KC_NO,                          KC_NO,        KC_NO,           KC_NO,            KC_NO,            KC_NO,
                                            KC_NO,    KC_NO,                          KC_NO,        KC_NO
    ),
    [NAV] = my_moonlander(
        RESET,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_NO,        KC_NO,         KC_NO,          KC_NO,          KC_NO,
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_LEFT,      KC_DOWN,       KC_UP,          KC_RIGHT,       KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_NO,        KC_NO,         KC_NO,          KC_NO,          KC_NO,
                                            KC_NO,      KC_NO,                        KC_NO,        KC_NO
    ),
    [FN] = my_moonlander(
        RESET,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_F10,          KC_F7,            KC_F8,            KC_F9,       KC_NO,        
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_F11,          KC_F4,            KC_F5,            KC_F6,       KC_NO,        
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_F12,          KC_F1,            KC_F2,            KC_F3,       KC_NO,        
                                            KC_NO,      KC_NO,                        KC_NO,        KC_NO
    ),
};

const uint16_t PROGMEM combo1[] = {LSFT_T(KC_F), LSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo2[] = {LCTL_T(KC_D), LCTL_T(KC_K), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo1, KC_ENT),
    COMBO(combo2, KC_ESC),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
