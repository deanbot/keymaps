#include "deanbot.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

#include QMK_KEYBOARD_H

#define BLANKx_ _______ , _______ , _______ , _______ , _______ , _______ , _______

#define LAYOUT_INFERNUM(...)    LAYOUT(__VA_ARGS__)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_INFERNUM(
//---------+---------+----*----+---------+---------//
   BASE_L1           , KC_MUTE ,           BASE_R1 ,
   BASE_L2                ,                BASE_R2 ,
   BASE_L3                ,                BASE_R3 ,
//---------+---------+----*----+---------+---------//
   _LOPT__ , BASEx_L , BASExLT , BASEx_R , BASExRT
//---------+---------+----*----+---------+---------//
),

[_NAV] = LAYOUT_INFERNUM(
//---------+---------+----*----+---------+---------//
   NAV__L1           , _______ ,           NAV__R1 ,
   NAV__L2                ,                NAV__R2 ,
   NAV__L3                ,                NAV__R3 ,
//---------+---------+----*----+---------+---------//
   NAVx_LT , NAVx__L , _______ , NAVx__R , NAVx_RT
//---------+---------+----*----+---------+---------//
),

[_SYM] = LAYOUT_INFERNUM(
//---------+---------+----*----+---------+---------//
   SYM__L1           , _______ ,           SYM__R1 ,
   SYM__L2                ,                SYM__R2 ,
   SYM__L3                ,                SYM__R3 ,
//---------+---------+----*----+---------+---------//
   SYMx_LT , SYMx__L , _______ , SYMx__R , SYMx_RT
//---------+---------+----*----+---------+---------//
),

[_NUM] = LAYOUT_INFERNUM(
//---------+---------+----*----+---------+---------//
   NUM__L1           , _______ ,           NUM__R1 ,
   NUM__L2                ,                NUM__R2 ,
   NUM__L3                ,                NUM__R3 ,
//---------+---------+----*----+---------+---------//
   NUMx_LT , NUMx__L , _______ , NUMx__R , NUMx_RT 
//---------+---------+----*----+---------+---------//
),

[_GUI] = LAYOUT_INFERNUM(
//---------+---------+----*----+---------+---------//
   GUI__L1           , _______ ,           GUI__R1 ,
   GUI__L2                ,                GUI__R2 ,
   GUI__L3                ,                GUI__R3 ,
//---------+---------+----*----+---------+---------//
   GUI_xL3           , _______ ,           GUI_xR3
//---------+---------+----*----+---------+---------//
),

[_DBG] = LAYOUT_INFERNUM(
//---------+---------+----*----+---------+---------//
   DBG__L1           , _______ ,           DBG__R1 ,
   DBG__L2                ,                DBG__R2 ,
   DBG__L3                ,                DBG__R3 ,
//---------+---------+----*----+---------+---------//
   GUIx_LT , GUIx__L , _______ , GUIx__R , GUIx_RT
//---------+---------+----*----+---------+---------//
),

[_META] = LAYOUT_INFERNUM(
//---------+---------+----*----+---------+---------//
   META_L1           , _______ ,           META_R1 ,
   META_L2                ,                META_R2 ,
   META_L3                ,                META_R3 ,
//---------+---------+----*----+---------+---------//
   METAxLT , METAx_L , _______ , METAx_R , METAxRT
//---------+---------+----*----+---------+---------//
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
// Encoder 1 , Encoder 2
[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
[1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
[2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
[3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
[4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
[5] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
[6] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
[7] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
};
#endif