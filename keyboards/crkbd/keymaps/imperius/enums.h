#pragma once


enum my_keycodes  {
    // LAYER_UP = SAFE_RANGE,
    LAYER_UP = QK_USER,
    LAYER_DOWN,
    SS_HELLO,
    // RGB_HUI,
    // RGB_HUD,
    // RGB_SAT,
    // RGB_SAD,
    // RGB_VAT,
    // RGB_VAD,
    // RGB_MOD,
    // RGB_RMOD,
    // RGB_TOG,
};

enum tap_dance_codes {
    ALT_LR = 0,
    SHFCAP,
    PLSSTR,
    MNSUDR,
    DOTCLN,
    COMSCL,
    PRN_LR,
    BRC_LR,
    CRB_LR,
    I_EXCL,
    I_QUES,
    SLASHS,
    PIPDEG,
    TLDNOT,
    HSHEQL,
    AT_DLR,
    ACNT_I,
    CMAPCM,
    UMBHAT
};

enum layers { _DVORAK, _FLECHASNUM, _FUNSYM, _ADJUST };  // 0, 1, 2, 3

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [ALT_LR]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),   // ALT left or right
    [SHFCAP]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),   // SHIFT or CAPS
    [PLSSTR]  = ACTION_TAP_DANCE_DOUBLE(ES_PLUS, ES_ASTR),   // + or *
    [MNSUDR]  = ACTION_TAP_DANCE_DOUBLE(ES_MINS, ES_UNDS),   // - or _
    [DOTCLN]  = ACTION_TAP_DANCE_DOUBLE(ES_DOT, ES_COLN),    // . or :
    [COMSCL]  = ACTION_TAP_DANCE_DOUBLE(ES_COMM, ES_SCLN),   // , or ;
    [PRN_LR]  = ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_RPRN),   // ( or )
    [BRC_LR]  = ACTION_TAP_DANCE_DOUBLE(ES_LBRC, ES_RBRC),   // [ or ]
    [CRB_LR]  = ACTION_TAP_DANCE_DOUBLE(ES_LCBR, ES_RCBR),   // { or }
    [I_EXCL]  = ACTION_TAP_DANCE_DOUBLE(ES_IEXL, ES_EXLM),   // ¡ or !
    [I_QUES]  = ACTION_TAP_DANCE_DOUBLE(ES_IQUE, ES_QUES),   // ¿ or ?
    [SLASHS]  = ACTION_TAP_DANCE_DOUBLE(ES_SLSH, ES_BSLS),   // / or (backslash)
    [PIPDEG]  = ACTION_TAP_DANCE_DOUBLE(ES_PIPE, ES_MORD),   // | or °
    [TLDNOT]  = ACTION_TAP_DANCE_DOUBLE(ES_TILD, ES_NOT),    // ~ or ¬
    [HSHEQL]  = ACTION_TAP_DANCE_DOUBLE(ES_NUMB, ES_EQL),    // # or =
    [AT_DLR]  = ACTION_TAP_DANCE_DOUBLE(ES_AT, ES_DLR),      // @ or $
    [ACNT_I]  = ACTION_TAP_DANCE_DOUBLE(ES_ACUT, ES_DIAE),   // ´ or ¨
    [CMAPCM]  = ACTION_TAP_DANCE_DOUBLE(ES_PERC, ES_AMPR),   // % or &
    [UMBHAT]  = ACTION_TAP_DANCE_DOUBLE(ES_CIRC, KC_NO),     // ^
};
