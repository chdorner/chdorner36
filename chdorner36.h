enum layers {
    _BASE,
    _MOV,
    _SYM,
    _NUM,
    _PAD,
};

enum custom_keycodes {
    LCKSCRN = SAFE_RANGE,
    SCRNSHT,
    ZMUTE,
};

enum combos {
    // right-handed vertical combos
    L_N_LPRN,
    U_E_RPRN,
    N_M_LCBR_LBRC,
    E_COMM_RCBR_RBRC,
    O_SQ_ESC,

    // two-handed combos
    P_L_MINS,
    V_M_UNDS,
    Z_SQ_CAPSWRD,

    COMBO_LENGTH,
};
uint16_t COMBO_LEN = COMBO_LENGTH;

#define HOME_A GUI_T(KC_A)
#define HOME_R ALT_T(KC_R)
#define HOME_S CTL_T(KC_S)
#define HOME_T SFT_T(KC_T)

#define HOME_N SFT_T(KC_N)
#define HOME_E CTL_T(KC_E)
#define HOME_I ALT_T(KC_I)
#define HOME_O GUI_T(KC_O)

#define LAY_SPC  LT(_MOV, KC_SPC)
#define LAY_BSPC LT(_SYM, KC_BSPC)
#define LAY_TAB  LT(_NUM, KC_TAB)
#define LAY_PAD  MO(_PAD)

#define KC_EUR LSA(KC_2)
