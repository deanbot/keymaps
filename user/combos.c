#include <stdint.h>
#include "config.h"
#include "process_combo.h"
#include "keycodes.h"

enum combos {
	ENTER,
	TAB,
  STAB,
	ESC,
  BSPACE,
  UNDO,
  REDO,

  SAVE,
  FIND,

  QUIT,
  CLOSE,
  HIDE,
  HUD,

  DUPL,
  FINDF,
  GOTOS,
  GOTOD,
  NEWF,
  FORMAT,
  SORTI,
  RNAME,
  TERM,
  PROJ,
  REPL,

  TABL,
  TABR,
  PRTSC,

  DISCO,
  SLACK,
  TEAMS,

  MB1,
  MB2,
  MWD,
  MWU,

  REQ,
  FIN,

	COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM enter_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM stab_combo[] = {KC_H, KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_H, KC_SCOLON, COMBO_END};
// const uint16_t PROGMEM bspace_combo[] = {KC_N, KC_I, COMBO_END};
const uint16_t PROGMEM undo_combo[] = {KC_G, KC_V, COMBO_END};
const uint16_t PROGMEM redo_combo[] = {KC_M, KC_K, COMBO_END};

const uint16_t PROGMEM save_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM find_combo[] = {KC_F, KC_P, COMBO_END};

const uint16_t PROGMEM quit_combo[] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM close_combo[] = {KC_QUOT, KC_O, COMBO_END};
const uint16_t PROGMEM hide_combo[] = {KC_O, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM hud_combo[] = {KC_A, KC_Z, COMBO_END};

const uint16_t PROGMEM dupl_combo[] = {KC_T, KC_D, COMBO_END};
const uint16_t PROGMEM findf_combo[] = {KC_P, KC_T, COMBO_END};
const uint16_t PROGMEM gotos_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM gotod_combo[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM format_combo[] = {KC_L, KC_N, COMBO_END};
const uint16_t PROGMEM sorti_combo[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM rname_combo[] = {KC_N, KC_H, COMBO_END};
const uint16_t PROGMEM newf_combo[] = {KC_G, KC_N, COMBO_END};
const uint16_t PROGMEM term_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM proj_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM repl_combo[] = {KC_L, KC_U, COMBO_END};

// const uint16_t PROGMEM tabl_combo[] = {KC_J, KC_M, COMBO_END};
// const uint16_t PROGMEM tabr_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM prtsc_combo[] = {KC_P, KC_SCOLON, COMBO_END};

const uint16_t PROGMEM disco_combo[] = {KC_D, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM slack_combo[] = {KC_V, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM teams_combo[] = {KC_G, KC_SCOLON, COMBO_END};

const uint16_t PROGMEM navat_mb1_combo[] = {_MONAV_, KC_A, KC_T, COMBO_END};
const uint16_t PROGMEM navag_mb2_combo[] = {_MONAV_, KC_A, KC_G, COMBO_END};
const uint16_t PROGMEM dv_mwd_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM pb_mwu_combo[] = {KC_P, KC_B, COMBO_END};

const uint16_t PROGMEM req_combo[] = {KC_Q, KC_E, COMBO_END};
const uint16_t PROGMEM fin_combo[] = {KC_F, KC_N, COMBO_END};

combo_t key_combos[] = {
    [ENTER] = COMBO(enter_combo, KC_ENTER),
    [TAB] = COMBO(tab_combo, KC_TAB),
    [STAB] = COMBO(stab_combo, _STAB__),
    [ESC] = COMBO(esc_combo, KC_ESCAPE),
    // [BSPACE] = COMBO(bspace_combo, KC_BSPACE),
    [UNDO] = COMBO(undo_combo, _UNDO__),
    [REDO] = COMBO(redo_combo, _REDO__),

    // basic
    [SAVE] = COMBO(save_combo, _SAVE__),
    [FIND] = COMBO(find_combo, _FIND__),

    // window
    [QUIT] = COMBO(quit_combo, _QUIT__),
    [CLOSE] = COMBO(close_combo, _CLOSE_),
    [HIDE] = COMBO(hide_combo, _CLOSE_),
    [HUD] = COMBO(hud_combo, __HUD__),

    // ide
    [DUPL] = COMBO(dupl_combo, __DUP__),
    [REPL] = COMBO(repl_combo, _REPL__),
    [FINDF] = COMBO(findf_combo, _FINDF_),
    [GOTOS] = COMBO(gotos_combo, _GOTOS_),
    [GOTOD] = COMBO(gotod_combo, _GOTOD_),
    [FORMAT] = COMBO(format_combo, _FORMA_),
    [SORTI] = COMBO(sorti_combo, _SORTI_),
    [RNAME] = COMBO(rname_combo, _RNAME_),
    [NEWF] = COMBO(newf_combo, _NEWFL_),
    [PROJ] = COMBO(proj_combo, _PROJ__),
    [TERM] = COMBO(term_combo, _TERM__),

    // misc
    // [TABL] = COMBO(tabl_combo, _TAB_L_),
    // [TABR] = COMBO(tabr_combo, _TAB_R_),
    [PRTSC] = COMBO(prtsc_combo, _PRTSC_),

    // apps
    [DISCO] = COMBO(disco_combo, _DISCO_),
    [SLACK] = COMBO(slack_combo, _SLACK_),
    [TEAMS] = COMBO(teams_combo, _TEAMS_),

    // mouse keys
    [MB1] = COMBO(navat_mb1_combo, _C_MB1_),
    [MB2] = COMBO(navag_mb2_combo, _C_MB2_),
    [MWD] = COMBO(dv_mwd_combo, _C_MWD_),
    [MWU] = COMBO(pb_mwu_combo, _C_MWU_),

    // words
    [REQ] = COMBO(req_combo, _REQU__),
    [FIN] = COMBO(fin_combo, __FIN__),
};
