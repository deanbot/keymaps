#pragma once

#include "quantum.h"

enum layers
{
  _BASE,
  _FN,
  _NAV,
  _MOUSE,
  _SYM,
  _NUM,
  _META
};

enum keycodes
{
  _SEL_L_ = SAFE_RANGE,

  // ${} macro
  _STRIN_,

  // swapper
  _SWWIN_,
  _SWLNG_,

  // one shot
  _O_SFT_,
  _O_OPT_,
  _O_CMD_,
  _O_CTL_,

  // repeat
  __RPT__,

  // capsword
  _CAPSW_
};

#define _MONAV_ MO(_NAV)
#define _MOSYM_ MO(_SYM)
#define _MMETA_ MO(_META)
#define _SP_MK_ LT(_MOUSE, KC_SPACE)

#define ___A___ KC_A
#define ___B___ KC_B
#define ___C___ KC_C
#define ___D___ KC_D
#define ___E___ KC_E
#define ___F___ KC_F
#define ___G___ KC_G
#define ___H___ KC_H
#define ___I___ KC_I
#define ___J___ KC_J
#define ___K___ KC_K
#define ___L___ KC_L
#define ___M___ KC_M
#define ___N___ KC_N
#define ___O___ KC_O
#define ___P___ KC_P
#define ___Q___ KC_Q
#define ___R___ KC_R
#define ___S___ KC_S
#define ___T___ KC_T
#define ___U___ KC_U
#define ___V___ KC_V
#define ___W___ KC_W
#define ___X___ KC_X
#define ___Y___ KC_Y
#define ___Z___ KC_Z

#define ___0___ KC_0
#define ___1___ KC_1
#define ___2___ KC_2
#define ___3___ KC_3
#define ___4___ KC_4
#define ___5___ KC_5
#define ___6___ KC_6
#define ___7___ KC_7
#define ___8___ KC_8
#define ___9___ KC_9

#define __F1___ KC_F1
#define __F2___ KC_F2
#define __F3___ KC_F3
#define __F4___ KC_F4
#define __F5___ KC_F5
#define __F6___ KC_F6
#define __F7___ KC_F7
#define __F8___ KC_F8
#define __F9___ KC_F9
#define __F10__ KC_F10
#define __F11__ KC_F11
#define __F12__ KC_F12

#define _LEFT__ KC_LEFT
#define _DOWN__ KC_DOWN
#define __UP___ KC_UP
#define _RIGHT_ KC_RIGHT

#define _SPACE_ KC_SPACE
#define __TAB__ KC_TAB
#define _ENTER_ KC_ENTER
#define _BKSPC_ KC_BSPACE
#define __DEL__ KC_DELETE
#define __ESC__ KC_ESCAPE
#define _PGDWN_ KC_PGDOWN
#define _PG_UP_ KC_PGUP
#define _HOME__ KC_HOME
#define __END__ KC_END

#define _LSHFT_ KC_LSFT
#define _LCTL__ KC_LCTL
#define _LOPT__ KC_LOPT
#define _ROPT__ KC_ROPT
#define _LCMD__ KC_LCMD
#define _RSHFT_ KC_LSFT

#define _LPARN_ KC_LEFT_PAREN
#define _RPARN_ KC_RIGHT_PAREN
#define _LCBRC_ KC_LEFT_CURLY_BRACE
#define _RCBRC_ KC_RIGHT_CURLY_BRACE
#define _LBRAC_ KC_LBRACKET
#define _RBRAC_ KC_RBRACKET
#define _LABRC_ KC_LEFT_ANGLE_BRACKET
#define _RABRC_ KC_RIGHT_ANGLE_BRACKET
#define __DOT__ KC_DOT
#define _COMMA_ KC_COMMA
#define _SQUOT_ KC_QUOTE
#define _DQUOT_ KC_DOUBLE_QUOTE
#define _COLON_ KC_COLON
#define _SCOLN_ KC_SCOLON
#define _TILDE_ LSFT(KC_GRAVE)
#define _GRAVE_ KC_GRAVE
#define _UNDRS_ KC_UNDERSCORE
#define _EQUAL_ KC_EQUAL
#define _MINUS_ KC_MINUS
#define _PLUS__ KC_PLUS
#define _ASTER_ KC_ASTERISK
#define _HASH__ KC_HASH
#define _DOLLR_ KC_DOLLAR
#define _SLASH_ KC_SLASH
#define _BSLSH_ KC_BSLASH
#define _PERCT_ KC_PERCENT
#define _AMPRS_ KC_AMPERSAND
#define _QUEST_ KC_QUESTION
#define _EXCLM_ KC_EXCLAIM
#define _CIRCF_ KC_CIRCUMFLEX
#define _PIPE__ LSFT(KC_BSLS)
#define __AT___ KC_AT

