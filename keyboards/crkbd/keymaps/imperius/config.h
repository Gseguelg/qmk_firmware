/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C
// #define RGBLIGHT_MAX_LAYERS 32

#define RGBLIGHT_LAYERS
//#define QUICK_TAP_TERM 0
#define TAPPING_TERM 200  // tapdance time gap
// #define TAP_DANCE_MAX_SIMULTANEOUS 5
// #define RGBLIGHT_SLEEP  // enable rgblight_suspend() and rgblight_wakeup() in keymap.c
// #define RGBLIGHT_TIMEOUT 900000  // ms to wait until rgblight time out, 900K ms is 15min.

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_MODE_BREATHING
    #define RGBLIGHT_MODE_RAINBOW_MOOD
    #define RGBLIGHT_MODE_RAINBOW_SWIRL
    #define RGBLIGHT_MODE_SNAKE
    #define RGBLIGHT_MODE_KNIGHT
    #define RGBLIGHT_MODE_CHRISTMAS
    #define RGBLIGHT_MODE_STATIC_GRADIENT
    #define RGBLIGHT_MODE_RGB_TEST
    #define RGBLIGHT_MODE_ALTERNATING
    #define RGBLIGHT_MODE_TWINKLE

    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif
