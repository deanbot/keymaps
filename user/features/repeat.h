#pragma once

#include QMK_KEYBOARD_H

uint16_t last_key;
uint16_t last_mods;

bool process_repeat_last_key(
    uint16_t keycode,
    keyrecord_t *record,
    uint16_t expected_keycode,
    uint16_t optional_layer_code);