#define _MLFT__ KC_MS_LEFT
#define _MDWN__ KC_MS_DOWN
#define __MUP__ KC_MS_UP
#define _MRGT__ KC_MS_RIGHT
#define _MWLFT_ KC_MS_WH_LEFT
#define _MWDWN_ KC_MS_WH_DOWN
#define _MWUP__ KC_MS_WH_UP
#define _MWRGT_ KC_MS_WH_RIGHT
#define __MB1__ KC_MS_BTN1
#define __MB2__ KC_MS_BTN2
#define __MB3__ KC_MS_BTN3

#define __PRV__ KC_MEDIA_PREV_TRACK
#define __NXT__ KC_MEDIA_NEXT_TRACK
#define __VUP__ KC_AUDIO_VOL_UP
#define _VDWN__ KC_AUDIO_VOL_DOWN
#define _MUTE__ KC_AUDIO_MUTE
#define _PLYPS_ KC_MEDIA_PLAY_PAUSE
#define _BRUP__ KC_BRIGHTNESS_UP
#define _BRDWN_ KC_BRIGHTNESS_DOWN
#define _SLEEP_ KC_SYSTEM_SLEEP
#define _RESET_ RESET

// workflow/app/browser
#define _PRTSC_ LCMD(LSFT(___4___))
#define _CMD_W_ LCMD(KC_W)
#define _COPY__ LCMD(KC_C)
#define __CUT__ LCMD(KC_X)
#define _UNDO__ LCMD(KC_Z)
#define _PASTE_ LCMD(KC_V)
#define _REDO__ LCMD(LSFT(KC_Z))
#define _N_TAB_ LCTL(KC_T)
#define _RETAB_ LSFT(LCTL(KC_T))
#define _N_WIN_ LCMD(KC_N)
#define _TAB_L_ LCTL(KC_PGUP)
#define _TAB_R_ LCTL(KC_PGDOWN)
#define _BSP_W_ LOPT(KC_BSPACE)
#define _DEL_W_ LOPT(KC_DELETE)
#define _BSP_L_ LCMD(KC_BSPACE)
#define _DEL_L_ LCMD(KC_DELETE)
#define _BEGLN_ LCMD(KC_LEFT)
#define _ENDLN_ LCMD(KC_RIGHT)
#define __TOP__ LCMD(KC_UP)
#define __BTM__ LCMD(KC_DOWN)
#define __HUD__ LCTL(KC_UP)
#define _TMSMU_ LCMD(LSFT(KC_M))
#define _INCOG_ LCMD(LSFT(KC_N))
#define _DEVT__ LCMD(LOPT(KC_I))
#define _SRCHW_ LCMD(LOPT(KC_F))
#define _SELAD_ LCMD(KC_L)
#define _JUMP__ LCMD(KC_K)
#define _BACK__ LCMD(KC_LBRACKET)
#define __FWD__ LCMD(KC_RBRACKET)
#define _ZOOMI_ LCMD(KC_PLUS)
#define _ZOOMO_ LCMD(KC_MINUS)
#define _ZOOMR_ LCMD(KC_0)
#define _SAVE__ LCMD(KC_S)
#define _SPOTL_ LCMD(KC_SPACE)
#define _CLALL_ LCMD(LSFT(KC_W))

// android studio
#define _HINT__ LCTL(KC_SPACE)
#define _TERM__ LALT(KC_F12)
#define _NEWFL_ LCMD(LOPT(KC_N))
#define _DRTAN_ LCMD(KC_SCOLON)
#define _PROJ__ LCMD(KC_1)
#define _DEBGR_ LCMD(KC_5)
#define _COMMT_ LCMD(KC_0)
#define _RNAME_ LSFT(KC_F6)
#define _COLS__ LCMD(LSFT(KC_8))
#define _FORMA_ LCMD(LOPT(KC_L))
#define __FIX__ LOPT(LSFT(KC_ENTER))
#define _FINDF_ LCMD(LSFT(KC_O))
#define _GOTOD_ LCMD(KC_B)
#define _GOTOE_ KC_F2
#define _HTRST_ LCMD(LSFT(KC_BSLASH))
#define _DEBUG_ LCTL(KC_D)
#define _STPDB_ LCMD(KC_F2)
