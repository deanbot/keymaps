#include <stdint.h>
#include "config.h"
#include "process_combo.h"
#include "keycodes.h"

enum combos {
	COMMADOT_ENTER,
	HCOMMA_TAB,
	HSCOLON_ESC,
  WQ_CMD_Q,
  JL_CMD_W,

  MB1,
  MB2,
  MWD,
  MWU,

  FINDF,
  TERM,
  PROJ,

  CAPSW,

	COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM enter_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_H, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM wq_cmd_q_combo[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM jl_cmd_w_combo[] = {KC_J, KC_L, COMBO_END};

const uint16_t PROGMEM navat_mb1_combo[] = {_MONAV_, KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM navag_mb2_combo[] = {_MONAV_, KC_A, KC_G, COMBO_END};
const uint16_t PROGMEM dv_mwd_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM pb_mwu_combo[] = {KC_P, KC_B, COMBO_END};

const uint16_t PROGMEM kh_capsw_combo[] = {KC_K, KC_H, COMBO_END};
const uint16_t PROGMEM fscolon_findf_combo[] = {KC_F, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM tscolon_term_combo[] = {KC_T, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM pscolon_proj_combo[] = {KC_P, KC_SCOLON, COMBO_END};

combo_t key_combos[] = {
  [COMMADOT_ENTER] = COMBO(enter_combo, KC_ENTER),
  [HCOMMA_TAB] = COMBO(tab_combo, KC_TAB),
  [HSCOLON_ESC] = COMBO(esc_combo, KC_ESCAPE),
  [WQ_CMD_Q] = COMBO(wq_cmd_q_combo, _CMD_Q_),
  [JL_CMD_W] = COMBO(jl_cmd_w_combo, _CMD_W_),

  [TERM] = COMBO(tscolon_term_combo, _TERM__),
  [FINDF] = COMBO(fscolon_findf_combo, _FINDF_),
  [PROJ] = COMBO(pscolon_proj_combo, _PROJ__),

  [CAPSW] = COMBO(kh_capsw_combo, _CAPSW_),

  [MB1] = COMBO(navat_mb1_combo, _C_MB1_),
  [MB2] = COMBO(navag_mb2_combo, _C_MB2_),
  [MWD] = COMBO(dv_mwd_combo, _C_MWD_),
  [MWU] = COMBO(pb_mwu_combo, _C_MWU_),
};

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case GT_MB1:
//       if (pressed) {
//         register_code(KC_MS_BTN1);
//         unregister_code(KC_MS_BTN1);
//         // tap_code16(LCTL(KC_C));
//       }
//       break;
//     // case XV_PASTE:
//     //   if (pressed) {
//     //     tap_code16(LCTL(KC_V));
//     //   }
//     //   break;
//   }
// }
