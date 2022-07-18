#include QMK_KEYBOARD_H

#include "deanbot.h"

#ifdef PIMORONI_TRACKBALL_ENABLE
#    include "color.h"
#    include "drivers/sensors/pimoroni_trackball.h"
#    include "pointing_device.h"
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
        SEQ_TWO_KEYS(KC_P, KC_W) {
            SEND_STRING("Myp@ssword1");
        }
        SEQ_TWO_KEYS(KC_R, KC_E) {
            SEND_STRING("required ");
        }
        SEQ_ONE_KEY(KC_F) {
            SEND_STRING("feature/MOBL-");
            // TODO : trigger numword
        }
        SEQ_ONE_KEY(KC_G) {
            SEND_STRING("gf; git pull;");
        }

        SEQ_ONE_KEY(KC_C) {
            tap_code16(LSFT(_CENTR_));
        }
        SEQ_TWO_KEYS(KC_D, KC_E) {
            SEND_STRING("development" SS_TAP(X_ENTER));
        }
        SEQ_ONE_KEY(KC_I) {
            SEND_STRING("tool/install.sh" SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_I, KC_I) {
            SEND_STRING("tool/build_generated.sh" SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_D, KC_M) {
            SEND_STRING("final Widget child;");
        }
        SEQ_TWO_KEYS(KC_D, KC_I) {
            SEND_STRING(" required this.child, ");
            tap_code16(_FORMA_);
        }
        SEQ_TWO_KEYS(KC_D, KC_DOT) {
            SEND_STRING("child: child, ");
            tap_code16(_FORMA_);
        }
    }
}
#endif

// current os
//
// set to desired os
// uint8_t current_os = OS_OSX;

#ifdef CUSTOM_SWAPPER_ENABLE
bool sw_win_active  = false;
bool sw_lang_active = false;
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
bool pimoroni_scroll = true;
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    if (record->event.pressed) {
        uprintf("0x%04X,%u,%u,%u\n", keycode, record->event.key.row, record->event.key.col, get_highest_layer(layer_state));
    }
#endif

#ifdef CUSTOM_SWAPPER_ENABLE
    if (keycode == _ALTTB_ || keycode == _LFTAT_) {
        update_swapper(&sw_win_active, KC_LCMD, KC_TAB, _SWWIN_, _SWWIN_, record);
    } else {
        update_swapper(&sw_win_active, KC_LCMD, KC_TAB, _SWWIN_, keycode, record);
    }
    // update_swapper(&sw_lang_active, KC_LSHIFT, KC_LOPT, _SWLNG_, keycode,
    // record);
#endif

#ifdef CUSTOM_REPEAT_ENABLE
    if (!process_repeat_last_key(keycode, record, __RPT__, _MONAV_)) {
        return false;
    }
#endif

    // process os swapping
    if (keycode == _SWOS__) {
        if (record->event.pressed) {
            update_os();
            // remove
            switch(current_os) {
                case OS_OSX:
                     SEND_STRING("osx");
                     break;
                case OS_WIN:
                    SEND_STRING("win");
                    break;
                case OS_UBU:
                    SEND_STRING("ubuntu");
                    break;
            }
            return false;
        }
    }


    // TODO : replace send string with tap_code to save space
    switch (keycode) {
        #ifdef LEADER_ENABLE
        case _L_MIR_:
            if (record->event.pressed && record->tap.count) {
                qk_leader_start();
                return false;
            }
            break;
        #endif

        // bottom/top in LT
        case LT(UTIL_2, KC_F15):
            if (record->event.pressed && record->tap.count) {
                SEND_STRING(SS_LCMD(SS_TAP(X_UP)));
                return false;
            }
            break;
        case LT(UTIL_3, KC_F16):
            if (record->event.pressed && record->tap.count) {
                SEND_STRING(SS_LCMD(SS_TAP(X_DOWN)));
                return false;
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

        case _OUTLK_:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "out" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            return false;

        case _MUSIC_:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "mus" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            return false;

        case _VSCDE_:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "vsc" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            return false;

        case _ANDST_:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "and" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            return false;

        case _BRWSR_:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(" ") SS_DELAY(100) "edg" SS_DELAY(100) SS_TAP(X_ENTER));
            }
            return false;

        // double click
        case _MB1X2_:
            if (record->event.pressed) {
                register_code(KC_MS_BTN1);
                unregister_code(KC_MS_BTN1);
                register_code(KC_MS_BTN1);
                unregister_code(KC_MS_BTN1);
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

#ifdef PIMORONI_TRACKBALL_ENABLE
        // pimoroni toggle scroll
        case _PSCRL_:
            if (record->event.pressed) {
            } else {
                pimoroni_scroll = !pimoroni_scroll;
            }
            return true;
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

#ifdef CUSTOM_CAPS_WORD_ENABLE
    process_caps_word(keycode, record);
#endif

#ifdef CUSTOM_ONESHOT_ENABLE
    int8_t keycode_consumed = 0;
    keycode_consumed += update_oneshot_modifiers(keycode, record, keycode_consumed);
#endif

    return true;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _NAV, _SYM, _NUM);
// }

#ifdef PIMORONI_TRACKBALL_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (pimoroni_scroll) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}
#endif
