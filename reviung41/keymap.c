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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
//----------+---------+---------+---------+---------//
    BOUT_L1 , BASE_L1      ,      BASE_R1 , BOUT_R1 ,
    BOUT_L2 , BASE_L2      ,      BASE_R2 , BOUT_R2 ,
    BOUT_L3 , BASE_L3      ,      BASE_R3 , BOUT_R3 ,
//----------+---------+----*----+---------+---------//
              BASEx_L , BASExLT , BASEx_R
           //---------+----*----,---------//
    ),
}; 
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _SYM, _NUM);
}