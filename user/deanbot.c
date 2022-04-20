#include QMK_KEYBOARD_H

#include "deanbot.h"

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "drivers/sensors/pimoroni_trackball.h"
#include "pointing_device.h"
#include "color.h"
#endif

#ifdef CUSTOM_ONESHOT_ENABLE

bool is_oneshot_modifier_cancel_key(uint16_t keycode) {
  switch (keycode) {
  case _MONAV_:
  case _MOSYM_:
  case _MMETA_:
  case __RPT__:
  case _CAPSW_:
    return true;
  default:
    return false;
  }
}

bool is_oneshot_modifier_ignored_key(uint16_t keycode) {
  switch (keycode) {
  case _MONAV_:
  case _MOSYM_:
  case _MOMIR_:
    return true;
  }
  return false;
}

oneshot_mod get_modifier_for_trigger_key(uint16_t keycode) {
  switch (keycode) {
  case _O_SFT_:
    return ONESHOT_LSFT;
  case _O_CTL_:
    return ONESHOT_LCTL;
  case _O_ALT_:
    return ONESHOT_LALT;
  case _O_GUI_:
    return ONESHOT_LGUI;
  }
  return ONESHOT_NONE;
}
#endif

#ifdef LEADER_ENABLE
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
    SEQ_TWO_KEYS(KC_P, KC_W) { SEND_STRING("Myp@ssword1"); }
    SEQ_TWO_KEYS(KC_R, KC_E) { SEND_STRING("required "); }
    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("feature/MOBL-");
      // TODO : trigger numword
    }
    SEQ_ONE_KEY(KC_G) { SEND_STRING("gf; git pull;"); }
    SEQ_ONE_KEY(KC_I) { SEND_STRING("tool/install.sh" SS_TAP(X_ENTER)); }
    SEQ_TWO_KEYS(KC_I, KC_I) { SEND_STRING("tool/build_generated.sh" SS_TAP(X_ENTER)); }
  }
}
#endif

#ifdef CUSTOM_SWAPPER_ENABLE
bool sw_win_active = false;
bool sw_lang_active = false;
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
  if (record->event.pressed) {
    uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row,
            record->event.key.col, get_highest_layer(layer_state));
  }
#endif

#ifdef CUSTOM_SWAPPER_ENABLE
  update_swapper(&sw_win_active, KC_LCMD, KC_TAB, _SWWIN_, keycode, record);
  // update_swapper(&sw_lang_active, KC_LSHIFT, KC_LOPT, _SWLNG_, keycode, record);
#endif

#ifdef CUSTOM_REPEAT_ENABLE
  if (!process_repeat_last_key(keycode, record, __RPT__, _MONAV_)) {
    return false;
  }
#endif

  // TODO : replace send string with tap_code to save space
  switch (keycode) {

  case _L_MIR_:
    if (record->event.pressed) {
      if (record->tap.count == 1) {
        qk_leader_start();
        return false;
      }
    }
    break;

  // select line
  case _SEL_L_:
    if (record->event.pressed) {
      SEND_STRING(SS_LCMD(SS_TAP(X_RIGHT)) SS_LCMD(SS_TAP(X_LEFT)) SS_LSFT(SS_LCMD(SS_TAP(X_RIGHT))));
    }
    return false;

  // ${} then tap left
  case _STRIN_:
    if (record->event.pressed) {
      SEND_STRING("${}" SS_TAP(X_LEFT));
    }
    return false;

  // <> then tap left
  case _TYPE__:
    if (record->event.pressed) {
      SEND_STRING("<>" SS_TAP(X_LEFT));
    }
    return false;

  // =>
  case _ARROW_:
    if (record->event.pressed) {
      SEND_STRING("=> ");
    }
    return false;

  case __SS___:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT("s"));
    }
    return false;

  case __UE___:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LSHIFT)) {
        unregister_code(KC_LSHIFT);
        SEND_STRING(SS_LALT("u") "U");
      } else {
        SEND_STRING(SS_LALT("u") "u");
      }
    }
    return false;

  case __OE___:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LSHIFT)) {
        unregister_code(KC_LSHIFT);
        SEND_STRING(SS_LALT("u") "O");
      } else {
        SEND_STRING(SS_LALT("u") "o");
      }
    }
    return false;

  case __AE___:
    if (record->event.pressed) {
      if (get_mods() & MOD_BIT(KC_LSHIFT)) {
        unregister_code(KC_LSHIFT);
        SEND_STRING(SS_LALT("u") "A");
      } else {
        SEND_STRING(SS_LALT("u") "a");
      }
    }
    return false;

  case __ZE___:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LSFT("2")));
    }
    return false;

  // open discord
  case _DISCO_:
    if (record->event.pressed) {
      SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "disc" SS_DELAY(100)
                      SS_TAP(X_ENTER));
    }
    return false;

  // open slack
  case _SLACK_:
    if (record->event.pressed) {
      SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "sla" SS_DELAY(100)
                      SS_TAP(X_ENTER));
    }
    return false;

  case _TEAMS_:
    if (record->event.pressed) {
      SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "tea" SS_DELAY(100)
                      SS_TAP(X_ENTER));
    }
    return false;

  case _VSCDE_:
    if (record->event.pressed) {
      SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "vsc" SS_DELAY(100)
                      SS_TAP(X_ENTER));
    }
    return false;

  case _ANDST_:
    if (record->event.pressed) {
      SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "and" SS_DELAY(100)
                      SS_TAP(X_ENTER));
    }
    return false;

