/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_spanish_latin_america.h"
#include "quantum.h"
// #include "keymap_extras/keymap_spanish_latin_america.h"
// #include "users/gseguelg/_example.h"

enum custom_keycodes {
    LAYER_UP = QK_USER,
    LAYER_DOWN,
    RGB_HUI,
    RGB_HUD,
    RGB_SAT,
    RGB_SAD,
    RGB_VAT,
    RGB_VAD,
    RGB_MOD,
    RGB_RMOD,
    RGB_TOG,
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

// enum layers { _BASE, _LOWER, _RAISE, _ADJUST };

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case _LOWER:
//             rgblight_sethsv_noeeprom(HSV_BLUE);
//             break;
//         case _RAISE:
//             rgblight_sethsv_noeeprom(HSV_RED);
//             break;
//         case _ADJUST:
//             rgblight_sethsv_noeeprom(HSV_GREEN);
//             break;
//         default: // _BASE
//             rgblight_sethsv_noeeprom(HSV_WHITE);
//             break;
//     }
//     return state;
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                           ,-----------------------------------------------------------------------.
        KC_ESC    , KC_LWIN   , KC_PSCR   , ES_NTIL   , KC_P      , KC_Y      ,                             KC_F      , KC_G      , KC_C      , KC_R      , KC_L      , KC_BSPC   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TAB    , KC_A      , KC_O      , KC_E      , KC_U      , KC_I      ,                             KC_D      , KC_H      , KC_T      , KC_N      , KC_S      , TD(ACNT_I),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(SHFCAP), ES_LABK   , KC_Q      , KC_J      , KC_K      , KC_X      ,                             KC_B      , KC_M      , KC_W      , KC_V      , KC_Z      , KC_DEL    ,
    //`-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                          KC_SPC  , XXXXXXX   , TD(ALT_LR),     KC_LCTL   , LAYER_UP  , KC_ENT
    //                                                  `---------------------------------´   `---------------------------------´
    ),

    [1] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                           ,-----------------------------------------------------------------------.
        KC_ESC    , KC_LWIN   , XXXXXXX   , KC_UP     , XXXXXXX   , KC_PGUP   ,                            KC_HOME    , KC_7      , KC_8      , KC_9      , TD(PLSSTR), KC_BSPC   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TAB    , XXXXXXX   , KC_LEFT   , KC_DOWN   , KC_RGHT   , KC_PGDN   ,                            KC_END     , KC_4      , KC_5      , KC_6      , KC_0      , TD(SLASHS),
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(SHFCAP), KC_INS    , KC_APP    , KC_CALC   , KC_PSCR   , XXXXXXX   ,                            TD(DOTCLN) , KC_1      , KC_2      , KC_3      , TD(MNSUDR), KC_DEL    ,
    //`-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                          KC_SPC  , LAYER_DOWN, TD(ALT_LR),     KC_LCTL   , LAYER_UP  , KC_ENT
    //                                                  `---------------------------------´   `---------------------------------´
    ),

    [2] = LAYOUT_split_3x6_3(
    //,----------------------------------------------------------------------.                            ,-----------------------------------------------------------------------.
        KC_ESC    , KC_LWIN   , KC_F1     , KC_F2     , KC_F3     , KC_F4     ,                             XXXXXXX   , TD(PRN_LR), TD(I_EXCL), TD(HSHEQL), XXXXXXX   , KC_BSPC   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TAB    , XXXXXXX   , KC_F5     , KC_F6     , KC_F7     , KC_F8     ,                             XXXXXXX   , TD(BRC_LR), TD(I_QUES), TD(TLDNOT), XXXXXXX   , XXXXXXX   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(SHFCAP), XXXXXXX   , KC_F9     , KC_F10    , KC_F11    , KC_F12    ,                             XXXXXXX   , TD(CRB_LR), TD(PIPDEG), TD(TLDNOT), XXXXXXX   , KC_DEL    ,
    //`-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                          KC_SPC  , LAYER_DOWN, TD(ALT_LR),     KC_LCTL   , LAYER_UP  , KC_ENT
    //                                                  `---------------------------------´   `---------------------------------´
    ),

    [3] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                           ,-----------------------------------------------------------------------.
        KC_ESC    , KC_LWIN   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,                             KC_BRIU   , KC_MUTE   , KC_VOLU   , KC_MFFD   , XXXXXXX   , KC_BSPC   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TAB    , XXXXXXX   , XXXXXXX    , XXXXXXX   , XXXXXXX   , XXXXXXX   ,                             KC_BRID   , KC_MPLY   , KC_VOLD   , KC_MRWD   , XXXXXXX   , XXXXXXX   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(SHFCAP), XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,                             XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , KC_DEL    ,
    //`-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                          KC_SPC  , LAYER_DOWN, TD(ALT_LR),     KC_LCTL   , LAYER_UP  , KC_ENT
    //                                                  `---------------------------------´   `---------------------------------´
    ),

    [4] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------.                           ,-----------------------------------------------------------------------.
        KC_ESC    , KC_LWIN   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,                             QK_BOOT   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , KC_BSPC   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TAB    , RGB_HUI   , RGB_SAT   , RGB_VAT   , RGB_MOD   , XXXXXXX   ,                             XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(SHFCAP), RGB_HUD   , RGB_SAD   , RGB_VAD   , RGB_RMOD  , RGB_TOG   ,                             XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , KC_DEL    ,
    //`-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                          KC_SPC  , LAYER_DOWN, TD(ALT_LR),     KC_LCTL   , XXXXXXX   , KC_ENT
    //                                                  `---------------------------------´   `---------------------------------´
    )

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif


// extern tap_dance_action_t tap_dance_actions[TD_COUNT];


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER_UP:
            if (record->event.pressed) {
                layer_on(get_highest_layer(layer_state) + 1);
            }
            return false;
        case LAYER_DOWN:
            if (record->event.pressed) {
                layer_off(get_highest_layer(layer_state));
            }
            return false;
        // RGB keycodes mapped to RGB matrix controls
        case RGB_HUI:
            if (record->event.pressed) { rgb_matrix_increase_hue(); }
            return false;
        case RGB_HUD:
            if (record->event.pressed) { rgb_matrix_decrease_hue(); }
            return false;
        case RGB_SAT:
            if (record->event.pressed) { rgb_matrix_increase_sat(); }
            return false;
        case RGB_SAD:
            if (record->event.pressed) { rgb_matrix_decrease_sat(); }
            return false;
        case RGB_VAT:
            if (record->event.pressed) { rgb_matrix_increase_val(); }
            return false;
        case RGB_VAD:
            if (record->event.pressed) { rgb_matrix_decrease_val(); }
            return false;
        case RGB_MOD:
            if (record->event.pressed) { rgb_matrix_step(); }
            return false;
        case RGB_RMOD:
            if (record->event.pressed) { rgb_matrix_step_reverse(); }
            return false;
        case RGB_TOG:
            if (record->event.pressed) { rgb_matrix_toggle(); }
            return false;
    }
    return true;
}
