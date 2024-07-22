/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                        KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,                 KC_LEFT_BRACKET,
    KC_LEFT_CTRL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                        KC_H,     KC_J,     KC_K,     KC_L,     RSFT_T(KC_SEMICOLON), RCTL_T(KC_QUOTE),
    KC_LEFT_SHIFT, KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                                        KC_N,     KC_M,     KC_COMM,  KC_DOT,   RALT_T(KC_SLASH),     KC_INTERNATIONAL_1,
              KC_LEFT_CTRL, KC_LEFT_ALT, KC_LEFT_GUI, LT(2,KC_LANGUAGE_2), LT(3,KC_BACKSPACE),    LT(2,KC_ENTER), LT(1,KC_LANGUAGE_1), _______, _______, KC_ESCAPE
  ),

  [1] = LAYOUT_universal(
    KC_TRANSPARENT, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                                        S(KC_6),     S(KC_7),     S(KC_8),          S(KC_9),      S(KC_INTERNATIONAL_3), S(KC_LEFT_BRACKET),
    KC_TRANSPARENT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                          S(KC_EQUAL), KC_MINUS,    KC_RIGHT_BRACKET, KC_BACKSLASH, S(KC_SEMICOLON),       S(KC_QUOTE),
    KC_TRANSPARENT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                                         KC_EQUAL,    S(KC_MINUS), S(KC_COMMA),      S(KC_DOT),    S(KC_SLSH),            S(KC_INTERNATIONAL_1),
              KC_F11, KC_F12, KC_TRANSPARENT, KC_LEFT_ALT, KC_TRANSPARENT,                        KC_TRANSPARENT, KC_TRANSPARENT, _______, _______, KC_TRANSPARENT
  ),

  [2] = LAYOUT_universal(
    KC_TRANSPARENT, KC_SLASH,    KC_7, KC_8, KC_9, KC_MINUS,                                            KC_SPACE,     KC_MS_BTN4, KC_NO,   KC_MS_BTN5, KC_MS_BTN3, KC_DELETE,
    KC_TRANSPARENT, S(KC_QUOTE), KC_4, KC_5, KC_6, S(KC_SEMICOLON),                                     KC_PAGE_UP,   KC_MS_BTN1, KC_UP,   KC_MS_BTN2, KC_HOME,    A(KC_PRINT_SCREEN),
    KC_TRANSPARENT, KC_0,        KC_1, KC_2, KC_3, KC_DOT,                                              KC_PAGE_DOWN, KC_LEFT,    KC_DOWN, KC_RIGHT,   KC_END,     KC_PRINT_SCREEN,
              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, _______, _______, KC_TRANSPARENT
  ),

  [3] = LAYOUT_universal(
    LCA(KC_PAUSE),  QK_KB_1,  QK_KB_14, QK_KB_13, QK_KB_15, QK_KB_0,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANSPARENT, QK_KB_10, QK_KB_11, QK_KB_8,  QK_KB_2,  QK_KB_4,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRANSPARENT, RGB_TOG,  QK_KB_12, QK_KB_9,  QK_KB_3,  QK_KB_5,                                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, _______, _______, RCS(KC_ESCAPE)
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
  
    uint8_t layer = biton32(state);
    switch (layer) {
      case 0:
        rgblight_sethsv(HSV_BLACK);
        break;
      case 1:
        rgblight_sethsv(HSV_BLUE);
        break;
      case 2:
        rgblight_sethsv(HSV_RED);
        break;
      case 3:
        rgblight_sethsv(HSV_GREEN);
        break;
    }
  
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
