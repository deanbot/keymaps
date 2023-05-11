#pragma once

// #define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY
// #define TAPPING_TERM_PER_KEY
// #define TAPPING_TERM 200
// #define TAPPING_FORCE_HOLD
// #undef TAPPING_FORCE_HOLD

// Combos
#define COMBO_TERM 30
// #define COMBO_VARIABLE_LEN
// #define COMBO_TERM_PER_COMBO

#ifdef MOUSEKEY_ENABLE
#  define MOUSEKEY_INTERVAL 16
#  define MOUSEKEY_DELAY 0
#  define MOUSEKEY_TIME_TO_MAX 60
#  define MOUSEKEY_MAX_SPEED 7
#  define MOUSEKEY_WHEEL_DELAY 0
#endif

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 260
#define LEADER_NO_TIMEOUT
// #define LEADER_KEY_STRICT_KEY_PROCESSING

#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 2085

// reduce filesize
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION

// #define ENCODER_RESOLUTION 4

// #define EECONFIG_KB_DATA_SIZE 8