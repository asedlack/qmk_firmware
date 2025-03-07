#include QMK_KEYBOARD_H

enum custom_keycodes {
  KVM_1 = SAFE_RANGE,
  KVM_2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KVM_1,  KVM_2,
    KC_F1,  KC_F2,  KC_F3,  KC_F4,
    KC_F5,  KC_F6,
    KC_F7,  KC_F8, KC_F9, KC_F10,
    KC_F11, KC_F12
  ),
};

// Process macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KVM_1:
      if (record->event.pressed) {
        tap_code(KC_SCRL);
        tap_code(KC_SCRL);
        tap_code(KC_1);
      }
      break;
    case KVM_2:
      if (record->event.pressed) {
        tap_code(KC_SCRL);
        tap_code(KC_SCRL);
        tap_code(KC_2);
      }
      break;
  }
  return true;
};

// Process encoders
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    return false;
}
