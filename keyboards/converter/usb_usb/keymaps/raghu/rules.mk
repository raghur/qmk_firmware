F_CPU=8000000
BOOTLOADER=caterina
# media keys
COMBO_ENABLE=no
EXTRAKEY_ENABLE=yes
TAP_DANCE_ENABLE=yes
USB_HID_ENABLE=yes
LTO_ENABLE=yes

# required to further reduce fw size.
EXTRAFLAGS=-flto
OLED_ENABLE=yes
MAGIC_ENABLE=yes

LEADER_ENABLE=yes
SPACE_CADET_ENABLE=yes

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
