#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


#include "keymap_german.h"

#include "keymap_nordic.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(
	// Left hand
	KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRNS,
	KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRNS,
	KC_LCTL,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
	KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_ENTER,
	KC_ESCAPE,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_LALT,
	                                                                                KC_VOLD,        KC_VOLU,
	                                                                                                KC_TRNS,
	                                                                KC_SPACE,       MO(2),          KC_LGUI,

	// Right hand
	KC_TRNS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLASH,
	KC_BSPACE,      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRACKET,
	                KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
	KC_ENTER,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
	                                KC_MINUS,       KC_EQUAL,       KC_TRNS,        KC_TRNS,        TG(3),

	KC_ESCAPE,      KC_AUDIO_MUTE,
	KC_PGUP,
	KC_PGDOWN,      MO(1),        KC_RALT),

  [1] = LAYOUT_ergodox(
	// Left hand
	KC_F12,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS,
	KC_TRNS,        KC_MS_WH_UP,    KC_TRNS,        KC_MS_UP,       KC_TRNS,        KC_TRNS,        KC_TRNS,
	KC_TRNS,        KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRNS,
	KC_TRNS,        KC_TRNS,        KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRNS,        KC_MS_BTN3,
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	                                                                                KC_MS_BTN4,     KC_MS_BTN5,
	                                                                                                KC_TRNS,
	                                                                KC_MS_BTN1,     KC_MS_BTN2,     KC_TRNS,

	// Right hand
	KC_TRNS,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_UP,          KC_MINUS,       KC_EQUAL,       KC_TRNS,
	                KC_TRNS,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_RBRACKET,    KC_TRNS,
	KC_TRNS,        KC_TRNS,        KC_ENTER,       KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	                                KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	KC_TRNS,        KC_TRNS,
	KC_TRNS,
	KC_TRNS,        KC_TRNS,       KC_TRNS),

  [2] = LAYOUT_ergodox(
	// Left hand
	KC_F12,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS,
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_UP,          LSFT(KC_INSERT),KC_TRNS,
	KC_TRNS,        KC_HOME,        KC_TRNS,        KC_END,         KC_TRNS,        KC_TRNS,
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_APP,
	KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	                                                                                KC_TRNS,        KC_TRNS,
	                                                                                                KC_TRNS,
	                                                                KC_TRNS,        KC_TRNS,        KC_TRNS,

	// Right hand
	KC_TRNS,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
	KC_TRNS,        KC_RIGHT,       KC_TRNS,        KC_TRNS,        KC_MINUS,       KC_EQUAL,       KC_TRNS,
	                KC_DELETE,      KC_BSPACE,      KC_TRNS,        KC_DOWN,        KC_RBRACKET,    KC_TRNS,
	KC_TRNS,        KC_LEFT,        KC_ENTER,       KC_TRNS,        RSFT(KC_INSERT),KC_TRNS,        KC_TRNS,
	                                KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	KC_TRNS,        KC_TRNS,-
	KC_TRNS,
	KC_TRNS,        KC_TRNS,        KC_TRNS),
  // Blender layer (numpad etc)
  [3] = LAYOUT_ergodox(
	// Left hand44
	KC_NLCK,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_PSLS,        KC_PAST,        KC_PENT,
	KC_TRNS,        KC_D,           KC_SLASH,       KC_P7,          KC_P8,          KC_P9,          KC_PMNS,
	KC_TRNS,        KC_TRNS,        KC_T,           KC_P4,          KC_P5,          KC_P6,
	KC_TRNS,        KC_TRNS,        KC_B,           KC_P1,          KC_P2,          KC_P3,          KC_PPLS,
	KC_TRNS,        KC_U,           KC_SCOLON,      KC_O,           KC_TRNS,
	                                                                                KC_P0,          KC_PDOT,
	                                                                                                KC_TRNS,
	                                                                KC_TRNS,        KC_TRNS,        KC_TRNS,

	// Right hand
	KC_TRNS,        KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	KC_TRNS,        KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	                KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	KC_TRNS,        KC_TRNS,        KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	                                KC_TRNS,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
	KC_TRNS,        KC_TRNS,
	KC_TRNS,
	KC_TRNS,        KC_TRNS,        KC_TRNS),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
};

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
    ergodox_right_led_1_on();
  } else {
    ergodox_right_led_1_off();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    if (layer == 3) {
      ergodox_right_led_2_on();
    } else {
      ergodox_right_led_2_off();
    }

    return state;

};
