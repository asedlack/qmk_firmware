#include QMK_KEYBOARD_H
#include "../../process_records.c"

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
  return (
       process_record_kvm(keycode, record)
  );
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
