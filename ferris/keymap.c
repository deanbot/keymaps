#include QMK_KEYBOARD_H

#include "deanbot.h"

// clang-format off

/**
  [VOID] = LAYOUT(
//---------+---------+---------+---------+---------                     ---------+---------+---------+---------+---------//
   _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ ,
//---------+---------+---------+---------+---------                     ---------+---------+---------+---------+---------//
   _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ ,
//---------+---------+---------+---------+---------                     ---------+---------+---------+---------+---------//
   _______ , _______ , _______ , _______ , _______           ,           _______ , _______ , _______ , _______ , _______ ,
//---------+---------+---------+---------+---------                     ---------+---------+---------+---------+---------//
                               , _______ , _______           ,           _______ , _______
                              //---------+---------+---------+---------+---------+---------//
  ),
**/

#define _____BLANKx______  _______ , _______ , _______ , _______
#define MOUSxLf  _______ , __MB1__

#define LAYOUT_ferris(...)       LAYOUT(__VA_ARGS__)

cons t uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

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

[_MOUSE] = LAYOUT_ferris(
//---------                     ---------//
   MOUS_L1           ,           MOUS_R1 ,
   MOUS_L2           ,           MOUS_R2 ,
   MOUS_L3           ,           MOUS_R3 ,
//---------                     ---------//
             MOUSxLf , MOUSx_R
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
