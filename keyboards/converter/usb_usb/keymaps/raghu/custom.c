
/* const key_override_t brightness_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CA, KC_MPLY, */
/*                                             KC_BRIU, ~0, MOD_MASK_SHIFT, ko_option_no_reregister_trigger); */

/* const key_override_t brightness_down_override = ko_make_basic(MOD_MASK_CSA, KC_MPLY, KC_BRID); */
/* const key_override_t **key_overrides = (const key_override_t *[]){ */
/*     &brightness_up_override, */
/*     &brightness_down_override, */
/*     NULL */
/* }; */
// Tap Dance declarations
enum {
    TD_PS_3,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap PS once for print screen, double tap to toggle mousekeys
    [TD_PS_3] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_PSCR, 3),
};

