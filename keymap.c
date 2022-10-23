#include <stdio.h>
#include QMK_KEYBOARD_H
#include "chdorner36.h"

const key_override_t ko_bspc_del  = ko_make_basic(MOD_MASK_SHIFT, LAY_BSPC, KC_DEL);
const key_override_t ko_lcbr_lbrc = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_LBRC);
const key_override_t ko_rcbr_rbrc = ko_make_basic(MOD_MASK_SHIFT, KC_RCBR, KC_RBRC);
const key_override_t ko_dlr_euro  = ko_make_basic(MOD_MASK_SHIFT, KC_DLR, KC_EUR);
const key_override_t ko_hash_ampr = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_AMPR);
const key_override_t ko_grv_perc  = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_PERC);
const key_override_t ko_slsh_no   = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_SLSH);
const key_override_t ko_astr_circ = ko_make_basic(MOD_MASK_SHIFT, KC_ASTR, KC_CIRC);
const key_override_t ko_pipe_bsls = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_BSLS);
const key_override_t **key_overrides = (const key_override_t *[]) {
    &ko_bspc_del,
    &ko_lcbr_lbrc,
    &ko_rcbr_rbrc,
    &ko_dlr_euro,
    &ko_hash_ampr,
    &ko_grv_perc,
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
        LAY_PAD, LAY_SPC, LAY_BSPC,            /* | */ LAY_TAB, KC_ENT, LAY_PAD
    ),
    [_MOV] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_NO,   KC_HOME, KC_END,  KC_NO,    KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /* | */ KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_NO,   KC_PGDN, KC_PGUP, KC_NO,    KC_NO,
        KC_NO,   KC_TRNS, KC_BSPC,                 /* | */ KC_TAB,  KC_ENT,  KC_NO
    ),
    [_SYM] = LAYOUT_split_3x5_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_EQL,  KC_QUES, KC_EXLM, KC_GRV,  KC_ASTR,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, /* | */ KC_TILD, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, /* | */ KC_DLR,  KC_HASH, KC_AT,   KC_SLSH, KC_PIPE,
        KC_NO,   KC_SPC,  KC_TRNS,                 /* | */ KC_TAB,  KC_ENT,  KC_NO
    ),
    [_NUM] = LAYOUT_split_3x5_3(
        KC_NO,  KC_P7,  KC_P8, KC_P9, KC_EQL,  /* | */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_P0,  KC_P4,  KC_P5, KC_P6, KC_MINS, /* | */ KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        KC_DOT, KC_P1,  KC_P2, KC_P3, KC_NO,   /* | */ KC_NO,   KC_NO,  KC_NO,    KC_NO,   KC_NO,
        KC_NO,  KC_SPC, KC_BSPC,               /* | */ KC_TRNS, KC_ENT, KC_NO
    ),
    [_PAD] = LAYOUT_split_3x5_3(
        LCKSCRN, KC_NO, KC_NO,   KC_NO, KC_NO, /* | */ KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO, SCRNSHT, KC_NO, KC_NO, /* | */ KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,
        KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, /* | */ KC_NO,   KC_MPLY, KC_NO,   KC_MUTE, ZMUTE,
        KC_TRNS, KC_NO, KC_NO,                 /* | */ KC_NO,   KC_NO,   KC_TRNS
    )
};

const uint16_t PROGMEM pl_combo[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM vm_combo[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM ao_combo[] = {HOME_A, HOME_O, COMBO_END};
const uint16_t PROGMEM zsq_combo[] = {KC_Z, KC_QUOT, COMBO_END};
combo_t key_combos[] = {
    [PL_MINS] = COMBO(pl_combo, KC_MINS),
    [VM_UNDS] = COMBO(vm_combo, KC_UNDS),
    [AO_ESC] = COMBO(ao_combo, KC_ESC),
    [ZSQ_CAPSWRD] = COMBO(zsq_combo, CAPSWRD),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LCKSCRN:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LGUI("q")));
            return false;
        }
        break;
    case SCRNSHT:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_LSFT("4")));
        }
    case ZMUTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LALT(SS_LSFT(SS_LGUI("a")))));
            return false;
        }
        break;
    }
    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;
    }
}
