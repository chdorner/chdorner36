#include QMK_KEYBOARD_H
#include <stdio.h>

#define L_B 0 // base layer
#define L_M 1 // movement layer
#define L_N 2 // numbers layer
#define L_S 3 // symbols layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_B] = LAYOUT_split_3x5_3(
        KC_Q,         KC_W,            KC_F,             KC_P,        KC_G, /* | */ KC_J,            KC_L,        KC_U,               KC_Y,        KC_SEMICOLON,
        GUI_T(KC_A),  ALT_T(KC_R),     CTL_T(KC_S),      SFT_T(KC_T), KC_D, /* | */ KC_H,            SFT_T(KC_N), CTL_T(KC_E),        ALT_T(KC_I), GUI_T(KC_O),
        KC_Z,         KC_X,            KC_C,             KC_V,        KC_B, /* | */ KC_K,            KC_M,        KC_COMM,            KC_DOT,      KC_SLSH,
        KC_ESC,       LT(L_M, KC_SPC), LT(L_N, KC_BSPC),                    /* | */ LT(L_S, KC_TAB), KC_ENT,      KC_LEAD
    ),
    [L_M] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ CAPS_WORD, KC_LBRC, KC_RBRC, KC_LPRN,  KC_RPRN,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /* | */ KC_LEFT,   KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_NO,     KC_NO,   KC_NO,   KC_NO,    KC_NO,
        KC_ESC,  KC_NO,   KC_BSPC,                 /* | */ KC_TAB,    KC_ENT,  KC_DEL
    ),
    [L_N] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_EQL,  KC_P7,  KC_P8, KC_P9, KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /* | */ KC_MINS, KC_P4,  KC_P5, KC_P6, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_P0,   KC_P1,  KC_P2, KC_P3, KC_NO,
        KC_ESC,  KC_SPC,  KC_NO,                   /* | */ KC_TAB,  KC_ENT, KC_DEL
    ),
    [L_S] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_ASTR, KC_AMPR, KC_NO,   /* | */ KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_QUOT, KC_CIRC, KC_PERC, KC_GRV,  KC_DLR,  /* | */ KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        KC_TILD, KC_HASH, KC_AT,   KC_EXLM, KC_BSLS, /* | */ KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_SPC,  KC_BSPC,                   /* | */ KC_NO, KC_ENT,  KC_DEL
    )
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Take screenshot
        SEQ_ONE_KEY(KC_S) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            tap_code(KC_4);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
        }

        // Toggle mute in Zoom
        SEQ_ONE_KEY(KC_M) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_LGUI);
            tap_code(KC_A);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
         }
    }
};

const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(L_N, KC_BSPC), KC_DEL);
const key_override_t **key_overrides = (const key_override_t *[]) {
    &backspace_key_override,
    NULL
};
