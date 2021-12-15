#pragma once

// #include <stdint.h>
// #include <stdbool.h>
#include QMK_KEYBOARD_H

void caps_word_enable(void);
void caps_word_disable(void);
void caps_word_toggle(void);
void process_caps_word(uint16_t keycode, keyrecord_t *record);
