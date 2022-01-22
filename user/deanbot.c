#include QMK_KEYBOARD_H

#include "deanbot.h"

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


#ifdef CUSTOM_SWAPPER_ENABLE
bool sw_win_active = false;
bool sw_lang_active = false;
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
  if (record->event.pressed) {
    uprintf(
      "0x%04X,%u,%u,%u\n",
      keycode,
      record->event.key.row,
      record->event.key.col,
      get_highest_layer(layer_state));
  }
#endif

#ifdef CUSTOM_SWAPPER_ENABLE
  update_swapper(
    &sw_win_active, KC_LCMD, KC_TAB, _SWWIN_,
    keycode, record
  );
  // update_swapper(
  //   &sw_lang_active, KC_LSHIFT, KC_LOPT, _SWLNG_,
  //   keycode, record
  // );
#endif

#ifdef CUSTOM_REPEAT_ENABLE
  if (!process_repeat_last_key(keycode, record, __RPT__, _MONAV_)) {
    return false;
  }
#endif

  // TODO : replace send string with tap_code to save space
  switch (keycode) {

    // select line
    case _SEL_L_:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
      }
      return false;

    // ${} then tap left
    case _STRIN_:
      if (record->event.pressed) {
        SEND_STRING("${}" SS_TAP(X_LEFT));
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
        SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "disc" SS_DELAY(100) SS_TAP(X_ENTER));
      }
      return false;

    // open slack
    case _SLACK_:
      if (record->event.pressed) {
        SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "sla" SS_DELAY(100) SS_TAP(X_ENTER));
      }
      return false;

    case _TEAMS_:
      if (record->event.pressed) {
        SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "tea" SS_DELAY(100) SS_TAP(X_ENTER));
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}
