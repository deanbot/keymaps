#include QMK_KEYBOARD_H

#include "solo.h"

// current swapper state
#ifdef CUSTOM_SWAPPER_ENABLE
bool sw_win_active = false;
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // process window swapping
  #ifdef CUSTOM_SWAPPER_ENABLE
  // set swapper keycodes by current os
  uint16_t cmdish = KC_LALT; //KC_LGUI;
  uint16_t tabish = KC_TAB;
  bool processFurther = update_swapper(&sw_win_active, cmdish, tabish, _SWWIN_, keycode, record);
  if (!processFurther) {
    return false;
  }
  #endif

  switch (keycode) {
    // LT allows only basic keycodes, to do anything else we intercept uncommon
    // keys and replace with shortcut. Here we process lt with f keys.
    //
    // "Top of page" when tapped
    case LT_P2__:
      if (record->event.pressed && record->tap.count) {
        // osx
        SEND_STRING(SS_LCMD(SS_TAP(X_UP)));

        // win
        // SEND_STRING(SS_GUI(SS_TAP(X_HOME)));
        return false;
      }
      break;

    // "Bottom of page" when tapped
    case LT_P3__:
      if (record->event.pressed && record->tap.count) {
        // osx
        SEND_STRING(SS_LCMD(SS_TAP(X_DOWN)));

        // win
        // SEND_STRING(SS_GUI(SS_TAP(X_END)));
        return false;
      }
      break;

    // select line macro
    case _SEL_L_:
      if (record->event.pressed) {
        // osx
        SEND_STRING(SS_LCMD(SS_TAP(X_RIGHT)) SS_LCMD(SS_TAP(X_LEFT)) SS_LSFT(SS_LCMD(SS_TAP(X_RIGHT))));

        // win
        // SEND_STRING(SS_TAP(X_END) SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
      }
      return false;

    // double click macro
    case _MB1X2_:
      if (record->event.pressed) {
        register_code(KC_MS_BTN1);
        unregister_code(KC_MS_BTN1);
        register_code(KC_MS_BTN1);
        unregister_code(KC_MS_BTN1);
      }
      return false;
  }

  return true;
}
