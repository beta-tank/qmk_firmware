 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */ 

#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"

//Default keymap. This can be changed in Via. Use oled.c and encoder.c to change beavior that Via cannot change.
#define RAISE_T(kc) LT(_RAISE, kc)
#define LOWER_T(kc) LT(_LOWER, kc)

enum sofle_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAMING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,------------------------------------------.                     ,--------------------------------------------.
 * |  ESC  |   1  |   2  |   3  |   4  |   5  |                     |   6  |   7  |   8  |   9  |   0  |    ]    |
 * |-------+------+------+------+------+------|                     |------+------+------+------+------+---------|
 * | `     |   Q  |   W  |   E  |   R  |   T  |                     |   Y  |   U  |   I  |   O  |   P  |    [    |
 * |-------+------+------+------+------+------|                     |------+------+------+------+------+---------|
 * | LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    ,--------|   H  |   J  |   K  |   L  |   ;  | '(Ctrl) |
 * |-------+------+------+------+------+------| MUTE  |    |        |------+------+------+------+------+---------|
 * |  LAlt |   Z  |   X  |   C  |   V  |   B  |-------|    |--------|   N  |   M  |   ,  |   .  |   /  | \(RAlt) |
 * `------------------------------------------/       /     \       \-------------------------------------------'
 *           | LGUI | LAlt | TAB  | SPACE  | /Enter  /       \ ESC  \  | BckSP  | DEL  | RAlt | RGUI |
 *           |      |      | RISE | LSHIFT |/ LOWER /        \ LOWER \ | RSHIFT | RISE |      |      |
 *           `------------------------------------'           '-------''------------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_RBRC,
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  RCTL_T(KC_QUOT),
  KC_LALT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,               XXXXXXX,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  RALT_T(KC_BSLS),
  KC_LGUI, KC_LALT, RAISE_T(KC_TAB), LSFT_T(KC_SPC), LOWER_T(KC_ENT),      LOWER_T(KC_ESC), RSFT_T(KC_BSPC), RAISE_T(KC_DEL), KC_RALT, KC_RGUI
),
/* LOWER
 * ,------------------------------------------.                    ,--------------------------------------------.
 * |  F1   |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12    |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+---------|
 * | `     |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12     |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+---------|
 * | LCtrl |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  | |(Ctrl) |
 * |-------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+---------|
 * |  LAlt |  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | RAlt    |
 * `------------------------------------------/       /     \      \--------------------------------------------'
 *           | LGUI | LAlt | TAB  | SPACE  | /Enter  /       \ ESC  \  | BckSP  | DEL  | RAlt | RGUI |
 *           |      |      | RISE | LSHIFT |/ LOWER /        \ LOWER \ | RSHIFT | RISE |      |      |
 *           `------------------------------------'           '-------''------------------------------'
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, RCTL_T(KC_PIPE),
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_RALT,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                     ,---------------------------------------------------.
 * |  ESC  |      |      |      |      |      |                    |      |      |      |        |        |            |
 * |-------+------+------+------+------+------|                    |------+------+------+--------+--------+------------|
 * | `     | Ins  | Pscr | Menu |      |      |                    | Vol+ | Home |  Up  | PgUp   | ScrLk  | CapsLck    |
 * |-------+------+------+------+------+------|                    |------+------+------+--------+--------+------------|
 * | LCtrl | LAt  | LCtl |LShift|      | Caps |-------.    ,-------| Mute | Left | Down | Rigth  | Insert | Menu(Ctrl) |
 * |-------+------+------+------+------+------|  MUTE  |   |       |------+------+------+--------+--------+------------|
 * |  LAlt | Undo |  Cut | Copy | Paste|GAMING|-------|    |-------| Vol- | End  | Pscr | PgDown | PsBrk | RAlt        |
 * `------------------------------------------/       /     \      \---------------------------------------------------'
 *           | LGUI | LAlt | TAB  | SPACE  | /Enter  /       \ ESC  \  | BckSP  | DEL  | RAlt | RGUI |
 *           |      |      | RISE | LSHIFT |/ LOWER /        \ LOWER \ | RSHIFT | RISE |      |      |
 *           `------------------------------------'           '-------''------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_ESC,  _______ , _______ , _______ , _______ , _______,                              _______,  _______ , _______,  _______ ,  _______ ,_______,
  _______, KC_INS,   KC_PSCR,  KC_APP,  XXXXXXX,  XXXXXXX,                               KC_VOLU, KC_HOME,  KC_UP,     KC_PGUP,   KC_SLCK, KC_CAPS,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT, XXXXXXX,  KC_CAPS,                               KC_MUTE, KC_LEFT,  KC_DOWN,   KC_RGHT,   KC_INS,  RCTL_T(KC_APP),
  _______, KC_UNDO,  KC_CUT,   KC_COPY, KC_PASTE, TG(_GAMING),   _______,       _______, KC_VOLD, KC_END,   KC_PSCR,   KC_PGDN,   KC_PAUS, _______,
                         _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______
),
[_ADJUST] = LAYOUT_symmetric(
  _______, _______, _______, _______, _______, _______, 
  RESET,   XXXXXXX, BL_INC,  RGB_VAI, RGB_HUD, RGB_HUI,
  DEBUG,   XXXXXXX, BL_DEC,  RGB_VAD, RGB_SAD, RGB_SAI,
  XXXXXXX, BL_BRTG, BL_TOGG, RGB_TOG, RGB_RMOD,RGB_MOD, _______,
                    _______, _______, _______, _______, _______

),
/*
 * QWERTY
 * ,------------------------------------------.                     ,--------------------------------------------.
 * |  ESC  |   1  |   2  |   5  |   6  |   4  |                     |   6  |   7  |   8  |   9  |   0  |    ]    |
 * |-------+------+------+------+------+------|                     |------+------+------+------+------+---------|
 * |  OFF  |   ]  |LCtrl |   W  |SPACE |   R  |                     |   Y  |   U  |   I  |   O  |   P  |    [    |
 * |-------+------+------+------+------+------|                     |------+------+------+------+------+---------|
 * |  Tab  |LSHIFT|   A  |   S  |   D  |   F  |-------.    ,--------|   H  |   J  |   K  |   L  |   ;  | '(Ctrl) |
 * |-------+------+------+------+------+------| MUTE  |    |        |------+------+------+------+------+---------|
 * |  V    | LAlt |   Z  |   X  |   C  |   G  |-------|    |--------|   N  |   M  |   ,  |   .  |   /  | \(RAlt) |
 * `------------------------------------------/       /     \       \-------------------------------------------'
 *           |   6   |   5   |   Q   |    E    |  4  /       \ ESC  \  | BckSP  | DEL  | RAlt | RGUI |
 *           `------------------------------------'           '-------''------------------------------'
 */

[_GAMING] = LAYOUT(
  KC_ESC,      KC_1,      KC_2,    KC_5,    KC_6,    KC_4,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_RBRC,
  TG(_GAMING), KC_RBRC,   KC_LCTL, KC_W,    KC_SPC,  KC_R,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,
  KC_TAB,      KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  RCTL_T(KC_QUOT),
  KC_V,        KC_LALT,   KC_Z,    KC_X,    KC_C,    KC_G, KC_MUTE,               XXXXXXX,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  RALT_T(KC_BSLS),
  KC_6,        KC_5,      KC_Q,    KC_E,    KC_4,                                 TG(_GAMING), TG(_GAMING), TG(_GAMING), KC_RALT, KC_RGUI
)
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}