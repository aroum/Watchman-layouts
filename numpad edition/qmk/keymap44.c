#include QMK_KEYBOARD_H

enum custom_keycodes {
    LNG_SW = SAFE_RANGE,
    RUBLE,
    CPRGHT,
    DEGREE,
    GRTSGN,
    PLSMNS,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LNG_SW:
        if (record->event.pressed) {
            // when keycode LNG_SW is pressed
            SEND_STRING(SS_LGUI(SS_TAP(X_SPC)));
        } else {
            // when keycode LNG_SW is released
        }
        break;

    case RUBLE:
        if (record->event.pressed) {
            // when keycode RUBLE is pressed
            SEND_STRING(SS_RALT(SS_TAP(X_8)));
        } else {
            // when keycode RUBLE is released
        }
        break;

    case CPRGHT:
        if (record->event.pressed) {
            // when keycode CPRGHT is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_9)));
        } else {
            // when keycode CPRGHT is released
        }
        break;

    case DEGREE:
        if (record->event.pressed) {
            // when keycode DEGREE is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
        } else {
            // when keycode DEGREE is released
        }
        break;

    case GRTSGN:
        if (record->event.pressed) {
            // when keycode GRTSGN is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_6) SS_TAP(X_KP_2)));
        } else {
            // when keycode GRTSGN is released
        }
        break;

    case PLSMNS:
        if (record->event.pressed) {
            // when keycode PLSMNS is pressed
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_7)));
        } else {
            // when keycode PLSMNS is released
        }
        break;

        }
    return true;
};

#define KC_LG_RBR LGUI_T(KC_RBRC)
#define KC_LC_GRV LCTL_T(KC_GRV)
#define KC_LA_BCL LALT_T(KC_BSLS)

#define KC_RG_LBR RGUI_T(KC_LBRC)
#define KC_RC_QUO RCTL_T(KC_QUOT)
#define KC_RA_MIN RALT_T(KC_MINUS)

#define KC_L2_TAB LT(2,KC_TAB)
#define KC_LS_SPC LSFT_T(KC_SPC)
#define KC_L1_ENT LT(1,KC_ENT)

#define KC_L1_ESC LT(1,KC_ESC)
#define KC_RS_BSP RSFT_T(KC_BSPC)
#define KC_L2_DEL LT(2,KC_DEL)

#define KC_LA_EQL LALT_T(KC_EQL)

#define KC_L3_TAB LT(3, KC_TAB)
#define KC_L3_DEL LT(3, KC_DEL)

#define KC_LG_CAP LGUI_T(KC_CAPS)
#define KC_LA_EQL LALT_T(KC_EQL)

#define KC_RG_NLC RGUI_T(KC_NLCK)
#define KC_RC_PEN RCTL_T(KC_PENT)

#define KC_L3_ENT LT(3,KC_ENT)
#define KC_L3_ESC LT(3,KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
     //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
KC_NO,  KC_LG_RBR ,   KC_Q   ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,                                       KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   ,   KC_P   ,KC_RG_LBR ,  KC_NO,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
        KC_LC_GRV ,   KC_A   ,   KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,                                       KC_H   ,   KC_J   ,   KC_K   ,   KC_L   ,  KC_SCLN ,KC_RC_QUO ,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
        KC_LA_BCL ,   KC_Z   ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,                                       KC_N   ,   KC_M   ,  KC_COMM ,   KC_DOT,   KC_SLSH ,KC_RA_MIN ,
     //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘       
                                                    KC_L2_TAB ,KC_LS_SPC , KC_L1_ENT,              KC_L1_ESC ,KC_RS_BSP ,KC_L2_DEL
                                                // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),
[1] = LAYOUT(
     //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
KC_NO,   KC_LGUI  ,  KC_F1   ,  KC_F2   ,  KC_F3   ,  KC_F4   ,  KC_CAPS ,                                     KC_EXLM  ,  KC_AT   , KC_HASH  ,  KC_DLR  , KC_PERC  , KC_RGUI  ,  KC_NO,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
         KC_LCTL  ,  KC_F5   ,  KC_F6   ,  KC_F7   ,  KC_F8   ,  KC_APP  ,                                     KC_CIRC  ,  KC_AMPR , KC_ASTR  ,  KC_LPRN , KC_RPRN  , KC_RCTL  ,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
         KC_LALT  ,  KC_F9   ,  KC_F10  ,  KC_F11  ,  KC_F12  ,  LNG_SW  ,                                      RUBLE   ,  CPRGHT  , DEGREE   ,  GRTSGN  , PLSMNS   , KC_RALT  ,
     //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘       
                                                    KC_L3_TAB , _______  , _______  ,               _______  , _______  ,KC_L3_DEL
                                                // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘
),
[2] = LAYOUT(
     //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
KC_NO,   KC_LG_CAP, KC_PAST  ,   KC_7   ,   KC_8   ,   KC_9   , KC_PPLS  ,                                     KC_WH_U  ,   KC_P7  ,   KC_P8  ,   KC_P9  ,  KC_VOLU ,KC_RG_NLC ,  KC_NO,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
          KC_LCTL , KC_PSLS  ,   KC_4   ,   KC_5   ,   KC_6   , KC_PMNS  ,                                      KC_WH_D ,   KC_P4  ,   KC_P5  ,   KC_P6  ,  KC_VOLD ,KC_RC_PEN ,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
         KC_LA_EQL,   KC_0   ,   KC_1   ,   KC_2   ,   KC_3   , KC_PDOT  ,                                      KC_P0   ,   KC_P1  ,   KC_P2  ,   KC_P3  ,  KC_MUTE ,KC_RALT   ,
     //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘  
                                                     _______  , _______  ,KC_L3_ENT ,              KC_L3_ESC , _______  , _______
                                                // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘


),
[3] = LAYOUT(
     //┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐                                   ┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
KC_NO,   KC_LGUI  ,   RESET  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,                                     KC_SLCK  , RGB_HUI  , RGB_VAI  , BL_INC   ,  RESET   , KC_RGUI  ,  KC_NO,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
         KC_LCTL  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   TO(1)  ,                                     KC_PAUS  , RGB_SAI  , RGB_VAD  , BL_DEC   ,  KC_INS  , KC_RCTL  ,
     //├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                                   ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤ 
         KC_LALT  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   KC_NO  ,   TO(2)  ,                                      KC_NO   , RGB_MOD  , RGB_TOG  , BL_TOGG  ,  KC_PSCR , KC_RALT  ,
     //└──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┐             ┌──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────┘       
                                                     _______  , KC_LSFT  , _______  ,               _______  , KC_RSFT  , _______
                                                // └──────────┴──────────┴──────────┘             └──────────┴──────────┴──────────┘

)
};

const rgblight_segment_t PROGMEM my_layer0[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, HSV_ORANGE}
);       
const rgblight_segment_t PROGMEM my_layer1[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_RED} 
);
const rgblight_segment_t PROGMEM my_layer2[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 7, HSV_GREEN}
);
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