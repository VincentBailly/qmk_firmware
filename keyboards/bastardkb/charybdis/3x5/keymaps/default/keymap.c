/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
  //  LAYER_BASE = 0,
  //  LAYER_LOWER,
  //  LAYER_RAISE,
    LAYER_BASE = 0,  // default layer
    LAYER_NUMBERS,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_FN,
    LAYER_MOUSE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────────────────────╮ ╭─────────────────────────────────────────────────────────────────────────────╮
          KC_J,         KC_F,         KC_M,         KC_P,         KC_V,             KC_SCLN,   KC_DOT,          KC_SLSH,        KC_COMM,        KC_QUOT,
  // ├──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────┤
          LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_D), KC_W,             KC_SCLN,   LSFT_T(KC_A),    LCTL_T(KC_E),   LALT_T(KC_I),   LGUI_T(KC_H),
  // ├──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────┤
          KC_X,         KC_G,         KC_L,         KC_C,         KC_B,             KC_MINS,   LT(LAYER_MOUSE, KC_U), KC_O,           KC_Y,           KC_K,
  // ╰──────────────────────────────────────────────────────────────────────┤ ├─────────────────────────────────────────────────────────────────────────────╯
                              LT(LAYER_NUMBERS, KC_T),  LT(LAYER_NAV,KC_BSPC), KC_NO,             KC_LSFT,  LT(LAYER_SYM,KC_SPC) 
  //                         ╰──────────────────────────────────────────────╯ ╰───────────────────────────────────────╯
  ),

[LAYER_NUMBERS] = LAYOUT( 
    QK_BOOT,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_ESC,         KC_7,            KC_8,             KC_9,             KC_0, 
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_0,           KC_4,            KC_5,             KC_6,             KC_TAB, 
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_CAPS,        KC_1,            KC_2,             KC_3,             KC_DEL, 
                                    KC_NO,  KC_LSFT,          KC_NO,                 KC_LSFT,      MO(LAYER_FN) 
),
[LAYER_SYM] = LAYOUT( 
    KC_NO,    KC_NO,      KC_MINS,    KC_EQL,     KC_NO,                          KC_NO,        KC_NO,           KC_NO,            KC_NO,            KC_NO, 
    KC_NO,    KC_LBRC,    KC_RBRC,    KC_QUOT,    KC_ENTER,                       KC_NO,        KC_LSFT,         KC_LCTL,          KC_LALT,          KC_LGUI, 
    KC_NO,    KC_NO,      KC_BSLS,    KC_GRV,     KC_NO,                          KC_NO,        KC_NO,           KC_NO,            KC_NO,            KC_NO, 
                                  MO(LAYER_FN), KC_LSFT,           KC_NO,              KC_LSFT,          KC_NO 
),
[LAYER_NAV] = LAYOUT( 
    QK_BOOT,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                      KC_NO,        KC_PAGE_DOWN,  KC_PAGE_UP,     KC_NO,          KC_NO, 
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_LEFT,      KC_DOWN,       KC_UP,          KC_RIGHT,       KC_NO, 
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_NO,        KC_HOME,       KC_END,         KC_NO,          KC_NO, 
                                       KC_NO,      KC_LSFT,     KC_NO,                     KC_LSFT,   KC_NO 
),
[LAYER_FN] = LAYOUT( 
    QK_BOOT,     KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_F10,          KC_F7,            KC_F8,            KC_F9,       KC_NO,         
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_F11,          KC_F4,            KC_F5,            KC_F6,       KC_NO,         
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_F12,          KC_F1,            KC_F2,            KC_F3,       KC_NO,         
                                     KC_LSFT,     KC_NO,      KC_NO,                      KC_LSFT,    KC_NO 
),
[LAYER_MOUSE] = LAYOUT( 
    KC_NO,      KC_NO,      SNIPING,    DRGSCRL,    KC_NO,                        KC_NO,          DPI_MOD,          S_D_MOD,          KC_NO,       KC_NO,         
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_NO,          KC_NO,            KC_NO,            KC_NO,       KC_NO,         
    KC_NO,      KC_NO,      KC_NO,      KC_BTN3,      KC_NO,                        KC_NO,          KC_NO,            KC_NO,            KC_NO,       KC_NO,         
                                     KC_BTN1,     KC_BTN2,      KC_NO,                         KC_NO,    KC_NO 
),
};

const uint16_t PROGMEM combo1[] = { LSFT_T(KC_A), LCTL_T(KC_E), LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo2[] = { LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_J, KC_F, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_K, LT(LAYER_MOUSE, KC_U), COMBO_END};
const uint16_t PROGMEM combo5[] = { LT(LAYER_MOUSE,KC_U), LCTL_T(KC_E), LALT_T(KC_I), COMBO_END};

combo_t key_combos[] = {
    COMBO(combo1, KC_ENT),
    COMBO(combo2, KC_ESC),
    COMBO(combo3, KC_Z),
    COMBO(combo4, KC_Q),
    COMBO(combo5, KC_TAB),
};

// clang-format on