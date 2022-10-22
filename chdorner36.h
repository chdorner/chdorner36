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
    PL_MINS,
    VM_UNDS,
    AO_ESC,
    ZSQ_CAPSWRD,
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
