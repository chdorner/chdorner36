#include <stdio.h>
#include QMK_KEYBOARD_H
#include "chdorner36.h"

const key_override_t ko_bspc_del  = ko_make_basic(MOD_MASK_SHIFT, LAY_BSPC, KC_DEL);
const key_override_t ko_dlr_euro  = ko_make_basic(MOD_MASK_SHIFT, KC_DLR, KC_EUR);
const key_override_t ko_eql_no    = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);
const key_override_t ko_ques_exlm = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t ko_grv_no    = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_GRV);
const key_override_t ko_bsls_no   = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_BSLS);
const key_override_t ko_slsh_no   = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_SLSH);
const key_override_t **key_overrides = (const key_override_t *[]) {
    &ko_bspc_del,
    &ko_dlr_euro,
    &ko_eql_no,
    &ko_ques_exlm,
    &ko_grv_no,
    &ko_bsls_no,
    &ko_slsh_no,
    NULL
};

//keytographer:generated:start
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, HOME_A, HOME_R, HOME_S, HOME_T, KC_D, KC_H, HOME_N, HOME_E, HOME_I, HOME_O, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_QUOT, LAY_MCR, LAY_SPC, LAY_BSPC, LAY_TAB, KC_ENT, LAY_MCR),
    [1] = LAYOUT_split_3x5_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_CYW, KC_NAVB, KC_NAVF, KC_NO, KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, KC_NO, KC_TRNS, KC_BSPC, KC_TAB, KC_ENT, KC_NO),
    [2] = LAYOUT_split_3x5_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PLUS, KC_EQL, KC_AMPR, KC_ASTR, KC_PERC, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_TILD, KC_QUES, KC_HASH, KC_GRV, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DLR, KC_AT, KC_BSLS, KC_PIPE, KC_CIRC, KC_NO, KC_SPC, KC_TRNS, KC_TAB, KC_ENT, KC_NO),
    [3] = LAYOUT_split_3x5_3(KC_NO, KC_P7, KC_P8, KC_P9, KC_EQL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, KC_P4, KC_P5, KC_P6, KC_MINS, KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_DOT, KC_P1, KC_P2, KC_P3, KC_PLUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SPC, KC_BSPC, KC_TRNS, KC_ENT, KC_NO),
    [4] = LAYOUT_split_3x5_3(LCKSCRN, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SCRNSHT, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO, ZMUTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_NO, KC_MUTE, ZMUTE, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS)
};
//keytographer:generated:end

// right-handed vertical combos
const uint16_t PROGMEM l_n_combo[]    = {KC_L, HOME_N, COMBO_END};
const uint16_t PROGMEM u_e_combo[]    = {KC_U, HOME_E, COMBO_END};
const uint16_t PROGMEM n_m_combo[]    = {HOME_N, KC_M, COMBO_END};
const uint16_t PROGMEM e_comm_combo[] = {HOME_E, KC_COMM, COMBO_END};
const uint16_t PROGMEM o_sq_combo[]   = {HOME_O, KC_QUOT, COMBO_END};

// right-handed horizontal combos
const uint16_t PROGMEM k_m_combo[] = {KC_K, KC_M, COMBO_END};

// left-handed horizontal combos
const uint16_t PROGMEM v_b_combo[] = {KC_V, KC_B, COMBO_END};

// two-handed combos
const uint16_t PROGMEM p_l_combo[]  = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM v_m_combo[]  = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM a_o_combo[]  = {HOME_A, HOME_O, COMBO_END};
const uint16_t PROGMEM z_sq_combo[] = {KC_Z, KC_QUOT, COMBO_END};

combo_t key_combos[] = {
    // right-handed vertical combos
    [L_N_LPRN]         = COMBO(l_n_combo, KC_LPRN),
    [U_E_RPRN]         = COMBO(u_e_combo, KC_RPRN),
    [N_M_LCBR_LBRC]    = COMBO_ACTION(n_m_combo),
    [E_COMM_RCBR_RBRC] = COMBO_ACTION(e_comm_combo),
    [O_SQ_ESC]         = COMBO(o_sq_combo, KC_ESC),

    // right-handed horizontal combos
    [K_M_APPSWCH] = COMBO(k_m_combo, APPSWCH),

    // left-handed horizontal combos
    [V_B_APPSWCH] = COMBO(v_b_combo, APPSWCH),

    // two-handed combos
    [P_L_MINS]     = COMBO(p_l_combo, KC_MINS),
    [V_M_UNDS]     = COMBO(v_m_combo, KC_UNDS),
    [A_O_ESC]      = COMBO(a_o_combo, KC_ESC),
    [Z_SQ_CAPSWRD] = COMBO(z_sq_combo, CAPSWRD),
};

uint8_t mod_state;
void process_combo_event(uint16_t combo_index, bool pressed) {
    mod_state = get_mods();

    switch(combo_index) {
        case N_M_LCBR_LBRC:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_LBRC);
                    set_mods(mod_state);
                } else {
                    tap_code16(KC_LCBR);
                }
            }
            break;
        case E_COMM_RCBR_RBRC:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    tap_code16(KC_RBRC);
                    set_mods(mod_state);
                } else {
                    tap_code16(KC_RCBR);
                }
            }
    }
};

void process_app_switcher(bool *active, uint16_t keycode, keyrecord_t *record) {
    if (keycode == APPSWCH) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(KC_LGUI);
            }
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }

    } else if (*active) {
        unregister_code16(KC_LGUI);
        *active = false;
    }
}

bool app_switcher_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_app_switcher(&app_switcher_active, keycode, record);

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
