#include <stdio.h>
#include QMK_KEYBOARD_H
#include "chdorner36.h"

const key_override_t ko_bspc_del  = ko_make_basic(MOD_MASK_SHIFT, LAY_BSPC, KC_DEL);
const key_override_t ko_lprn_ques = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_QUES);
const key_override_t ko_rprn_exlm = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_EXLM);
const key_override_t ko_lcbr_lbrc = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_LBRC);
const key_override_t ko_rcbr_rbrc = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_RBRC);
const key_override_t ko_dlr_euro  = ko_make_basic(MOD_MASK_SHIFT, KC_DLR, KC_EUR);
const key_override_t ko_grv_ampr  = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_AMPR);
const key_override_t ko_slsh_no   = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_SLSH);
const key_override_t ko_astr_circ = ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_CIRC);
const key_override_t ko_pipe_bsls = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_BSLS);
const key_override_t **key_overrides = (const key_override_t *[]) {
    &ko_bspc_del,
    &ko_lprn_ques,
    &ko_rprn_exlm,
    &ko_lcbr_lbrc,
    &ko_rcbr_rbrc,
    &ko_dlr_euro,
    &ko_grv_ampr,
    &ko_slsh_no,
    &ko_astr_circ,
    &ko_pipe_bsls,
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,   KC_F,   KC_P,   KC_G, /* | */ KC_J,    KC_L,   KC_U,    KC_Y,   KC_SEMICOLON,
        HOME_A,  HOME_R, HOME_S, HOME_T, KC_D, /* | */ KC_H,    HOME_N, HOME_E,  HOME_I, HOME_O,
        KC_Z,    KC_X,   KC_C,   KC_V,   KC_B, /* | */ KC_K,    KC_M,   KC_COMM, KC_DOT, KC_QUOT,
        KC_ESC,  LAY_SPC, LAY_BSPC,            /* | */ LAY_TAB, KC_ENT, KC_LEAD
    ),
    [_MOV] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_NO,   KC_HOME, KC_END,  KC_NO,    KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /* | */ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_NO,   KC_PGDN, KC_PGUP, KC_NO,    KC_NO,
        KC_ESC,  KC_NO,   KC_BSPC,                 /* | */ KC_TAB,  KC_ENT,  KC_NO
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ CAPSWRD, KC_MINS, KC_EQL,  KC_GRV,  KC_ASTR,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /* | */ KC_TILD, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_DLR,  KC_HASH, KC_AT,   KC_SLSH, KC_PIPE,
        KC_ESC,  KC_SPC,  KC_NO,                   /* | */ KC_TAB,  KC_ENT,  KC_NO
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        KC_NO,  KC_P7,  KC_P8, KC_P9, KC_EQL,  /* | */ KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_P0,  KC_P4,  KC_P5, KC_P6, KC_MINS, /* | */ KC_NO,  KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        KC_DOT, KC_P1,  KC_P2, KC_P3, KC_NO,   /* | */ KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,
        KC_ESC, KC_SPC, KC_NO,                 /* | */ KC_TAB, KC_ENT, KC_NO
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
