#pragma once

// #define ENCODER_RESOLUTION 4
#define ENCODER_RESOLUTIONS { 4, 4, 4 }

#ifdef MOUSEKEY_ENABLE
  #define MOUSEKEY_INTERVAL 16
  #define MOUSEKEY_TIME_TO_MAX 40
  #define MOUSEKEY_DELAY 100
  #define MOUSEKEY_MOVE_DELTA 5
  #define MOUSEKEY_MAX_SPEED 5a
  #define MOUSEKEY_WHEEL_DELAY 100
  #define MOUSEKEY_WHEEL_INTERVAL 50
  #define MOUSEKEY_WHEEL_MAX_SPEED 6
  #define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif

// // Underglow configuration
// #ifdef RGBLIGHT_ENABLE
//   #define RGBLIGHT_ANIMATIONS
//   #define RGBLIGHT_HUE_STEP 8
//   #define RGBLIGHT_SAT_STEP 8
//   #define RGBLIGHT_VAL_STEP 8
// #endif

// #define RETRO_TAPPING
