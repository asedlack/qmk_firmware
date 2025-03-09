#include QMK_KEYBOARD_H

enum custom_keycodes {
  KVM_1 = SAFE_RANGE,
  KVM_2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KVM_1,            KVM_2,
    KC_NO,            KC_NO,            KC_NO,            KC_NO,
    KC_NO,            KC_NO,
    KC_NO,            KC_NO,            KC_NO,            KC_NO,
    KC_MUTE,          KC_ENTER
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