#ifdef CUSTOM_CAPS_WORD_ENABLE
  case _CAPSW_:
    if (record->event.pressed) {
    } else {
      caps_word_toggle();
    }
    return false;
#endif

  // letting go of nav doesn't unregister
  case _C_MB1_:
    if (record->event.pressed) {
      register_code(KC_MS_BTN1);
    } else {
      unregister_code(KC_MS_BTN1);
    }
    return false;
  case _C_MB2_:
    if (record->event.pressed) {
      register_code(KC_MS_BTN2);
    } else {
      unregister_code(KC_MS_BTN2);
    }
    return false;
  case _C_MWD_:
    if (record->event.pressed) {
      register_code(KC_MS_WH_DOWN);
    } else {
      unregister_code(KC_MS_WH_DOWN);
    }
    return false;
  case _C_MWU_:
    if (record->event.pressed) {
      register_code(KC_MS_WH_UP);
    } else {
      unregister_code(KC_MS_WH_UP);
    }
    return false;
  }

  int8_t keycode_consumed = 0;

#ifdef CUSTOM_CAPS_WORD_ENABLE
  process_caps_word(keycode, record);
#endif

#ifdef CUSTOM_ONESHOT_ENABLE
  keycode_consumed +=
      update_oneshot_modifiers(keycode, record, keycode_consumed);
#endif

  return true;
}

layer_state_t _state;
layer_state_t layer_state_set_user(layer_state_t state) {
  // cache state for encoder handler
  _state = state;

  // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md#colors
  #if !defined(RGBLIGHT_ENABLE) && defined(PIMORONI_TRACKBALL_ENABLE)
  switch (get_highest_layer(state)) {
    // case _MIR:
    //   pimoroni_trackball_set_rgbw(RGB_CYAN, 0x00);
    //   break;
    // case _NAV:
    //   pimoroni_trackball_set_rgbw(RGB_GREEN, 0x00);
    //   break;
    // case _SYM:
    //   pimoroni_trackball_set_rgbw(RGB_PURPLE, 0x00);
    //   break;
    // case _NUM:
    //   pimoroni_trackball_set_rgbw(RGB_GOLDENROD, 0x00);
    //   break;
    case _GUI:
      pimoroni_trackball_set_rgbw(RGB_TURQUOISE, 0x00);
      break;
    // case _DBG:
    //   pimoroni_trackball_set_rgbw(RGB_SPRINGGREEN, 0x00);
    //   break;
    case _META:
      pimoroni_trackball_set_rgbw(RGB_ORANGE, 0x00);
      break;
    default:
      // if (is_caps_lock_on) {}
      pimoroni_trackball_set_rgbw(RGB_BLACK, 0x00);
      break;
  }
  #endif
  return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
  // default behavior if undefined
  if (index == 0) {
    // Conditional to reverse the direction of encoder
    #ifdef ENCODERS_A_REVERSE
    if (!clockwise) {
    #else
    if (clockwise) {
    #endif
      switch(get_highest_layer(_state)) {
        case _GUI:
          tap_code(_BRUP__);
          break;
        default:
          tap_code(KC_VOLU);
          break;
      }
    } else {
      switch(get_highest_layer(_state)) {
        case _GUI:
          tap_code(_BRDWN_);
          break;
        default:
          tap_code(KC_VOLD);
          break;
      }
    }
  }
  else if (index == 1) {
    // Conditional to reverse the direction of encoder
    #ifdef ENCODERS_B_REVERSE
    if (!clockwise) {
    #else
    if (clockwise) {
    #endif
      tap_code(KC_PGDN);
    }
    else{
      tap_code(KC_PGUP);
    }
  } else if (index == 3) {
    // center feature
  }

  return true;
}
#endif
