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

#include "enums.h"
#ifdef OLED_ENABLE
    #include "oled.c"
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
        case SS_HELLO:
            if (record->event.pressed) {
                SEND_STRING("Hello, world!\n");
            }
            return false;
    }
    return true;
}


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) { // CURRENT LAYER
        case _FLECHASNUM:
            // rgblight_mode_noeeprom(RGBLIGHT_MODE_CHRISTMAS);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_SNAKE + 5);
            break;
        case _FUNSYM:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_TWINKLE + 5);
            // rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD);
            break;
        case _ADJUST:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
            break;
        default: // _DVORAK
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
            break;
    }
    return state;
}

void keyboard_post_init_user(void) {
    // Call of post init code.
    rgblight_enable_noeeprom(); // enables Rgb, without saving settings
    // rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2); // sets mode to Faster breathing at start
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


#ifdef ENCODER_MAP_ENABLE
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
    };
#endif