#include QMK_KEYBOARD_H
#include "custom.h"

/* const key_override_t brightness_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CA, KC_MPLY, */
/*                                             KC_BRIU, ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger); */

/* const key_override_t brightness_down_override = ko_make_basic(MOD_MASK_CSA, KC_MPLY, KC_BRID); */
/* const key_override_t **key_overrides = (const key_override_t *[]){ */
/*     &brightness_up_override, */
/*     &brightness_down_override, */
/*     NULL */
/* }; */
#ifdef COMBO_ENABLE
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(jk_combo, KC_ESC),
};
#endif

#ifdef TAP_DANCE_ENABLE
// Function to determine the current tapdance state
td_state_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void bsls_finished(qk_tap_dance_state_t *state, void *user_data);
void bsls_reset(qk_tap_dance_state_t *state, void *user_data);

void shift_finished(qk_tap_dance_state_t *state, void *user_data);
void shift_reset(qk_tap_dance_state_t *state, void *user_data);
// Determine the current tap dance state
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count >= 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t bsls_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t shift_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void bsls_finished(qk_tap_dance_state_t *state, void *user_data) {
    bsls_tap_state.state = cur_dance(state);
    switch (bsls_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_BSLS);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(LYR_EXTRAKEYS)) {
                // If already set, then switch it off
                layer_off(LYR_EXTRAKEYS);
            } else {
                // If not already set, then switch the layer on
                set_oneshot_layer(LYR_EXTRAKEYS, ONESHOT_START);
            }
            break;
        default:
            break;
    }
}

void bsls_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (bsls_tap_state.state == TD_DOUBLE_TAP) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
    bsls_tap_state.state = TD_NONE;
}

void shift_finished(qk_tap_dance_state_t *state, void *user_data) {
    shift_tap_state.state = cur_dance(state);
    switch (shift_tap_state.state) {
        case TD_SINGLE_TAP:
#ifdef LEADER_ENABLE
            qk_leader_start();
            break;
#endif
        case TD_SINGLE_HOLD:
            register_mods(MOD_LSFT | get_oneshot_mods());
            break;
        case TD_DOUBLE_TAP:
            set_oneshot_mods(MOD_LALT | get_oneshot_mods());
            break;
        default:
            break;
    }
}

void shift_reset(qk_tap_dance_state_t *state, void *user_data) {

    if (shift_tap_state.state == TD_SINGLE_HOLD) {
        unregister_mods(MOD_LSFT);
    }

    /* if (shift_tap_state.state == TD_DOUBLE_TAP) { */
    /*     clear_oneshot_mods(); */
    /* } */

    shift_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap PS once for print screen, double tap to toggle mousekeys
    [TD_PS_2] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_PSCR, 2),
    // [TD_COPY] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
    // [TD_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
    [TD_BSLS_ALTTAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bsls_finished, bsls_reset),
    [TD_SHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shift_finished, shift_reset),
    [TD_WIN_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, LGUI(KC_TAB)),
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    // oled_write_P(PSTR("LYR: "), false);
    /* oled_write_P(get_u8_str(get_highest_layer(layer_state), ' '), false); */
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("DFLT\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("XTRA\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("MSE\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            // oled_write_ln_P(PSTR("NA"), false);
            break;
    }

    // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    /* oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false); */
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    /* oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false); */

    return false;
}
#endif

#ifdef LEADER_ENABLE
uint8_t leaderCSFT = 0;
void toggleCSFT (void) {
    if (!leaderCSFT) {
        register_mods(MOD_LCTL);
        register_mods(MOD_LSFT);
    }else {
        unregister_mods(MOD_LSFT);
        unregister_mods(MOD_LCTL);
    }

    leaderCSFT = !leaderCSFT;
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_TWO_KEYS(KC_E, KC_E) {
            // Anything you can do in a macro.
            SEND_STRING("raghu.rajagopalan@gmail.com");
        }
        SEQ_TWO_KEYS(KC_E, KC_S) {
            SEND_STRING("raghu.nospam@gmail.com");
        }
        SEQ_TWO_KEYS(KC_E, KC_W) {
            SEND_STRING("raghu.rajagopalan@rockwellautomation.com");
        }
        SEQ_ONE_KEY(KC_L) {
            SEND_STRING("ra-int\\rrajagopala");
        }
        SEQ_ONE_KEY(KC_SPC) {
            toggleCSFT();
        }
        SEQ_ONE_KEY(KC_SCLN) {
            // this is to prevent confusion between shifted ; being typed fast 
            // rather than leader... helps me keep sanity
            SEND_STRING(":");
        }
        SEQ_ONE_KEY(KC_M) {
            register_code(KC_LGUI);
            register_code(KC_F12);
            unregister_code(KC_F12);
            unregister_code(KC_LGUI);
        }
        SEQ_ONE_KEY(KC_V) {
            register_code(KC_LALT);
            register_code(KC_LCTL);
            register_code(KC_V);
            unregister_code(KC_V);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
        }
    }
}
#endif
