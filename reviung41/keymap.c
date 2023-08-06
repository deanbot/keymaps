/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "deanbot.h"

#ifdef COMBO_ENABLE
#include "g/keymap_combo.h"
#endif

#include QMK_KEYBOARD_H

#define LAYOUT_REV(...)       LAYOUT(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_REV(
//----------+---------+---------+---------+---------//
    BOUT_L1 , BASE_L1      ,      BASE_R1 , BOUT_R1 ,
    BOUT_L2 , BASE_L2      ,      BASE_R2 , BOUT_R2 ,
    BOUT_L3 , BASE_L3      ,      BASE_R3 , BOUT_R3 ,
//----------+---------+----*----+---------+---------//
              BASEx_L , BASExLT , BASEx_R
           //---------+----*----,---------//
    ),
    
    [_NAV] = LAYOUT_REV(
//----------+---------+---------+---------+---------//
    _______ , NAV__L1      ,      NAV__R1 , _______ ,
    _______ , NAV__L2      ,      NAV__R2 , _______ ,
    _______ , NAV__L3      ,      NAV__R3 , _______ ,
//----------+---------+----*----+---------+---------//
              NAVx__L , NAVx_LT , NAVx__R
           //---------+----*----,---------//
    ),

    [_SYM] = LAYOUT_REV(
//----------+---------+---------+---------+---------//
    _______ , SYM__L1      ,      SYM__R1 , _______ ,
    _______ , SYM__L2      ,      SYM__R2 , _______ ,
    _______ , SYM__L3      ,      SYM__R3 , _______ ,
//----------+---------+----*----+---------+---------//
              SYMx__L , SYMx_LT , SYMx__R
           //---------+----*----,---------//
    ),

    [_NUM] = LAYOUT_REV(
//----------+---------+---------+---------+---------//
    _______ , NUM__L1      ,      NUM__R1 , _______ ,
    _______ , NUM__L2      ,      NUM__R2 , _______ ,
    _______ , NUM__L3      ,      NUM__R3 , _______ ,
//----------+---------+----*----+---------+---------//
              NUMx__L , NUMx_LT , NUMx__R
           //---------+----*----,---------//
    ),

    [_GUI] = LAYOUT_REV(
//----------+---------+---------+---------+---------//
    _______ , GUI__L1      ,      GUI__R1 , _______ ,
    _______ , GUI__L2      ,      GUI__R2 , _______ ,
    _______ , GUI__L3      ,      GUI__R3 , _______ ,
//----------+---------+----*----+---------+---------//
              GUIx__L , GUIx_LT , GUIx__R
           //---------+----*----,---------//
    ),

    [_META] = LAYOUT_REV(
//----------+---------+---------+---------+---------//
    _______ , META_L1      ,      META_R1 , _______ ,
    _______ , META_L2      ,      META_R2 , _______ ,
    _______ , META_L3      ,      META_R3 , _______ ,
//----------+---------+----*----+---------+---------//
              METAx_L , METAxLT , METAx_R
           //---------+----*----,---------//
    )
}; 
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}