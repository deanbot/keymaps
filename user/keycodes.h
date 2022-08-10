#pragma once

#include QMK_KEYBOARD_H

enum layers
{
  _BASE,
  _MIR,
  _FN,
  _NAV,
  _GUI,
  _MSE,
  _DBG,
  _SYM,
  _NUM,
  _META,
};

enum layers_cannonball {
  BASE = 0,
  RAISE,
  UTIL_1,
  UTIL_2,
  UTIL_3,
  UTIL_4,
  UTIL_5
};

enum keycodes
{
  _SEL_L_ = SAFE_RANGE,

  // _TERTL_,
  // _TERTR_,

  _STRIN_, // ${} left
  _TYPE__, // <> left
  _ARROW_, // =>
  _REQU__, // required
  __SS___, // s umlaut
  __AE___, // a umlaut
  __UE___, // u umlaut
  __OE___, // o umlaut
  __ZE___, // euro

  // swappers
  _SWWIN_,
  _SWLNG_,

  // one shot
  _O_SFT_,
  _O_ALT_,
  _O_GUI_,
  _O_CTL_,

  // repeat
  __RPT__,

  // capsword
  _CAPSW_,

  // double left click
  _MB1X2_,

  // mousekey combos
  // _C_MB1_,
  // _C_MB2_,
  // _C_MWU_,
  // _C_MWD_,

  // pimoroni scroll
  _PSCRL_,

  _USRPW_,
};

#define _LEADF_ KC_F22

#define _MONAV_ MO(_NAV)
#define _MOSYM_ MO(_SYM)
#define _MOMIR_ MO(_MIR)
#define _MOMSE_ MO(_MSE)
#define _MMETA_ MO(_META)
#define _MODBG_ MO(_DBG)
#define _SPGUI_ LT(_GUI, KC_SPACE) // tap: space hold: gui layer
#define _L_MIR_ LT(_MIR, _LEADF_) // tap: leader hold: mirror layer
#define _DBG_T_ LT(_DBG, __HUD__) // tap: escape hold: debug layer
#define _CLMK_ DF(_BASE)

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
#define __F13__ KC_F13
#define __F14__ KC_F14
#define __F15__ KC_F15
#define __F16__ KC_F16
#define __F17__ KC_F17
#define __F18__ KC_F18
#define __F19__ KC_F19
#define __F20__ KC_F20
#define __F21__ KC_F21
#define __F22__ KC_F22
#define __F23__ KC_F23
#define __F24__ KC_F24

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

#define _ALTTB_ KC_F15 // alt tab

// gui
#define _T_LFT_ KC_F17
#define _T_RGT_ KC_F18
#define _T_TOP_ KC_F19
#define _T_BTM_ KC_F20
#define _CENTR_ LCTL(KC_F20)
#define __MAX__ LCTL(KC_F19)
#define _T_NW_ LSFT(KC_F17)
#define _T_NE_ LSFT(KC_F18)
#define _T_SW_ LSFT(KC_F19)
#define _T_SE_ LSFT(KC_F20)
#define _SPOT_ LCMD(KC_SPACE)

// workflow/app/browser
#define _LEAD__ KC_LEAD
#define _CTL_C_ LCTL(KC_C)
#define _STAB__ LSFT(KC_TAB)
#define _PRTRC_ LCMD(LSFT(KC_4)) // print region clipboard
#define _PRTSF_ LCMD(LSFT(KC_3)) // print screen file
#define _CLOSE_ LCMD(KC_W)
#define _QUIT__ LCMD(KC_Q)
#define _HIDE__ LCMD(KC_H)
#define _FIND__ LCMD(KC_F)
#define __DUP__ LCMD(KC_D)
#define _RFSH__ LCMD(KC_R)
#define _COPY__ LCMD(KC_C)
#define __CUT__ LCMD(KC_X)
#define _UNDO__ LCMD(KC_Z)
#define _PASTE_ LCMD(KC_V)
#define _REDO__ LCMD(LSFT(KC_Z))
#define _N_TAB_ LCMD(KC_T)
#define _RETAB_ LSFT(LCMD(KC_T))
#define _N_WIN_ LCMD(KC_N)
#define _TAB_L_ LCTL(KC_PGUP)
#define _TAB_R_ LCTL(KC_PGDOWN)
#define _BSP_W_ LOPT(KC_BSPACE)
#define _DEL_W_ LOPT(KC_DELETE)
#define _BSP_L_ LCMD(KC_BSPACE)
#define _DEL_L_ LCMD(KC_DELETE)
#define _BEGLN_ LCMD(KC_LEFT)
#define _ENDLN_ LCMD(KC_RIGHT)
#define _SEL_A_ LCMD(KC_A)
#define __TOP__ LCMD(KC_UP)
#define __BTM__ LCMD(KC_DOWN)
#define __HUD__ LCTL(KC_UP)
#define _TMSMU_ LCMD(LSFT(KC_M))
#define _INCOG_ LCMD(LSFT(KC_N))
#define _DEVT__ LCMD(LOPT(KC_I))
#define _SRCHW_ LCMD(LOPT(KC_F))
#define _ADDRS_ LCMD(KC_L)
#define _JUMP__ LCMD(KC_K)
#define _BACK__ LCMD(KC_LBRACKET)
#define __FWD__ LCMD(KC_RBRACKET)
#define _ZOOMI_ LCMD(KC_PLUS)
#define _ZOOMO_ LCMD(KC_MINUS)
#define _ZOOMR_ LCMD(KC_0)
#define _SAVE__ LCMD(KC_S)
#define _SPOTL_ LCMD(KC_SPACE)
#define _WD_L__ LOPT(KC_LEFT)
#define _WD_R__ LOPT(KC_RIGHT)
#define _SWD_L_ LSFT(LOPT(KC_LEFT))
#define _SWD_R_ LSFT(LOPT(KC_RIGHT))

