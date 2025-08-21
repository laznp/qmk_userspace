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
/* #include "g/keymap_combo.h" */

/* enum { */
    /* TD_SCLN_ESC = 0, */
/* }; */

#include "sm_td.h"
/* tap_dance_action_t tap_dance_actions[] = { */
    /* // Tap Once Quote, Tap Twice Escape */
    /* [TD_SCLN_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ESC), */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   MO(2),  KC_ENT,     KC_SPC,   MO(1), KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_NO ,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),            LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0), KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_NO ,KC_LBRC, LSFT(KC_LBRC),LSFT(KC_QUOT),LSFT(KC_RBRC),KC_RBRC,       LSFT(KC_EQL), KC_EQL, KC_MINS,LSFT(KC_MINS) ,KC_BSPC, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_NO ,LSFT(KC_GRV),KC_GRV,KC_QUOT,_______,_______,                      _______,_______,_______,KC_BSLS,LSFT(KC_BSLS), KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, _______, _______,     _______, _______, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
    [2] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO  ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0 ,  KC_NO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO  ,  KC_TAB, _______, _______, _______, KC_KB_VOLUME_UP,              KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, KC_NO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO  , KC_PSCR, _______, KC_COPY, KC_PASTE, KC_KB_VOLUME_DOWN,            _______, _______, _______, _______, KC_DEL , KC_NO,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, _______, _______,     _______, _______, KC_NO
                                        //`--------------------------'  `--------------------------'
  ),
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO, KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,                     _______, _______, _______, _______, _______,   KC_NO,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,                     _______, _______, _______, _______, _______,   KC_NO,
  //|--------+--------+--------+--------+--------|--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,                     _______, _______, _______, _______, _______,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,    KC_ENT,  KC_SPC,  _______, _______, KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(KC_A, KC_LSFT)
        SMTD_MT(KC_S, KC_LCTL)
        SMTD_MT(KC_D, KC_LGUI)
        SMTD_MT(KC_F, KC_LALT)
    }
    return SMTD_RESOLUTION_UNHANDLED;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    return true;
}
