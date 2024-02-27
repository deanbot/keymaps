#include "deanbot.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

#include QMK_KEYBOARD_H

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
  ),
**/

#define _____BLANKx______  _______ , _______ , _______ , _______

#define LAYOUT_ferris(...)       LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ferris(
//---------                     ---------//
   BASE_L1           ,           BASE_R1 ,
   BASE_L2           ,           BASE_R2 ,
   BASE_L3           ,           BASE_R3 ,
//---------                     ---------//
             BASEx_L , BASEx_R
          //---------+---------//
),

[_NAV] = LAYOUT_ferris(
//---------                     ---------//
   NAV__L1           ,           NAV__R1 ,
   NAV__L2           ,           NAV__R2 ,
   NAV__L3           ,           NAV__R3 ,
//---------                     ---------//
             NAVx__L , NAVx__R
          //---------+---------//
),

[_SYM] = LAYOUT_ferris(
//---------                     ---------//
   SYM__L1           ,           SYM__R1 ,
   SYM__L2           ,           SYM__R2 ,
   SYM__L3           ,           SYM__R3 ,
//---------                     ---------//
             SYMx__L , SYMx__R
          //---------+---------//
),

[_NUM] = LAYOUT_ferris(
//---------                     ---------//
   NUM__L1           ,           NUM__R1 ,
   NUM__L2           ,           NUM__R2 ,
   NUM__L3           ,           NUM__R3 ,
//---------                     ---------//
             _____BLANKx______
          //---------+---------//
),

[_GUI] = LAYOUT_ferris(
//---------                     ---------//
   GUI__L1           ,           GUI__R1 ,
   GUI__L2           ,           GUI__R2 ,
   GUI__L3           ,           GUI__R3 ,
//---------                     ---------//
             GUIx__L , GUIx__R
          //---------+---------//
),

[_META] = LAYOUT_ferris(
//---------                     ---------//
   META_L1           ,           META_R1 ,
   META_L2           ,           META_R2 ,
   META_L3           ,           META_R3 ,
//---------                     ---------//
             _____BLANKx______
          //---------+---------//
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}