#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

char wpm_str[10];
uint16_t wpm_graph_timer = 0;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
      KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOTE, \
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_MINS, KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
      KC_LCTL,  KC_LALT, KC_HYPR, KC_LGUI, KC_SPC,  LOWER,  KC_LBRC, KC_RBRC, RAISE,   KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
      ),

  [_LOWER] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,  _______,  _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,  _______,  _______, \
      _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,  _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______ \
      ),

  [_RAISE] = LAYOUT( \
      _______, _______, _______, _______,  _______, _______,                   _______, _______,     _______, _______,   _______,        _______, \
      _______, _______, KC_UP,   _______,  _______, _______,                   _______, KC_KP_7,     KC_KP_8, KC_KP_9,   KC_KP_SLASH,    _______, \
      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                   _______, KC_KP_4,     KC_KP_5, KC_KP_6,   KC_KP_ASTERISK, _______, \
      _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_KP_1,     KC_KP_2, KC_KP_3,   KC_KP_MINUS,    _______, \
      _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_KP_EQUAL, KC_KP_0, KC_KP_DOT, KC_KP_PLUS,     _______ \
      ),

  [_ADJUST] =  LAYOUT( \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      RESET,   _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______ \
      )
};


// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;

      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif

    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

#ifdef OLED_DRIVER_ENABLE

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

#ifdef WPM_ENABLE
    // Write WPM
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    oled_write_P(PSTR("\n"), false);
    oled_write(wpm_str, false);
#else
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
#endif
}


static uint8_t zero_bar_count = 0;

static void render_wpm_graph(void) {
    uint8_t bar_height = 0;
    uint8_t bar_segment = 0;

    if (wpm_graph_timer == 0) {
        // render_kyria_logo();
        wpm_graph_timer = timer_read();
        return;
    }
    if(timer_elapsed(wpm_graph_timer) > 500) {
        wpm_graph_timer = timer_read();

        if(OLED_DISPLAY_HEIGHT == 64)
            bar_height = get_current_wpm() / 2;
        if(OLED_DISPLAY_HEIGHT == 32)
            bar_height = get_current_wpm() / 4;
        if(bar_height > OLED_DISPLAY_HEIGHT)
            bar_height = OLED_DISPLAY_HEIGHT;

        if(bar_height == 0) {
            // keep track of how many zero bars we have drawn.  If
            // there is a whole screen worth, turn the display off and
            // wait until there is something to do
            if (zero_bar_count > OLED_DISPLAY_WIDTH) {
                oled_off();
                return;
            }
            zero_bar_count++;
        } else
            zero_bar_count=0;

        oled_pan(false);
        for (uint8_t i = (OLED_DISPLAY_HEIGHT / 8); i > 0; i--) {
            if (bar_height > 7) {
                bar_segment = 255;
                bar_height -= 8;
            } else {
                switch (bar_height) {
                    case 0:
                        bar_segment = 0;
                        break;

                    case 1:
                        bar_segment = 128;
                        break;

                    case 2:
                        bar_segment = 192;
                        break;

                    case 3:
                        bar_segment = 224;
                        break;

                    case 4:
                        bar_segment = 240;
                        break;

                    case 5:
                        bar_segment = 248;
                        break;

                    case 6:
                        bar_segment = 252;
                        break;

                    case 7:
                        bar_segment = 254;
                        break;
                }
                bar_height = 0;
            }
            oled_write_raw_byte(bar_segment, (i-1) * OLED_DISPLAY_WIDTH);
        }
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_wpm_graph();
    } else {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
}
#endif
