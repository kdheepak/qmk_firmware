#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"

#define A_BSPC  LALT(KC_BSPC)
#define A_LEFT  LALT(KC_LEFT)
#define A_RGHT  LALT(KC_RGHT)
#define C_TAB   LCTL(KC_TAB)
#define GSL     LGUI(S(KC_LEFT))
#define GSR     LGUI(S(KC_RGHT))
#define G_TAB   LGUI(KC_TAB)
#define G_GRV   LGUI(KC_GRV)
#define SftEnt  SFT_T(KC_ENT)
#define NAV     LT(2, KC_TAB)

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


enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

//tapdance declarations
enum {
  SFT_LCK
};

#define SftLck TD(SFT_LCK) /* alias for tapdance */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyper| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_planck_grid(
          KC_ESCAPE , KC_Q     , KC_W    , KC_E    , KC_R  , KC_T     , KC_Y  , KC_U  , KC_I     , KC_O    , KC_P      , KC_BSPACE ,
          KC_TAB    , KC_A     , KC_S    , KC_D    , KC_F  , KC_G     , KC_H  , KC_J  , KC_K     , KC_L    , KC_SCOLON , KC_QUOTE  ,
          SftLck    , KC_Z     , KC_X    , KC_C    , KC_V  , KC_B     , KC_N  , KC_M  , KC_COMMA , KC_DOT  , KC_SLASH  , KC_SFTENT ,
          KC_HYPR   , KC_LCTRL , KC_LALT , KC_LGUI , LOWER , KC_SPACE , KC_NO , RAISE , KC_LEFT  , KC_DOWN , KC_UP     , KC_RIGHT
          ),

  [_LOWER] = LAYOUT_planck_grid(
          KC_DELETE , KC_1    , KC_2    , KC_3    , KC_4     , KC_5    , KC_6     , KC_7     , KC_8                , KC_9              , KC_0            , _______             ,
          _______   , KC_EXLM , KC_AT   , KC_HASH , KC_DLR   , KC_PERC , KC_CIRC  , KC_AMPR  , KC_ASTR             , KC_LPRN           , KC_RPRN         , KC_GRAVE            ,
          _______   , KC_UNDO , KC_CUT  , KC_COPY , KC_PASTE , KC_FIND , KC_MINUS , KC_EQUAL , KC_LBRACKET         , KC_RBRACKET       , KC_BSLASH       , _______             ,
          _______   , _______ , _______ , _______ , _______  , _______ , KC_NO    , _______  , KC_MEDIA_NEXT_TRACK , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , KC_MEDIA_PLAY_PAUSE
          )         ,

  [_RAISE] = LAYOUT_planck_grid(
          KC_DELETE , KC_F1   , KC_F2   , KC_F3   , KC_F4   , _______ , _______ , KC_KP_7 , KC_KP_8 , KC_KP_9   , KC_KP_SLASH    , _______     ,
          _______   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , _______ , _______ , KC_KP_4 , KC_KP_5 , KC_KP_6   , KC_KP_ASTERISK , _______     ,
          _______   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , KC_KP_1 , KC_KP_2 , KC_KP_3   , KC_KP_MINUS    , _______     ,
          _______   , _______ , _______ , _______ , _______ , _______ , KC_NO   , _______ , KC_KP_0 , KC_KP_DOT , KC_KP_PLUS     , KC_KP_EQUAL
          ),

  [_ADJUST] = LAYOUT_planck_grid(
          KC_DELETE , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
          _______   , _______ , AU_ON   , AU_OFF  , AU_TOG  , _______ , _______ , RGB_TOG , RGB_VAI , RGB_VAD , _______ , RESET   ,
          _______   , _______ , MU_ON   , MU_OFF  , MU_TOG  , _______ , _______ , RGB_MOD , RGB_HUI , RGB_HUD , _______ , _______ ,
          _______   , _______ , _______ , _______ , _______ , _______ , KC_NO   , _______ , _______ , _______ , _______ , _______
          ),
};

// Shift vs capslock function. From bbaserdem's Planck keymap.
void caps_tap (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code (KC_LSFT);
    } else if (state->count == 2) {
        unregister_code (KC_LSFT);
        register_code (KC_CAPS);
    }
}
void caps_tap_end (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code (KC_LSFT);
    } else {
        unregister_code (KC_CAPS);
    }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Shift, twice for Caps Lock
  [SFT_LCK] = ACTION_TAP_DANCE_FN_ADVANCED( caps_tap, NULL, caps_tap_end )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
