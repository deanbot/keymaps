#include QMK_KEYBOARD_H

#include "deanbot.h"

#ifdef CUSTOM_ONESHOT_ENABLE
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case _MOSYM_:
    case _MONAV_:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case _MOSYM_:
    case _MONAV_:

    case _O_SFT_:
    case _O_OPT_:
    case _O_CTL_:
    case _O_CMD_:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_opt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
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
  update_swapper(
    &sw_lang_active, KC_LSHIFT, KC_LOPT, _SWLNG_,
    keycode, record
  );
#endif

#ifdef CUSTOM_ONESHOT_ENABLE
  process_oneshot(
    &os_shft_state, KC_LSHIFT, _O_SFT_,
    keycode, record
  );
  process_oneshot(
    &os_ctrl_state, KC_LCTL, _O_CTL_,
    keycode, record
  );
  process_oneshot(
    &os_opt_state, KC_LOPT, _O_OPT_,
    keycode, record
  );
  process_oneshot(
    &os_cmd_state, KC_LCMD, _O_CMD_,
    keycode, record
  );
#endif

#ifdef CUSTOM_REPEAT_ENABLE
  if (!process_repeat_last_key(keycode, record, __RPT__, _MONAV_)) {
    return false;
  }
#endif

  switch (keycode) {
    // select line
    case _SEL_L_:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
      }
      break;

    // ${} then tap left
    case _STRIN_:
      if (record->event.pressed) {
        SEND_STRING("${}" SS_TAP(X_LEFT));
      }
      break;

  #ifdef CUSTOM_CAPS_WORD_ENABLE
    case _CAPSW_:
      if (record->event.pressed) {
        return false;
      } else {
        caps_word_toggle();
        return false;
      }
  #endif
  }

#ifdef CUSTOM_CAPS_WORD_ENABLE
  process_caps_word(keycode, record);
#endif

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}
