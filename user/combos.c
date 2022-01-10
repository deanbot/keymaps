#include <stdint.h>
#include "config.h"
#include "process_combo.h"
#include "keycodes.h"

enum combos {
	COMMADOT_ENTER,
	HCOMMA_TAB,
	HSCOLON_ESC,
  WF_Q,
  UY_QUOTE,
	COMBO_LENGTH
};

const uint16_t PROGMEM enter_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_H, KC_SCOLON, COMBO_END};

const uint16_t PROGMEM kc_q_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM kc_quote_combo[] = {KC_U, KC_Y, COMBO_END};

combo_t key_combos[] = {
  [COMMADOT_ENTER] = COMBO(enter_combo, KC_ENTER),
  [HCOMMA_TAB] = COMBO(tab_combo, KC_TAB),
  [HSCOLON_ESC] = COMBO(esc_combo, KC_ESCAPE),

  [WF_Q] = COMBO(kc_q_combo, KC_Q),
  [UY_QUOTE] = COMBO(kc_quote_combo, KC_QUOTE),
};

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case ZC_COPY:
//       if (pressed) {
//         tap_code16(LCTL(KC_C));
//       }
//       break;
//     case XV_PASTE:
//       if (pressed) {
//         tap_code16(LCTL(KC_V));
//       }
//       break;
//   }
// }

// uint16_t COMBO_LEN = COMBO_LENGTH;
