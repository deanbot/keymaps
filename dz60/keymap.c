#include "deanbot.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

#include QMK_KEYBOARD_H

#define LAYOUT_DZ(...)       LAYOUT_all(__VA_ARGS__)

// clang-format off

#define BASE_L0 ___1___ , ___2___ , ___3___ , ___4___ , ___5___
#define BASE_R0 ___6___ , ___7___ , ___8___ , ___9___ , ___0___
#define BASE_RP _MINUS_ , _EQUAL_ , _TILDE_ , __DEL__
#define BASEBRC _LCBRC_ , _RCBRC_ , _BKSPC_
#define BASENAV _LEFT__ , _DOWN__ , __UP___ , _RIGHT_
#define BLANK_3 _______ , _______ , _______
#define BLANK_4 _______ , _______ , _______ , _______
#define BLANK_5 _______ , _______ , _______ , _______ , _______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {    

[_BASE] = LAYOUT_DZ(
//---------+---------+---------+---------+---------+---------//
   __ESC__ , BASE_L0 ,                     BASE_R0 , BASE_RP ,
   __TAB__ , BASE_L1 , __VUP__ ,           BASE_R1 , BASEBRC ,
   _BKSPC_ , BASE_L2 , _VDWN__ ,           BASE_R2 , _ENTER_ ,
   _LOPT__ , BASE_L3 , __MB2__ , __MB3__ , BASE_R3 , BASExRT ,
   _LCTL__ , _LCMD__ , BASEx_L , BASExLT , BASEx_R , BASENAV
//---------+---------+---------+----*----+---------+---------//
),

[_NAV] = LAYOUT_DZ(
//---------+---------+---------+---------+---------+---------//
   _______ , BLANK_5 ,                     BLANK_5 , BLANK_4 ,
   _______ , NAV__L1 , _______ ,           NAV__R1 , BLANK_3 ,
   _______ , NAV__L2 , _______ ,           NAV__R2 , _______ ,
   _______ , NAV__L3 , _______ , _______ , NAV__R3 , NAVx_RT ,
   _______ , _______ , NAVx__L , NAVx_LT , NAVx__R , BLANK_4
//---------+---------+---------+---------+---------+---------//
),

[_SYM] = LAYOUT_DZ(
//---------+---------+---------+---------+---------+---------//
   _______ , BLANK_5 ,                     BLANK_5 , BLANK_4 ,
   _______ , SYM__L1 , _______ ,           SYM__R1 , BLANK_3 ,
   _______ , SYM__L2 , _______ ,           SYM__R2 , _______ ,
   _______ , SYM__L3 , _______ , _______ , SYM__R3 , SYMx_RT ,
   _______ , _______ , SYMx__L , SYMx_LT , SYMx__R , BLANK_4
//---------+---------+---------+---------+---------+---------//
),

[_NUM] = LAYOUT_DZ(
//---------+---------+---------+---------+---------+---------//
   _______ , BLANK_5 ,                     BLANK_5 , BLANK_4 ,
   _______ , NUM__L1 , _______ ,           NUM__R1 , BLANK_3 ,
   _______ , NUM__L2 , _______ ,           NUM__R2 , _______ ,
   _______ , NUM__L3 , _______ , _______ , NUM__R3 , NUMx_RT ,
   _______ , _______ , NUMx__L , NUMx_LT , NUMx__R , BLANK_4
//---------+---------+---------+---------+---------+---------//
),

[_GUI] = LAYOUT_DZ(
//---------+---------+---------+---------+---------+---------//
   _______ , BLANK_5 ,                     BLANK_5 , BLANK_4 ,
   _______ , GUI__L1 , _______ ,           GUI__R1 , BLANK_3 ,
   _______ , GUI__L2 , _______ ,           GUI__R2 , _______ ,
   _______ , GUI__L3 , _______ , _______ , GUI__R3 , GUIx_RT ,
   _______ , _______ , GUIx__L , GUIx_LT , GUIx__R , BLANK_4
//---------+---------+---------+---------+---------+---------//
),

[_MSE] = LAYOUT_DZ(
//---------+---------+---------+---------+---------+---------//
   _______ , BLANK_5 ,                     BLANK_5 , BLANK_4 ,
   _______ , MSE__L1 , _______ ,           MSE__R1 , BLANK_3 ,
   _______ , MSE__L2 , _______ ,           MSE__R2 , _______ ,
   _______ , MSE__L3 , _______ , _______ , MSE__R3 , MSEx_RT ,
   _______ , _______ , MSEx__L , MSEx_LT , MSEx__R , BLANK_4
//---------+---------+---------+---------+---------+---------//
),

[_DBG] = LAYOUT_DZ(
//---------+---------+---------+---------+---------+---------//
   _______ , BLANK_5 ,                     BLANK_5 , BLANK_4 ,
   _______ , DBG__L1 , _______ ,           DBG__R1 , BLANK_3 ,
   _______ , DBG__L2 , _______ ,           DBG__R2 , _______ ,
   _______ , DBG__L3 , _______ , _______ , DBG__R3 , DBGx_RT ,
   _______ , _______ , DBGx__L , DBGx_LT , DBGx__R , BLANK_4
//---------+---------+---------+---------+---------+---------//
),

[_META] = LAYOUT_DZ(
//---------+---------+---------+---------+---------+---------//
   _______ , BLANK_5 ,                     BLANK_5 , BLANK_4 ,
   _______ , META_L1 , _______ ,           META_R1 , BLANK_3 ,
   _______ , META_L2 , _______ ,           META_R2 , _______ ,
   _______ , META_L3 , _______ , _______ , META_R3 , METAxRT ,
   _______ , _______ , METAx_L , METAxLT , METAx_R , BLANK_4
//---------+---------+---------+---------+---------+---------//
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}
