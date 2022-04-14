#include QMK_KEYBOARD_H
#include "caps_word.h"

enum layers {
    BASE,
    NUMBER,
    NAV,
    FUNCTION,
    GAME1,
    GAME2,
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_RGH RGUI_T(KC_ESCAPE)

// Alts
#define ALT_X RALT_T(KC_X)
#define ALT_DO RALT_T(KC_DOT)

// Thumbs
#define T_LFT1 MO(NUMBER)
#define T_LFT2 LCTL_T(KC_SPACE)
#define T_LFT3 LSFT_T(KC_BACKSPACE)

#define T_RGH1 MO(NAV)
#define T_RGH2 LSFT_T(KC_ENTER)
#define T_RGH3 LCTL_T(KC_TAB)

// Game layer
#define TO_GAME TO(GAME1)
#define TO_BASE TO(BASE)
#define ALT_GAME2 LT(GAME2, KC_LALT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Base qwerty layout
  [BASE] = LAYOUT_3x5_3(
     KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
     HOME_A,    HOME_S,  HOME_D,  HOME_F,  KC_G,        KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_RGH,
     KC_Z,      ALT_X,   KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, ALT_DO,  KC_SLSH,
                                  T_LFT1,  T_LFT2,      T_RGH2,  T_RGH1,
                                           T_LFT3,      T_RGH3
  ),

  // Special <> Numpad
  [NUMBER] = LAYOUT_3x5_3(
     KC_LBRC, KC_RBRC, KC_QUES, KC_SLSH, KC_CIRC,       KC_PPLS, KC_7,    KC_8,    KC_9,    KC_PERC,
     KC_LPRN, KC_RPRN, KC_QUOT, KC_DQUO, KC_COLN,       KC_PMNS, KC_5,    KC_5,    KC_6,    KC_SCLN,
     KC_LABK, KC_RABK, KC_DLR,  KC_EQL,  KC_HASH,       KC_UNDS, KC_1,    KC_2,    KC_3,    KC_0,
                                KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                         KC_TRNS,       KC_TRNS
  ),

  // Special             <> Navigation
  // Modifiers on bottom <> Media on bottom
  [NAV] = LAYOUT_3x5_3(
     KC_PIPE, KC_AMPR, KC_EXLM, KC_BSLS, KC_TILD,       XXXXXXX, KC_HOME, KC_UP,   KC_END,   XXXXXXX,
     KC_LCBR, KC_RCBR, KC_GRV,  KC_AT,   KC_ASTR,       KC_PGUP, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,
     KC_BSPC, KC_DEL,  KC_LALT, KC_LSFT, KC_LGUI,       KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD,  KC_VOLU,
                                KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                         KC_TRNS,       KC_TRNS
  ),

  // Danger zone <> Function keys
  [FUNCTION] = LAYOUT_3x5_3(
     XXXXXXX, XXXXXXX, TO_GAME, XXXXXXX, XXXXXXX,       XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,
     KC_CAPS, KC_INS,  KC_PSCR, KC_CALC, XXXXXXX,       XXXXXXX, KC_F4,   KC_F5,   KC_F6,   KC_F11,
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F12,
                                KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS,
                                         KC_TRNS,       KC_TRNS
  ),

  // Gaming layer where left is shifted to the right.
  // Shift to numbers with left-alt thumb key
  [GAME1] = LAYOUT_3x5_3(
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,           KC_N,    KC_M,    KC_COMM, ALT_DO,  KC_SLSH,
                                KC_ESC,  KC_SPACE,       KC_ENT,  TO_BASE,
                                         ALT_GAME2,      KC_BSPC
  ),
  // Space fo 3 more alt layouts.
  [GAME2] = LAYOUT_3x5_3(
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
     KC_5,    KC_6,    KC_7,    KC_8,    XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     KC_9,    KC_0,    XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                         KC_TRNS,        KC_TRNS
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    return true;
}
