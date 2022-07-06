#include "./keycodes.h"
#include "./keymap.h"

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

#include "features/swap_os.h"
