SRC += deanbot.c

ifeq ($(strip $(CUSTOM_ONESHOT_ENABLE)), yes)
	SRC += ./features/oneshot.c
	OPT_DEFS += -DCUSTOM_ONESHOT_ENABLE
endif

ifeq ($(strip $(CUSTOM_REPEAT_ENABLE)), yes)
	SRC += ./features/repeat.c
	OPT_DEFS += -DCUSTOM_REPEAT_ENABLE
endif

ifeq ($(strip $(CUSTOM_CAPS_WORD_ENABLE)), yes)
	SRC += ./features/caps_word.c
	OPT_DEFS += -DCUSTOM_CAPS_WORD_ENABLE
endif

ifeq ($(strip $(CUSTOM_SWAPPER_ENABLE)), yes)
	SRC += ./features/swapper.c
	OPT_DEFS += -DCUSTOM_SWAPPER_ENABLE
endif

SRC += ./features/swap_os.c
