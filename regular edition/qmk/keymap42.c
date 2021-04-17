#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
LGUI_T(KC_RBRC), KC_Q, KC_W, KC_E, KC_R, KC_T,                     KC_Y, KC_U, KC_I,    KC_O,   KC_P,    RGUI_T(KC_LBRC),
LCTL_T(KC_GRV),  KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, RCTL_T(KC_QUOT),
LALT_T(KC_BSLS), KC_Z, KC_X, KC_C, KC_V, KC_B,                     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RALT_T(KC_MINUS),
   LT(2,KC_TAB), LSFT_T(KC_SPC), LT(1,KC_ENT),                     LT(1,KC_ESC), RSFT_T(KC_BSPC), LT(2,KC_DEL)
),
[1] = LAYOUT(
LGUI_T(KC_F1),   KC_F2,   KC_F3, KC_F4,   KC_F5,  KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  RGUI_T(KC_F12),
LCTL_T(KC_PPLS), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
LALT_T(KC_EQL),  KC_1,    KC_2,  KC_3,    KC_4,   KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RALT_T(KC_MINS),
                            LT(3, KC_TAB),_______,_______,   _______,_______,LT(3, KC_DEL)
),
[2] = LAYOUT(
LGUI_T(KC_NLCK), KC_PSLS, KC_P7, KC_P8, KC_P9, TO(3),        KC_WH_U, KC_HOME, KC_MPLY, KC_PGUP, KC_VOLU, RGUI_T(KC_CAPS),
LCTL_T(KC_PPLS), KC_PAST, KC_P4, KC_P5, KC_P6, KC_PMNS,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, RCTL_T(KC_APP),
LALT_T(KC_EQL),  KC_P0,   KC_P1, KC_P2, KC_P3, KC_PDOT,      KC_WH_D, KC_END,  KC_PSCR, KC_PGDN, KC_MUTE, KC_RALT,
                        _______, _______, LT(3,KC_ENT),      LT(3,KC_ESC), _______, _______
),
[3] = LAYOUT(
LGUI_T(KC_SLCK), RGB_VAI, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,        KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2, BL_INC,  KC_RGUI,
LCTL_T(KC_PAUS), RGB_VAD, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN3,        KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_R, BL_DEC,  KC_RCTL,
LALT_T(KC_INS),  RGB_TOG, RESET,   TO(2),   TO(1),   KC_WH_D,        KC_MS_D, TO(1),   TO(2),   RESET,   BL_TOGG, KC_RALT,
                                   _______, KC_LSFT, _______,        _______, KC_RSFT, _______
)
};
// Light LED 1 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, HSV_ORANGE}
);       
// Light 7 LEDs in red when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_RED}
);
// Light 7 LEDs in green when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_GREEN}
);
// Light 7 LEDs in cyan when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer0,
    my_layer1,   
    my_layer2,
    my_layer3// Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
};

// 0 No
// 1 HSV_RED
// 2 HSV_GREEN
// 3 HSV_CYAN
