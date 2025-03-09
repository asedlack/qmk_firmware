enum custom_keycodes {
  KVM_1 = SAFE_RANGE,
  KVM_2,
  UC_FLIP,         // (ಠ痊ಠ)┻━┻
  UC_SHRG,         // ¯\_(ツ)_/¯
  UC_DISA,         // ಠ_ಠ
  UC_IRNY,         // ⸮
  UC_CLUE,         // ‽
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

// Process unicode macros
bool process_record_unicode(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UC_FLIP: // (ノಠ痊ಠ)ノ彡┻━┻
      if (record->event.pressed) {
          send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻");
      }
      break;

    case UC_SHRG: // ¯\_(ツ)_/¯
      if (record->event.pressed) {
          send_unicode_string("¯\\_(ツ)_/¯");
      }
      break;

    case UC_DISA: // ಠ_ಠ
      if (record->event.pressed) {
          send_unicode_string("ಠ_ಠ");
      }
      break;

    case UC_IRNY: // ⸮
      if (record->event.pressed) {
          register_unicode(0x2E2E);
      }
      break;
    case UC_CLUE: // ‽
      if (record->event.pressed) {
          register_unicode(0x203D);
      }
      break;
    }
  return true;
};
