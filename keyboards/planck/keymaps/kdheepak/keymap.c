#include QMK_KEYBOARD_H
#include "muse.h"
#include "eeprom.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define NO_TH ALGR(KC_T)
#define NO_ETH ALGR(KC_D)

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = EZ_SAFE_RANGE,
  RGB_SLD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC  , KC_Q     , KC_W    , KC_E    , KC_R  , KC_T     , KC_Y  , KC_U  , KC_I     , KC_O    , KC_P      , KC_BSPACE ,
    KC_TAB  , KC_A     , KC_S    , KC_D    , KC_F  , KC_G     , KC_H  , KC_J  , KC_K     , KC_L    , KC_SCOLON , KC_QUOTE  ,
    KC_LSFT , KC_Z     , KC_X    , KC_C    , KC_V  , KC_B     , KC_N  , KC_M  , KC_COMMA , KC_DOT  , KC_UP     , KC_SFTENT ,
    KC_HYPR , KC_LCTRL , KC_LALT , KC_LGUI , LOWER , KC_SPACE , KC_NO , RAISE , KC_SLASH , KC_LEFT , KC_DOWN   , KC_RIGHT
),

[_LOWER] = LAYOUT_planck_grid(
    KC_DELETE , KC_1    , KC_2    , KC_3    , KC_4     , KC_5    , KC_6     , KC_7     , KC_8        , KC_9              , KC_0               , _______         ,
    _______   , _______ , _______ , _______ , _______  , _______ , KC_LEFT  , KC_DOWN  , KC_UP       , KC_RIGHT          , _______            , KC_GRAVE        ,
    _______   , KC_UNDO , KC_CUT  , KC_COPY , KC_PASTE , KC_FIND , KC_MINUS , KC_EQUAL , KC_LBRACKET , KC_RBRACKET       , KC_BRIGHTNESS_UP   , _______         ,
    _______   , _______ , _______ , _______ , _______  , _______ , KC_NO    , _______  , KC_BSLASH   , KC_AUDIO_VOL_DOWN , KC_BRIGHTNESS_DOWN , KC_AUDIO_VOL_UP
)           ,

[_RAISE] = LAYOUT_planck_grid(
    _______ , _______ , KC_UP   , _______  , _______ , _______ , _______ , KC_KP_7 , KC_KP_8 , KC_KP_9   , KC_KP_SLASH    , _______     ,
    _______ , KC_LEFT , KC_DOWN , KC_RIGHT , _______ , _______ , _______ , KC_KP_4 , KC_KP_5 , KC_KP_6   , KC_KP_ASTERISK , _______     ,
    _______ , _______ , _______ , _______  , _______ , _______ , _______ , KC_KP_1 , KC_KP_2 , KC_KP_3   , KC_KP_MINUS    , _______     ,
    _______ , _______ , _______ , _______  , _______ , _______ , KC_NO   , _______ , KC_KP_0 , KC_KP_DOT , KC_KP_PLUS     , KC_KP_EQUAL
),

[_ADJUST] = LAYOUT_planck_grid(
    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
    _______ , _______ , AU_ON   , AU_OFF  , AU_TOG  , _______ , _______ , RGB_TOG , RGB_VAI , RGB_VAD , _______ , RESET   ,
    _______ , _______ , MU_ON   , MU_OFF  , MU_TOG  , _______ , _______ , RGB_MOD , RGB_HUI , RGB_HUD , _______ , _______ ,
    _______ , _______ , _______ , _______ , _______ , _______ , KC_NO   , _______ , _______ , _______ , _______ , _______
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define BLANK_COLOR  { 0   , 0   , 0   }
#define ALPHA_COLOR  { 255 , 255 , 255 }
#define SYMBOL_COLOR  { 77 , 77 , 255 }
#define ORTHO_COLOR  { 255 , 0   , 0   }
#define OS_COLOR     { 255, 77 , 77   }
#define LAYER_COLOR  { 0   , 0   , 255 }
#define NUMPAD_COLOR { 255 , 255 , 0   }
#define ARROW_COLOR  { 0   , 255 , 0   }
#define SPACE_COLOR  { 255 , 255 , 255 }
#define RESET_COLOR  { 255   , 255 , 255   }

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
        ORTHO_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR  , ALPHA_COLOR  , ALPHA_COLOR  , ALPHA_COLOR  , ORTHO_COLOR  ,
        ORTHO_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR  , ALPHA_COLOR  , ALPHA_COLOR  , SYMBOL_COLOR , SYMBOL_COLOR ,
        ORTHO_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR , ALPHA_COLOR  , SYMBOL_COLOR , SYMBOL_COLOR , ARROW_COLOR  , ORTHO_COLOR  ,
        LAYER_COLOR , ORTHO_COLOR , ORTHO_COLOR , ORTHO_COLOR , LAYER_COLOR ,        SPACE_COLOR        , LAYER_COLOR , SYMBOL_COLOR , ARROW_COLOR  , ARROW_COLOR  , ARROW_COLOR
    },

    [1] = {
        ORTHO_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , BLANK_COLOR  ,
        BLANK_COLOR , BLANK_COLOR  , BLANK_COLOR  , BLANK_COLOR  , BLANK_COLOR  , BLANK_COLOR  , ARROW_COLOR  , ARROW_COLOR  , ARROW_COLOR  , ARROW_COLOR  , BLANK_COLOR  , SYMBOL_COLOR ,
        BLANK_COLOR , OS_COLOR     , OS_COLOR     , OS_COLOR     , OS_COLOR     , OS_COLOR     , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , SYMBOL_COLOR , OS_COLOR     , BLANK_COLOR  ,
        LAYER_COLOR , BLANK_COLOR  , BLANK_COLOR  , BLANK_COLOR  , LAYER_COLOR  ,         SPACE_COLOR         , LAYER_COLOR  , SYMBOL_COLOR , OS_COLOR     , OS_COLOR     , OS_COLOR
    },

    [2] = {
        BLANK_COLOR , BLANK_COLOR , ARROW_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , BLANK_COLOR ,
        BLANK_COLOR , ARROW_COLOR , ARROW_COLOR , ARROW_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , BLANK_COLOR ,
        BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , BLANK_COLOR ,
        LAYER_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , LAYER_COLOR ,        BLANK_COLOR        , LAYER_COLOR  , NUMPAD_COLOR , NUMPAD_COLOR , NUMPAD_COLOR , BLANK_COLOR
    },

    [3] = {
        BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR ,
        BLANK_COLOR , BLANK_COLOR , OS_COLOR    , OS_COLOR    , OS_COLOR    , BLANK_COLOR , BLANK_COLOR , OS_COLOR    , OS_COLOR    , OS_COLOR    , BLANK_COLOR , RESET_COLOR ,
        BLANK_COLOR , BLANK_COLOR , OS_COLOR    , OS_COLOR    , OS_COLOR    , BLANK_COLOR , BLANK_COLOR , OS_COLOR    , OS_COLOR    , OS_COLOR    , BLANK_COLOR , BLANK_COLOR ,
        LAYER_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , LAYER_COLOR ,        BLANK_COLOR        , LAYER_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR , BLANK_COLOR
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    RGB rgb = {
      .r = ledmap[layer][i][0],
      .g = ledmap[layer][i][1],
      .b = ledmap[layer][i][2],
    };
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}


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

void suspend_power_down_user(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void)
{
    rgb_matrix_set_suspend_state(false);
}

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

/*

Combo

*/

// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {COMBO(jk_combo, KC_ESC)};



