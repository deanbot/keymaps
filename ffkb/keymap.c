#include QMK_KEYBOARD_H

#include "deanbot.h"
#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

// clang-format off

/**
  [VOID] = LAYOUT(
//---------+---------+---------+---------+---------                     ---------+---------+---------+---------+---------//
   _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ ,
//---------+---------+---------+---------+---------                     ---------+---------+---------+---------+---------//
   _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ ,
//---------+---------+---------+---------+---------                     ---------+---------+---------+---------+---------//
   _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ ,
//---------+---------+---------+----*----+----*----                     ----*----+----*----+---------+---------+---------//
                                    , _______ , _______      ,      _______ , _______
                                   //---------+---------+---------+---------+---------//
**/

// Blank thumb cluster
#define BLANKx_  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
#define CENTERF_______ ,   _______ _______ ,

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

[_MIR] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   MIOUT_1 , MIR__L1           ,           MIR__R1 , MIOUT_1 ,
   MIOUT_2 , MIR__L2           ,           MIR__R2 , MIOUT_2 ,
   MIOUT_3 , MIR__L3           ,           MIR__R3 , MIOUT_3 ,
//---------+---------                     ---------+---------//
   BLANKx_ ,
   _______
//---------+---------//
),

[_NAV] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , NAV__L1           ,           NAV__R1 , _______ ,
   _______ , NAV__L2           ,           NAV__R2 , _______ ,
   _______ , NAV__L3           ,           NAV__R3 , _______ ,
//---------+---------                     ---------+---------//
   _______ , NAVx__L , _______ , _______ , NAVx__R , _______ ,
   _______
//---------+---------//
),

[_SYM] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , SYM__L1           ,           SYM__R1 , _______ ,
   _______ , SYM__L2           ,           SYM__R2 , _______ ,
   _______ , SYM__L3           ,           SYM__R3 , _______ ,
//---------+---------                     ---------+---------//
   _______ , SYMx__L , _______ , _______ , SYMx__R , _______ ,
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

[_DBG] = LAYOUT_ffkb_wrapper(
//---------+---------                     ---------+---------//
   _______ , DBG__L1           ,           DBG__R1 , _______ ,
   _______ , DBG__L2           ,           DBG__R2 , _______ ,
   _______ , DBG__L3           ,           DBG__R3 , _______ ,
//---------+---------                     ---------+---------//
   _______ , _______ , DBGx__L , DBGx__R , _______ , _______ ,
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
        // Conditional to reverse the direction of encoder
        #ifdef ENCODERS_A_REVERSE
        if (!clockwise) {
        #else
        if (clockwise) {
        #endif
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
      // Conditional to reverse the direction of encoder
      #ifdef ENCODERS_B_REVERSE
      if (!clockwise) {
      #else
      if (clockwise) {
      #endif
        tap_code16(_BRUP__);
      }
      else{
        tap_code16(_BRDWN_);
      }
    } else if (index == 3) {
      // center feature
    }

    return true;
}
#endif
