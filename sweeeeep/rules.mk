# BOOTLOADER = atmel-dfu
# SPLIT_KEYBOARD = no

# reduce filesize
# COMMAND_ENABLE = no
EXTRAFLAGS += -flto

# Disable unused features
CONSOLE_ENABLE = no
VIA_ENABLE = no
NKRO_ENABLE = no
AUDIO_ENABLE = no
STENO_ENABLE = no
COMMAND_ENABLE = no
TERMINAL_ENABLE = no
KEY_LOCK_ENABLE = no
BOOTMAGIC_ENABLE = no
SLEEP_LED_ENABLE = no
TAP_DANCE_ENABLE = no
VELOCIKEY_ENABLE = no
SWAP_HANDS_ENABLE = no
# RGBLIGHT_ENABLE = no
# RGB_MATRIX_ENABLE = no
SPACE_CADET_ENABLE = no
KEY_OVERRIDE_ENABLE = no

LEADER_ENABLE = yes
MOUSEKEY_ENABLE = yes
CUSTOM_ONESHOT_ENABLE = yes
CUSTOM_SWAPPER_ENABLE = yes
CUSTOM_REPEAT_ENABLE = no
CUSTOM_CAPS_WORD_ENABLE = yes

VPATH += keyboards/gboards/
COMBO_ENABLE = yes
