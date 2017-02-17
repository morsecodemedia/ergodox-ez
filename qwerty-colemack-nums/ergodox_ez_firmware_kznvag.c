#include "ergodox.h"
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

  [0] = KEYMAP(KC_MINUS,KC_1,KC_2,KC_3,KC_4,KC_5,KC_ESCAPE,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,TG(1),KC_BSPACE,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,ALL_T(KC_NO),KC_LCTL,KC_F14,KC_F15,KC_LEFT,KC_RIGHT,ALT_T(KC_APPLICATION),KC_LGUI,KC_LBRACKET,KC_SPACE,KC_BSPACE,KC_QUOTE,KC_GRAVE,KC_6,KC_7,KC_8,KC_9,KC_0,KC_EQUAL,MEH_T(KC_NO),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,SCMD_T(KC_NO),KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_LSHIFT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_SYSTEM_SLEEP,KC_LALT,KC_LCTL,KC_RBRACKET,KC_BSLASH,KC_TAB,KC_ENTER),

  [1] = KEYMAP(KC_MINUS,KC_1,KC_2,KC_3,KC_4,KC_5,KC_ESCAPE,KC_TAB,KC_Q,KC_W,KC_F,KC_P,KC_G,KC_TRANSPARENT,KC_BSPACE,KC_A,KC_R,KC_S,KC_T,KC_D,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,ALL_T(KC_NO),KC_LCTL,KC_F14,KC_F15,KC_TRANSPARENT,TO(2),ALT_T(KC_APPLICATION),KC_LGUI,KC_LBRACKET,KC_SPACE,KC_BSPACE,KC_QUOTE,KC_GRAVE,KC_6,KC_7,KC_8,KC_9,KC_0,KC_EQUAL,MEH_T(KC_NO),KC_J,KC_L,KC_U,KC_Y,KC_SCOLON,KC_F12,KC_H,KC_N,KC_E,KC_I,KC_O,KC_QUOTE,SCMD_T(KC_NO),KC_K,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_LSHIFT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_SYSTEM_SLEEP,KC_LALT,KC_LCTL,KC_RBRACKET,KC_BSLASH,KC_TAB,KC_ENTER),

  [2] = KEYMAP(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LPRN,KC_RPRN,KC_MINUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_7,KC_8,KC_9,KC_KP_ASTERISK,KC_TRANSPARENT,KC_TRANSPARENT,KC_4,KC_5,KC_6,KC_KP_PLUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_1,KC_2,KC_3,KC_EQUAL,KC_TRANSPARENT,KC_TRANSPARENT,KC_0,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

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

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
