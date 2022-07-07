#include QMK_KEYBOARD_H

typedef enum {
  OS_OSX = 0,
  OS_WIN = 1,
  OS_UBU = 2
} swap_os;

swap_os current_os;

void update_os(void);
