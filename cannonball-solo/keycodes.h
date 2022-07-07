#pragma once

#include QMK_KEYBOARD_H

enum layers_cannonball {
  BASE = 0,
  RAISE,
  UTIL_1,
  UTIL_2,
  UTIL_3,
  UTIL_4,
  UTIL_5
};

// cannonball layer change
#define TG_P5__ TG(UTIL_5)
#define LT_2U__ LT(RAISE, KC_SPACE)
#define LT_P1__ LT(UTIL_1, KC_ENTER)
#define LT_P2__ LT(UTIL_2, KC_F15)
#define LT_P3__ LT(UTIL_3, KC_F16)
#define LT_P4__ LT(UTIL_4, KC_BSPC)

enum keycodes {
  _SEL_L_ = SAFE_RANGE,
  _SWWIN_, // swap window
  _MB1X2_ // double left click
};

// arrow
#define _LEFT__ KC_LEFT
#define _DOWN__ KC_DOWN
#define __UP___ KC_UP
#define _RIGHT_ KC_RIGHT

// basic
#define _SPACE_ KC_SPACE
#define __TAB__ KC_TAB
#define _ENTER_ KC_ENTER
#define _BKSPC_ KC_BSPACE
#define __DEL__ KC_DELETE
#define __ESC__ KC_ESCAPE

// mod
#define _LSHFT_ KC_LSFT

// mouse
#define _MWLFT_ KC_MS_WH_LEFT
#define _MWDWN_ KC_MS_WH_DOWN
#define _MWUP__ KC_MS_WH_UP
#define _MWRGT_ KC_MS_WH_RIGHT
#define __MB1__ KC_MS_BTN1
#define __MB2__ KC_MS_BTN2
#define __MB3__ KC_MS_BTN3

// media
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

// gui
#define _T_LFT_ KC_F17
#define _T_RGT_ KC_F18
#define __MAX__ LCTL(KC_F19)
#define __HUD__ LCTL(KC_UP) // task view

// workflow
#define _COPY__ LCMD(KC_C)
#define __CUT__ LCMD(KC_X)
#define _UNDO__ LCMD(KC_Z)
#define _PASTE_ LCMD(KC_V)
#define _REDO__ LCMD(LSFT(KC_Z))
#define _SAVE__ LCMD(KC_S)
#define _STAB__ LSFT(KC_TAB) // shift tab
#define _PRTRC_ LCMD(LSFT(KC_4)) // print region clipboard
#define _BEGLN_ LCMD(KC_LEFT) // beginning of line
#define _ENDLN_ LCMD(KC_RIGHT) // end of line
#define _SEL_A_ LCMD(KC_A) // select all
#define _TAB_L_ LCTL(KC_PGUP)
#define _TAB_R_ LCTL(KC_PGDOWN)
#define _N_TAB_ LCMD(KC_T) // new tab
#define _RETAB_ LSFT(LCMD(KC_T)) // reopen window
#define _CLOSE_ LCMD(KC_W) // close window
#define _QUIT__ LCMD(KC_Q) // quit app
#define _HIDE__ LCMD(KC_H) // minimize
#define _ADDRS_ LCMD(KC_L) // select address bar
#define _JUMP__ LCMD(KC_K) // slack jump
#define _RFSH__ LCMD(KC_R) // browser refresh
#define _BACK__ LCMD(KC_LBRACKET) // browser back
#define __FWD__ LCMD(KC_RBRACKET) // browser forward
#define _ZOOMI_ LCMD(KC_PLUS) // zoom in
#define _ZOOMO_ LCMD(KC_MINUS) // zoom out
#define _ZOOMR_ LCMD(KC_0) // zoom reset
#define _WD_L__ LOPT(KC_LEFT)
#define _WD_R__ LOPT(KC_RIGHT)
#define _INCOG_ LCMD(LSFT(KC_N))
