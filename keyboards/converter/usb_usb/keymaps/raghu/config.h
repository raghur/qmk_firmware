#pragma once
    
// place overrides here
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 10
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define LAYER_STATE_8BIT
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT 10000
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 2
#define COMBO_COUNT 1
#define COMBO_TERM 100
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300
#define LEADER_NO_TIMEOUT
#define DYNAMIC_MACRO_SIZE 32

// audio on pro micro with v-usb takes too much space
#define AUDIO_PIN B6
#define AUDIO_CLICKY
#define NO_MUSIC_MODE

// tap dance and related
#define TAPPING_TERM 175
#define RETRO_TAPPING
#define IGNORE_MOD_TAP_INTERRUPT

// underglow related
#define RGBLED_NUM 20
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LIMIT_VAL 180
#define RGBLIGHT_MAX_LAYERS 11
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_LAYER_BLINK
// define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_TEST
#define RGBLIGHT_LAYERS
#define RGB_DI_PIN F7
#define USE_GET_MILLISECOND_TIMER

// custom
#define ENABLE_LAYER_LED
