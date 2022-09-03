F_CPU=8000000
BOOTLOADER=caterina
EXTRAKEY_ENABLE=yes
TAP_DANCE_ENABLE=yes
USB_HID_ENABLE=yes
OLED_ENABLE=no
LEADER_ENABLE=yes
LTO_ENABLE=yes
RGBLIGHT_ENABLE=yes
WS2812_DRIVER=bitbang

# required to further reduce fw size.
EXTRAFLAGS=-flto
SRC+=custom.c

# ----------- disabled for various reasons
MAGIC_ENABLE=no
COMBO_ENABLE=yes
SPACE_CADET_ENABLE=no

# size limited by RAM - see config.h
DYNAMIC_MACRO_ENABLE=no
   
# takes up too much space
MOUSEKEY_ENABLE=no

# too much space
AUDIO_ENABLE=no
# deprecated in favor of MAGIC
# COMMAND_ENABLE=no

#linux doesn't recognize...
PROGRAMMABLE_BUTTON_ENABLE = no
# only for tiny kbds without dedicated esc
GRAVE_ESC_ENABLE=no

CONSOLE_ENABLE=no
UNICODE_ENABLE=no
KEY_OVERRIDE_ENABLE=no
TERMINAL_ENABLE=no
