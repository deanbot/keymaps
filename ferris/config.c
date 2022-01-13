#pragma once

#define MOUSEKEY_DELAY 0 // 300 - Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 4 // 50 - Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA 5 // 5 - Step size
#define MOUSEKEY_MAX_SPEED 5 // 10 - Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX 40 // 20 - Time until maximum cursor speed is reached
#define MOUSEKEY_WHEEL_DELAY 100 // 300 - Delay between pressing a wheel key and wheel movement
#define MOUSEKEY_WHEEL_INTERVAL 4 // 100 - Time between wheel movements
#define MOUSEKEY_WHEEL_MAX_SPEED 6 // 8 - Maximum number of scroll steps per scroll action
#define MOUSEKEY_WHEEL_TIME_TO_MAX 5 // 40 - Time until maximum scroll speed is reached

// Underglow configuration
#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
#endif
