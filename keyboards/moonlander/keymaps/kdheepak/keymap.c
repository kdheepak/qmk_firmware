#include QMK_KEYBOARD_H
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_BRID,                    KC_BRIU, KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,   KC_LBRC,                    KC_RBRC, KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,   KC_BSLS,                    KC_SLSH, KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOTE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                                        KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_UP,   KC_SFTENT,
    KC_LCTL, KC_LALT, KC_HYPR, MO(1),   CMD_T(KC_LBRC),   RGB_MOD,                    RGB_TOG,          ROPT_T(KC_RBRC),  MO(2),   KC_LEFT, KC_DOWN, KC_RIGHT,
                                                  KC_SPC, MO(1),   MO(3),    MO(4),   MO(2),   KC_SPC
  ),
  [1] = LAYOUT_moonlander(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_VOLD,                    KC_VOLU, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL0, _______, KC_WH_L,                    KC_WH_R, _______, _______, _______, _______, _______, KC_DEL,
    KC_GRV,  KC_MS_L, KC_MS_D, KC_MS_R, KC_ACL1, _______, KC_WH_D,                    KC_WH_U, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
    _______, KC_BTN3, KC_BTN4, KC_BTN5, KC_ACL2, _______,                                      _______, _______, _______, _______, _______, KC_ENT,
    _______, _______, _______, _______, _______,          _______,                    _______,          _______, _______, _______, _______, _______,
                                                 _______, _______, _______,  _______, _______, _______
  ),
  [2] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,                    _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______,
    RESET,   KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, _______, _______,                    _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                                      _______, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, _______,
    _______, KC_COMM, _______, _______, _______,          _______,                    _______,          KC_PEQL, KC_P0,   KC_PDOT, KC_PPLS, _______,
                                                 _______, _______, _______,  _______, _______, _______
  ),
  [3] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,                    _______,          _______, _______, _______, _______, _______,
                                                 _______, _______, _______,  _______, _______, _______
  ),
  [4] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,                    _______,          _______, _______, _______, _______, _______,
                                                 _______, _______, _______,  _______, _______, _______
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case ADJUST:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}
