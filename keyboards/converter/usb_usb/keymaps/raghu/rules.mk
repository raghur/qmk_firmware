F_CPU=8000000
BOOTLOADER=caterina
EXTRAKEY_ENABLE=yes
TAP_DANCE_ENABLE=yes
USB_HID_ENABLE=yes
OLED_ENABLE=yes
LEADER_ENABLE=yes
LTO_ENABLE=yes
# required to further reduce fw size.
EXTRAFLAGS=-flto
SRC+=custom.c

# ----------- disabled for various reasons
MAGIC_ENABLE=no
COMBO_ENABLE=no
SPACE_CADET_ENABLE=no

# pro micro won't boot
# causes weird issues
DYNAMIC_MACRO_ENABLE=no

# takes up too much space
MOUSEKEY_ENABLE=no

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
