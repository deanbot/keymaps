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

#define LAYOUT_ortho_4x10_wrapper(...)  LAYOUT_lesovoz(__VA_ARGS__)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_ortho_4x10_wrapper(
//----------+---------+---------//
    BASE_L1      ,      BASE_R1 ,
    BASE_L2      ,      BASE_R2 ,
    BASE_L3      ,      BASE_R3 ,
//----------+---------+---------//
    _PRTSF_ , __MB2__ , 
    BASEx_L , BASExLT ,
    BASExRT , BASEx_R ,  
    _PG_UP_ , _PGDWN_
//---------+---------//
    ),

    [_NAV] = LAYOUT_ortho_4x10_wrapper(
//----------+---------+---------//
    NAV__L1      ,      NAV__R1 ,
    NAV__L2      ,      NAV__R2 ,
    NAV__L3      ,      NAV__R3 ,
//----------+---------+---------//
    _______ , _______ ,
    NAVx__L , NAVx_LT ,  
    NAVx_RT , NAVx__R ,  
    _______ , _______
//---------+---------//
    ),

    [_SYM] = LAYOUT_ortho_4x10_wrapper(
//----------+---------+---------//
    SYM__L1      ,      SYM__R1 ,
    SYM__L2      ,      SYM__R2 ,
    SYM__L3      ,      SYM__R3 ,
//----------+---------+---------//
    _______ , _______ ,
    SYMx__L , SYMx_LT ,  
    SYMx_RT , SYMx__R ,  
    _______ , _______ 
//---------+---------//
    ),

    [_NUM] =  LAYOUT_ortho_4x10_wrapper(
//----------+---------+---------//
    NUM__L1      ,      NUM__R1 ,
    NUM__L2      ,      NUM__R2 ,
    NUM__L3      ,      NUM__R3 ,
//----------+---------+---------//
    _______ , _______ ,
    NUMx__L , NUMx_LT ,  
    NUMx_RT , NUMx__R ,  
    _______ , _______ 
//---------+---------//
    ),
  
    [_GUI] =  LAYOUT_ortho_4x10_wrapper(
//----------+---------+---------//
    GUI__L1      ,      GUI__R1 , 
    GUI__L2      ,      GUI__R2 ,
    GUI__L3      ,      GUI__R3 ,
//----------+---------+---------//
    _______ , _______ ,
    GUIx__L , GUIx_LT ,  
    GUIx_RT , GUIx__R ,  
    _______ , _______
//---------+---------//
    ),

    [_META] =  LAYOUT_ortho_4x10_wrapper(
//----------+---------+---------//
    META_L1      ,      META_R1 ,
    META_L2      ,      META_R2 ,
    META_L3      ,      META_R3 ,
//----------+---------+---------//
    _______ , _______ ,
    METAx_L , METAxLT ,  
    METAxRT , METAx_R ,  
    _______ , _______
//---------+---------//
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}