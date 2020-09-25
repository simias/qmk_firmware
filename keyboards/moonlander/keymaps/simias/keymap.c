/*
Copyright 2020 ZSA Technology Labs, Inc <@zsa>
Copyright 2020 Jack Humbert <jack.humb@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
    RGB_STG,
};

enum layers {
    BASE = 0,
    ARROWS = 1,
    EMACS = 2,
    GAMING = 3,
};

#define CT_ESC   LCTL_T(KC_ESC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    TO(3),             _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        CT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_APP,            KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
        KC_PGDN, KC_PGUP, _______, _______, KC_LALT,              KC_ESC,   KC_MUTE,               KC_MINS, KC_EQL,  _______, _______, _______,
                                            KC_SPC,  MO(2),   KC_LGUI,           _______, MO(1),   KC_RALT
    ),

    [ARROWS] = LAYOUT_moonlander(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, KC_UP,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, KC_VOLD, KC_VOLU, _______,                             _______, _______, _______, _______, _______, _______,
        _______, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI,              RGB_MOD,  RGB_STG,               _______, _______, _______, _______, _______,
                                            RGB_VAD, RGB_VAI, _______,           _______, _______, _______
    ),

    [EMACS] = LAYOUT_moonlander(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, KC_UP,   _______, _______,           _______, KC_RGHT, _______, _______, _______, _______, _______,
        _______, KC_HOME, _______, KC_END,  _______, _______, _______,           _______, KC_DEL,  KC_BSPC, _______, KC_DOWN, KC_RBRC, _______,
        _______, _______, _______, KC_VOLD, KC_VOLU, _______,                             KC_LEFT, KC_ENT,  _______, _______, _______, _______,
        _______, _______, _______, _______, _______,              _______,   _______,              _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
    [GAMING] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, TO(3),             _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, KC_RSFT,
        _______, _______, _______, _______, _______,              _______,   _______,              _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

static bool had_rgb = false;
static uint32_t rgb_mode = 0;
static uint16_t rgb_hue = 0;
static uint8_t rgb_sat = 0;
static uint8_t rgb_val = 0;

void rgblight_bank(void) {
    had_rgb = rgblight_is_enabled();
    rgb_mode = rgblight_get_mode();
    rgb_hue = rgblight_get_hue();
    rgb_sat = rgblight_get_sat();
    rgb_val = rgblight_get_val();
}

void rgblight_restore(void) {
    if (had_rgb) {
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(rgb_mode);
        rgblight_sethsv_noeeprom(rgb_hue, rgb_sat, rgb_val);
    } else {
        rgblight_mode_noeeprom(rgb_mode);
        rgblight_sethsv_noeeprom(rgb_hue, rgb_sat, rgb_val);
        rgblight_disable_noeeprom();
    }
}

static bool in_sc = false;

void led_set_user(uint8_t usb_led) {

    bool is_sc = usb_led & (1 << USB_LED_SCROLL_LOCK);

    if (in_sc == is_sc) {
        return;
    }

    in_sc = is_sc;

    if (is_sc) {
        rgblight_bank();

        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(0, 0xff, (rgb_val > 0x1f) ? rgb_val : 0x1f);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

        ML_LED_6(true);
    } else {
        rgblight_restore();
        ML_LED_6(false);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case RGB_STG:
            if (!in_sc) {
#if defined(RGBLIGHT_ENABLE) && !defined(RGBLIGHT_DISABLE_KEYCODES)
                rgblight_toggle();
#endif
#if defined(RGB_MATRIX_ENABLE) && !defined(RGB_MATRIX_DISABLE_KEYCODES)
                rgb_matrix_toggle();
#endif
            }
            return false;
        }
    }
    return true;
}
