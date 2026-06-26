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

enum my_keycodes  {
    // LAYER_UP = SAFE_RANGE,
    LAYER_UP = QK_USER,
    LAYER_DOWN,
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


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

// Programming the Behavior of Any Keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER_UP:
            if (record->event.pressed) {
                layer_on(get_highest_layer(layer_state) + 1);
            }
            return false; // Skip all further processing of this key
        case LAYER_DOWN:
            if (record->event.pressed) {
                layer_off(get_highest_layer(layer_state));
            }
            return false; // Skip all further processing of this key
    }
    return true;
}

// bool oled_task_user(void) {
//     // Título / estado de capa
//     oled_write_P(PSTR("Capa: "), false);

//     switch (get_highest_layer(layer_state)) {
//         case _DVORAK:
//             oled_write_P(PSTR("Dvorak\n"), false);
//             break;
//         case _FLECHASNUM:
//             oled_write_P(PSTR("FlechaNum\n"), false);
//             break;
//         case _FUNSYM:
//             oled_write_P(PSTR("FnSym\n"), false);
//             break;
//         case _ADJUST:
//             oled_write_P(PSTR("Config\n"), false);
//             break;
//         default:
//             oled_write_P(PSTR("Undefined\n"), false);
//     }
//     return false;
// }


// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//         case _FLECHASNUM:
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE);
//             break;
//         case _FUNSYM:
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
//             break;
//         case _ADJUST:
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
//             break;
//         default: // _DVORAK
//             rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
//             break;
//     }
//     return state;
// }

void keyboard_post_init_user(void) {
    // Call the post init code.
    rgblight_enable_noeeprom(); // enables Rgb, without saving settings
    rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3); // sets mode to Fast breathing without saving
}

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
        KC_ESC    , KC_LWIN   , XXXXXXX   , XXXXXXX   , XXXXXXX   , UG_TOGG   ,                             KC_BRIU   , KC_MUTE   , KC_VOLU   , KC_MFFD   , XXXXXXX   , KC_BSPC   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        KC_TAB    , UG_HUEU   , UG_SATU   , UG_VALU   , UG_NEXT   , UG_SPDU   ,                             KC_BRID   , KC_MPLY   , KC_VOLD   , KC_MRWD   , XXXXXXX   , QK_BOOT   ,
    //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
        TD(SHFCAP), UG_HUED   , UG_SATD   , UG_VALD   , UG_PREV   , UG_SPDD   ,                             XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , KC_DEL    ,
    //`-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
                                                          KC_SPC  , LAYER_DOWN, TD(ALT_LR),     KC_LCTL   , XXXXXXX   , KC_ENT
    //                                                  `---------------------------------´   `---------------------------------´
    ),
    // [3] = LAYOUT_split_3x6_3(
    // //,-----------------------------------------------------------------------.                           ,-----------------------------------------------------------------------.
    //     KC_ESC    , KC_LWIN   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,                             KC_BRIU   , KC_MUTE   , KC_VOLU   , KC_MFFD   , XXXXXXX   , KC_BSPC   ,
    // //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
    //     KC_TAB    , RGB_HUI   , RGB_SAT   , RGB_VAT   , RGB_MOD   , XXXXXXX   ,                             KC_BRID   , KC_MPLY   , KC_VOLD   , KC_MRWD   , XXXXXXX   , QK_BOOT   ,
    // //|-----------+-----------+-----------+-----------+-----------+-----------|                           |-----------+-----------+-----------+-----------+-----------+-----------|
    //     TD(SHFCAP), RGB_HUD   , RGB_SAD   , RGB_VAD   , RGB_RMOD  , RGB_TOG   ,                             XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   , KC_DEL    ,
    // //`-----------+-----------+-----------+-----------+-----------+-----------+-----------|   |-----------+-----------+-----------+-----------+-----------+-----------+-----------|
    //                                                       KC_SPC  , LAYER_DOWN, TD(ALT_LR),     KC_LCTL   , XXXXXXX   , KC_ENT
    // //                                                  `---------------------------------´   `---------------------------------´
    // ),
};
