#include QMK_KEYBOARD_H

/* const key_override_t brightness_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CA, KC_MPLY, */
/*                                             KC_BRIU, ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger); */

/* const key_override_t brightness_down_override = ko_make_basic(MOD_MASK_CSA, KC_MPLY, KC_BRID); */
/* const key_override_t **key_overrides = (const key_override_t *[]){ */
/*     &brightness_up_override, */
/*     &brightness_down_override, */
/*     NULL */
/* }; */
#ifdef COMBO_ENABLE
const uint16_t PROGMEM test_combo1[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_ESC),
};
#endif

#ifdef TAP_DANCE_ENABLE
// Tap Dance declarations
enum {
    TD_PS_2,
    TD_BSLS_ALTTAB,
    // TD_COPY,
    // TD_PASTE,
    TD_WIN_TAB,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap PS once for print screen, double tap to toggle mousekeys
    [TD_PS_2] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_PSCR, 2),
    [TD_BSLS_ALTTAB] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, LALT(KC_TAB)),
    // [TD_COPY] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
    // [TD_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, LCTL(KC_V)),
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
            oled_write_P(PSTR("DFL\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("XTR\n"), false);
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
