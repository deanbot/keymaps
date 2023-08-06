#pragma once

#include QMK_KEYBOARD_H

#include "codes.h"
#include "wrappers.h"

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

#ifdef CUSTOM_ONESHOT_ENABLE
# include "features/oneshot.h"
#endif

#ifdef CUSTOM_SWAPPER_ENABLE
# include "features/swapper.h"
#endif

#ifdef CUSTOM_REPEAT_ENABLE
# include "features/repeat.h"
#endif

#ifdef CUSTOM_CAPS_WORD_ENABLE
# include "features/caps_word.h"
#endif
