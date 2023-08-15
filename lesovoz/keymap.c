/* Copyright 2022 Caleb Lightfoot
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

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
//----------+---------+---------//
    BASE_L1      ,      BASE_R1 ,
    BASE_L2      ,      BASE_R2 ,
    BASE_L3      ,      BASE_R3 ,
//----------+---------+---------//
    _TAB_L_ , _TAB_R_ , 
    BASExLT , BASEx_L , 
    BASEx_R , BASExRT , 
    _PG_UP_ , _PGDWN_
//---------+---------//
    ),

    [_NAV] = LAYOUT(
//----------+---------+---------//
    NAV_L1      ,      NAV_R1 ,
    NAV_L2      ,      NAV_R2 ,
    NAV_L3      ,      NAV_R3 ,
//----------+---------+---------//
    _______ , _______ ,
    NAVx_LT , NAVx__L , 
    NAVx__R , NAVx_RT , 
    _______ , _______ 
//---------+---------//
    ),

    [_SYM] = LAYOUT(
//----------+---------+---------//
    SYM__L2      ,      SYM__R2 ,
    SYM__L1      ,      SYM__R1 ,
    SYM__L3      ,      SYM__R3 ,
//----------+---------+---------//
    _______ , _______ ,
    SYMx_LT , SYMx__L , 
    SYMx__R , SYMx_RT , 
    _______ , _______ 
//---------+---------//
    ),

    [_NUM] =  LAYOUT(
//----------+---------+---------//
    NUM__L1      ,      NUM__R1 ,
    NUM__L2      ,      NUM__R2 ,
    NUM__L3      ,      NUM__R3 ,
//----------+---------+---------//
    _______ , _______ ,
    NUMx_LT , NUMx__L , 
    NUMx__R , NUMx_RT , 
    _______ , _______ 
//---------+---------//
    ),
  
    [_GUI] =  LAYOUT(
//----------+---------+---------//
    GUI__L1      ,      GUI__R1 , 
    GUI__L2      ,      GUI__R2 ,
    GUI__L3      ,      GUI__R3 ,
//----------+---------+---------//
    _______ , _______ ,
    GUIx_LT , GUIx__L , 
    GUIx__R , GUIx_RT , 
    _______ , _______
//---------+---------//
    ),

    [_META] =  LAYOUT(
//----------+---------+---------//
    META_L1      ,      META_R1 ,
    META_L2      ,      META_R2 ,
    META_L3      ,      META_R3 ,
//----------+---------+---------//
    _______ , _______ ,
    METAxLT , METAx_L , 
    METAx_R , METAxRT , 
    _______ , _______
//---------+---------//
    ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}