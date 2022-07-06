#include "swap_os.h"

swap_os current_os = OS_OSX;
static swap_os get_next_os(swap_os os);

void update_os() {
  current_os = get_next_os(current_os);
}

swap_os get_next_os(swap_os os) {
  swap_os next_os;
  switch (os) {
    case OS_OSX:
      next_os = OS_WIN;
      break;
    case OS_WIN:
      next_os = OS_LINUX;
      break;
    case OS_LINUX:
      next_os = OS_OSX;
      break;
  }
  return next_os;
}
