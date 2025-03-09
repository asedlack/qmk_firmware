enum custom_keycodes {
  KVM_1 = SAFE_RANGE,
  KVM_2,
};

// Process KVM inputs
bool process_record_kvm(uint16_t keycode, keyrecord_t *record) {
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
