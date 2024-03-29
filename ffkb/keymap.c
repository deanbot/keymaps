#include "deanbot.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

#include QMK_KEYBOARD_H

// clang-format off

// Blank thumb cluster
#define BLANKx_  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______

#define LAYOUT_ffkb_wrapper(...)       LAYOUT_ffkb(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   BOUT_L1 , BASE_L1           ,           BASE_R1 , BOUT_R1 ,
   BOUT_L2 , BASE_L2           ,           BASE_R2 , BOUT_R2 ,
   BOUT_L3 , BASE_L3           ,           BASE_R3 , BOUT_R3 ,
//---------+---------                     ---------+---------//
   BASExLQ , BASEx_L , BASExLT , BASExRT , BASEx_R , BASExRQ ,
   _______
//---------+---------//
),

[_NAV] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , NAV__L1           ,           NAV__R1 , _______ ,
   _______ , NAV__L2           ,           NAV__R2 , _______ ,
   _______ , NAV__L3           ,           NAV__R3 , _______ ,
//---------+---------                     ---------+---------//
   NAVx_LQ , NAVx__L , NAVx_LT , NAVx_RT , NAVx__R , NAVx_RQ ,
   _______
//---------+---------//
),

[_SYM] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , SYM__L1           ,           SYM__R1 , _______ ,
   _______ , SYM__L2           ,           SYM__R2 , _______ ,
   _______ , SYM__L3           ,           SYM__R3 , _______ ,
//---------+---------                     ---------+---------//
   _______ , SYMx__L , SYMx_LT , SYMx_RT , SYMx__R , _______ ,
   _______
//---------+---------//
),

[_NUM] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , NUM__L1           ,           NUM__R1 , _______ ,
   _______ , NUM__L2           ,           NUM__R2 , _______ ,
   _______ , NUM__L3           ,           NUM__R3 , _______ ,
//---------+---------                     ---------+---------//
   BLANKx_ ,
   _______
//---------+---------//
),

[_GUI] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , GUI__L1           ,           GUI__R1 , _______ ,
   _______ , GUI__L2           ,           GUI__R2 , _______ ,
   _______ , GUI__L3           ,           GUI__R3 , _______ ,
//---------+---------                     ---------+---------//
   GUIx_LQ , GUIx__L , GUIx_LT , GUIx_RT , GUIx__R , GUIx_RQ ,
   _______
//---------+---------//
),

[_MSE] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , MSE__L1           ,           MSE__R1 , _______ ,
   _______ , MSE__L2           ,           MSE__R2 , _______ ,
   _______ , MSE__L3           ,           MSE__R3 , _______ ,
//---------+---------                      ---------+---------//
   MSEx_LQ , MSEx__L , MSEx_LT , _______ , MSEx__R , MSEx_RQ ,
   _______
//---------+---------//
),

[_DBG] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , DBG__L1           ,           DBG__R1 , _______ ,
   _______ , DBG__L2           ,           DBG__R2 , _______ ,
   _______ , DBG__L3           ,           DBG__R3 , _______ ,
//---------+---------                     ---------+---------//
   _______ , DBGx__L , _______ , _______ , DBGx__R , _______ ,
   _______
//---------+---------//
),

[_META] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , META_L1           ,           META_R1 , _______ ,
   _______ , META_L2           ,           META_R2 , _______ ,
   _______ , META_L3           ,           META_R3 , _______ ,
//---------+---------                     ---------+---------//
   BLANKx_ ,
   _______
//---------+---------//
),

};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // default behavior if undefined
    if (index == 0) {
        if (clockwise) {
            switch (biton32(layer_state)) {
                case _GUI:
                    tap_code16(_MWDWN_);
                    break;
                case _SYM:
                    tap_code16(_REDO__);
                    break;
                default:
                    tap_code(KC_VOLU);
                    break;
            }
        } else {
            switch (biton32(layer_state)) {
                case _GUI:
                    tap_code16(_MWUP__);
                    break;
                case _SYM:
                    tap_code16(_UNDO__);
                    break;
                default:
                    tap_code(KC_VOLD);
                    break;
            }
        }
    } else if (index == 1) {
        if (clockwise) {
            switch (biton32(layer_state)) {
                case _NAV:
                    tap_code(KC_PGDN);
                    break;
                default:
                    tap_code(_BRUP__);
                    break;
            }
        } else {
            switch (biton32(layer_state)) {
                case _NAV:
                    tap_code(KC_PGUP);
                    break;
                default:
                    tap_code(_BRDWN_);
                    break;
            }
        }
    } else if (index == 3) {
        // center feature
        if (clockwise) {
            switch (biton32(layer_state)) {
                default:
                    tap_code16(_REDO__);
                    break;
            }
        } else {
            switch (biton32(layer_state)) {
                default:
                    tap_code16(_UNDO__);
                    break;
            }
        }
    }

    return true;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}