// apps
#define _DISCO_ HYPR(KC_D) // discord
#define _SLACK_ HYPR(KC_S)
#define _TEAMS_ HYPR(KC_T)
#define _ANDST_ HYPR(KC_A)
#define _VSCDE_ HYPR(KC_V)
#define _OUTLK_ HYPR(KC_O)
#define _MUSIC_ HYPR(KC_C)
#define _BRWSR_ HYPR(KC_B)

// ide
#define _HINT__ LCTL(KC_C) //LCTL(KC_SPACE) // prompt complete
#define __FIX__ LOPT(LSFT(KC_ENTER)) // autofix
#define _ACTIO_ LOPT(KC_ENTER) // actions
#define _TERM__ LALT(KC_F12) // toggle terminal
#define _TERMQ_ LSFT(LALT(KC_F12))
#define _NEWFL_ LCMD(LOPT(KC_N)) // new file in directory
#define _DRTAN_ LCMD(KC_SCOLON) // analysis
#define _PROJ__ LCMD(KC_1) // project explorer
#define _DEBGR_ LCMD(KC_5) // debugger panel
#define _COMMT_ LCMD(KC_0) // git panel
#define _RNAME_ LSFT(KC_F6) // rename
#define _COLS__ LCMD(LSFT(KC_8)) // col selection
#define _FORMA_ LCMD(LOPT(KC_L)) // format code
#define _RFCTR_ LCTL(KC_T) // refactor this
#define _WRAP__ LOPT(LCMD(KC_T))
#define _SORTI_ LCTL(LOPT(KC_O)) // sort imports
#define _FINDF_ LCMD(LSFT(KC_O)) // find file in workspace
#define _GOTOD_ LCMD(KC_B) // go to definition
#define _GOTOE_ KC_F2 // go to next error
#define _GOTOL_ LCMD(KC_L) // go to line
#define _GOTOS_ LCMD(LOPT(KC_O)) // go to symbol in editor
#define _HTRST_ LCMD(LSFT(KC_BSLASH)) // hot reset
#define _DEBUG_ LCTL(KC_D) // start debugger
#define _STPDB_ LCMD(KC_F2) // stop debugger
#define _RSUME_ LOPT(LCMD(KC_R)) // resume execution
#define _MATCH_ LCTL(KC_M) // match bracket
#define _REPL__ LCMD(KC_R) // replace
#define _FOLDI_ LCMD(KC_MINUS) // fold code in
#define _FOLDO_ LCMD(KC_PLUS) // fold code out
#define _RESUM_ LCMD(LOPT(KC_R)) // resume debugger
#define _STOP__ LCMD(KC_F2) // stop debugging
#define _START_ LCTL(KC_D) // start debugging
#define _RSTRT_ LSFT(LCMD(_BSLSH_)) // hot restart
#define _RLOAD_ LCMD(_BSLSH_) // hot reload
#define _TOGBR_ LCMD(KC_F8) // toggle breakpoint
#define _DT_OV_ KC_F8 // debug step over
#define _DS_IN_ KC_F7 // debug step into
#define _DSOUT_ LSFT(KC_F8) // debug step out

// terminal
#define __BOL__ LCTL(KC_A)
#define __EOL__ LCTL(KC_E)
