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
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,           KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TRNS,           KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        CT_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_APP,            KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT,              KC_ESC,   KC_MUTE,               KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS, TO(3),
                                            KC_SPC,  MO(2),   KC_LGUI,           KC_TRNS, MO(1),   KC_RALT
    ),

    [ARROWS] = LAYOUT_moonlander(
        KC_F12,  KC_F7,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,           KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI,              RGB_MOD,  RGB_TOG,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            RGB_VAD, RGB_VAI, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [EMACS] = LAYOUT_moonlander(
        KC_F12,  KC_F7,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,           KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS,           KC_TRNS, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_HOME, KC_TRNS, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_DEL,  KC_BSPC, KC_TRNS, KC_DOWN, KC_RBRC, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS,                             KC_LEFT, KC_ENT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,   KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [GAMING] = LAYOUT_moonlander(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS,   KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
                                            KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
      ML_LED_6(true);
  } else {
      ML_LED_6(false);
  }
}

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
