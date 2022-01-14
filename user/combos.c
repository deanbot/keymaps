#include <stdint.h>
#include "config.h"
#include "process_combo.h"
#include "keycodes.h"

enum combos {
	COMMADOT_ENTER,
	HCOMMA_TAB,
	HSCOLON_ESC,

  SAVE,
  FIND,

  QUIT,
  CLOSE,
  HIDE,

  CAPSW,

  DUPL,
  TERM,
  PROJ,
  FINDF,
  GOTOS,
  FORMAT,

  DISCO,

  MB1,
  MB2,
  MWD,
  MWU,

	COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM enter_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_H, KC_SCOLON, COMBO_END};

const uint16_t PROGMEM save_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM find_combo[] = {KC_F, KC_P, COMBO_END};

const uint16_t PROGMEM quit_combo[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM close_combo[] = {KC_J, KC_L, COMBO_END};

const uint16_t PROGMEM capsw_combo[] = {KC_N, KC_H, COMBO_END};

const uint16_t PROGMEM dupl_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM term_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM proj_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM findf_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM gotos_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM format_combo[] = {KC_F, KC_H, COMBO_END};

const uint16_t PROGMEM disco_combo[] = {KC_D, KC_H, COMBO_END};

const uint16_t PROGMEM navat_mb1_combo[] = {_MONAV_, KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM navag_mb2_combo[] = {_MONAV_, KC_A, KC_G, COMBO_END};
const uint16_t PROGMEM dv_mwd_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM pb_mwu_combo[] = {KC_P, KC_B, COMBO_END};

combo_t key_combos[] = {
    [COMMADOT_ENTER] = COMBO(enter_combo, KC_ENTER),
    [HCOMMA_TAB] = COMBO(tab_combo, KC_TAB),
    [HSCOLON_ESC] = COMBO(esc_combo, KC_ESCAPE),

    // basic
    [SAVE] = COMBO(save_combo, _SAVE__),
    [FIND] = COMBO(find_combo, _FIND__),

    // window
    [QUIT] = COMBO(quit_combo, _QUIT__),
    [CLOSE] = COMBO(close_combo, _CLOSE_),
    [HIDE] = COMBO(hide_combo, _CLOSE_),

    // custom
    [CAPSW] = COMBO(capsw_combo, _CAPSW_),

    // ide
    [DUPL] = COMBO(dupl_combo, __DUP__),
    [FINDF] = COMBO(findf_combo, _FINDF_),
    [GOTOS] = COMBO(gotos_combo, _GOTOS_),
    [FORMAT] = COMBO(format_combo, _FORMA_),
    [PROJ] = COMBO(proj_combo, _PROJ__),
    [TERM] = COMBO(term_combo, _TERM__),

    // apps
    [DISCO] = COMBO(disco_combo, _DISCO_),

    // mouse keys
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
