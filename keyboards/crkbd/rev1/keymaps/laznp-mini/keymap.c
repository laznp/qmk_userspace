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

enum {
    TD_SCLN_ESC = 0,
    TD_C_COPY = 1,
    TD_V_PASTE = 2,
};

// toggle layer
const uint16_t PROGMEM switch_layer0[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM switch_layer3[] = {KC_U, KC_I, KC_O, COMBO_END};

// left side
const uint16_t PROGMEM cmb_osm_lgui[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_osm_lsft[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_osm_lctl[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_osm_lguisft[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_osm_lctlsft[] = {KC_S, KC_D, KC_V, COMBO_END};

// right side
const uint16_t PROGMEM cmb_osm_rsft[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_osm_rgui[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_osm_rctl[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_osm_rguisft[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_osm_rctlsft[] = {KC_M, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_caps[] = {KC_D, KC_F, KC_J, KC_K, COMBO_END};

tap_dance_action_t tap_dance_actions[] = {
    // Tap Once Quote, Tap Twice Escape
    [TD_SCLN_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ESC),
    [TD_C_COPY] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_COPY),
    [TD_V_PASTE] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_PASTE)
};

combo_t key_combos[] = {
    COMBO(switch_layer0, TO(0)),
    COMBO(switch_layer3, TO(3)),
    COMBO(cmb_osm_lgui, OSM(MOD_LGUI)),
    COMBO(cmb_osm_lsft, OSM(MOD_LSFT)),
    COMBO(cmb_osm_lctl, OSM(MOD_LCTL)),
    COMBO(cmb_osm_lguisft, OSM(MOD_LGUI | MOD_LSFT)),
    COMBO(cmb_osm_lctlsft, OSM(MOD_LCTL | MOD_LSFT)),
    COMBO(cmb_osm_rgui, OSM(MOD_RGUI)),
    COMBO(cmb_osm_rsft, OSM(MOD_RSFT)),
    COMBO(cmb_osm_rctl, OSM(MOD_RCTL)),
    COMBO(cmb_osm_rguisft, OSM(MOD_RGUI | MOD_RSFT)),
    COMBO(cmb_osm_rctlsft, OSM(MOD_RCTL | MOD_RSFT)),
    COMBO(cmb_caps, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, TD(TD_SCLN_ESC), KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_Z,    KC_X, TD(TD_C_COPY), TD(TD_V_PASTE), KC_B,            KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL,   MO(2),  LSFT_T(KC_ENT),     KC_SPC,   MO(1), KC_TAB
                                      //`--------------------------'  `--------------------------'
  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_NO ,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),            LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0), KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_NO ,KC_LBRC, LSFT(KC_LBRC),LSFT(KC_QUOT),LSFT(KC_RBRC),KC_RBRC,       LSFT(KC_EQL), KC_EQL, KC_MINS,LSFT(KC_MINS) ,KC_BSPC, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_NO ,LSFT(KC_GRV),KC_GRV,KC_QUOT,_______,_______,                      _______,_______,_______,_______,LSFT(KC_BSLS), KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, _______, _______,     _______, _______, KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
    [2] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO  ,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,   KC_0 ,  KC_NO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO  , _______, _______, _______,    KC_6, KC_KB_VOLUME_UP,              KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, KC_NO,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO  , _______, _______, KC_COPY,    KC_3, KC_KB_VOLUME_DOWN,            _______, _______, _______, _______, KC_DEL , KC_NO,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,     _______, _______, _______
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
                                          KC_LCTL,    KC_ENT,  KC_SPC,  _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};
