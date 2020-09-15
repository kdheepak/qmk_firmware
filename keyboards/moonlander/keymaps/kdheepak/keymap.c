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
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,     MO(1),                     MO(2),   KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,   KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,     KC_LBRC,                   KC_RBRC, KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,      KC_BSPC,
    KC_GESC, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,     KC_BSLS,                   KC_SLSH, KC_H,     KC_J,     KC_K,     KC_L,    KC_SCOLON, KC_QUOTE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,                                         KC_N,     KC_M,     KC_COMMA, KC_DOT,  KC_UP,     KC_SFTENT,
    KC_LCTL, KC_LALT, KC_HYPR, KC_LGUI, MO(1),    _______,                                      _______,  MO(2),    KC_RALT,  KC_LEFT, KC_DOWN,   KC_RIGHT,
                                                  KC_SPC,   _______, _______, _______, _______, KC_SPC
  ),
  [1] = LAYOUT_moonlander(
    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          _______,                                        _______,      KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
    _______,        KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        _______,                                        _______,      KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
    KC_GRAVE,       KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       _______,                                        _______,      KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_KP_PLUS,     _______,
    _______,        KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                                                      KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      _______,
    _______,        KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                      RGB_TOG,        _______,        KC_DOT,         KC_0,           KC_EQUAL,       _______,
                                                                                    RGB_VAD,        _______, TOGGLE_LAYER_COLOR,RGB_SLD,     _______, RGB_HUI
  ),
  [2] = LAYOUT_moonlander(
    AU_TOG,         _______,        _______,        _______,        _______,        _______,        _______,                                        _______,        _______,      _______,        _______,        _______,        _______,        RESET,
    MU_TOG,         _______,        _______,        KC_MS_UP,       _______,        _______,        _______,                                        _______,        _______,      _______,        _______,        _______,        _______,        _______,
    MU_MOD,         _______,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    _______,        _______,                                        _______,        _______,      _______,        _______,        _______,        _______,        KC_MEDIA_PLAY_PAUSE,
    _______,        _______,        _______,        _______,        _______,        _______,                                                                        _______,      _______,        KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,_______, _______,
    _______,        _______,        _______,        KC_MS_BTN1,     KC_MS_BTN2,     _______,                                                                        _______,      KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  _______, _______,
                                                                                    _______, _______, _______,                  _______, _______, KC_WWW_BACK
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}
