#include QMK_KEYBOARD_H

enum layers {
    BASE,  // default layer
    NUMBERS,
    SYM,
    NAV,
    FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_split_3x5_3( \
   KC_Q,         KC_W,         KC_K,         KC_R,         KC_NO,             KC_Y,      KC_U,         KC_L,         KC_COMM,         KC_P, \
   LGUI_T(KC_J), LALT_T(KC_S), LCTL_T(KC_N), LSFT_T(KC_F), KC_G,              KC_H,      LSFT_T(KC_A), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_SCLN), \
   KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,              KC_D,      KC_M,         KC_O,      KC_DOT,       KC_SLSH, \
                           KC_LSFT,  LT(NUMBERS, KC_T),  LT(NAV,KC_BSPC),       KC_LSFT,  LT(SYM,KC_SPC), KC_LSFT \
),
[NUMBERS] = LAYOUT_split_3x5_3( \
    RESET,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_ESC,         KC_7,            KC_8,             KC_9,             KC_0, \
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_0,           KC_4,            KC_5,             KC_6,             KC_TAB, \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_CAPS,        KC_1,            KC_2,             KC_3,             KC_DEL, \
                                  KC_LSFT,          KC_NO,    KC_NO,                 KC_LSFT,         MO(FN),         KC_NO \
),
[SYM] = LAYOUT_split_3x5_3( \
    KC_NO,    KC_NO,      KC_MINS,    KC_EQL,     KC_NO,                          KC_NO,        KC_NO,           KC_NO,            KC_NO,            KC_NO, \
    KC_NO,    KC_LBRC,    KC_RBRC,    KC_QUOT,    KC_ENTER,                       KC_NO,        KC_LSFT,         KC_LCTL,          KC_LALT,          KC_LGUI, \
    KC_NO,    KC_NO,      KC_BSLS,    KC_GRV,     KC_NO,                          KC_NO,        KC_NO,           KC_NO,            KC_NO,            KC_NO, \
                               KC_LSFT,           KC_NO,    KC_NO,                  KC_LSFT,          KC_NO,        KC_NO \
),
[NAV] = LAYOUT_split_3x5_3( \
    RESET,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_NO,        KC_NO,         KC_NO,          KC_NO,          KC_NO, \
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_LEFT,      KC_DOWN,       KC_UP,          KC_RIGHT,       KC_NO, \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_NO,        KC_NO,         KC_NO,          KC_NO,          KC_NO, \
                                     KC_LSFT,     KC_NO,      KC_NO,                       KC_LSFT,   KC_NO,        KC_NO \
),
[FN] = LAYOUT_split_3x5_3( \
    RESET,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_F10,          KC_F7,            KC_F8,            KC_F9,       KC_NO,         \
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    KC_NO,                        KC_F11,          KC_F4,            KC_F5,            KC_F6,       KC_NO,         \
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                        KC_F12,          KC_F1,            KC_F2,            KC_F3,       KC_NO,         \
                                     KC_LSFT,     KC_NO,      KC_NO,                      KC_LSFT,    KC_NO,        KC_NO \
),
};

const uint16_t PROGMEM combo1[] = {LSFT_T(KC_F), LSFT_T(KC_A), COMBO_END};
const uint16_t PROGMEM combo2[] = {LCTL_T(KC_N), LCTL_T(KC_E), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo1, KC_ENT),
    COMBO(combo2, KC_ESC),
};
