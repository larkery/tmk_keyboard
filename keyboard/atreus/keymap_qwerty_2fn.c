#include "keymap_common.h"

/* This keymap is based on the default one, but it has a momentary
   layer2 key on layer 1. (see also keymap_qwerty_ml2.c which has
   fn+shift as a momentary layer2.) */

#define EXCLM (SHIFT(KC_1))
#define QUOTE (SHIFT(KC_2))
#define POUND (SHIFT(KC_3))
#define DOLLR (SHIFT(KC_4))
#define PRCNT (SHIFT(KC_5))
#define HAT   (SHIFT(KC_6))
#define AMP   (SHIFT(KC_7))
#define STAR  (SHIFT(KC_8))
#define LPARN (SHIFT(KC_9))
#define RPARN (SHIFT(KC_0))
#define USCOR (SHIFT(KC_MINS))
#define PLUS  (SHIFT(KC_EQUAL))
#define PIPE  (SHIFT(KC_NUBS))
#define TILDE (SHIFT(KC_NUHS))
#define ATPER (SHIFT(KC_QUOT))
#define LBRCE (SHIFT(KC_LBRC))
#define RBRCE (SHIFT(KC_RBRC))

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_TAP_KEY(1, KC_SPC),  // to Fn overlay
  [1] = ACTION_LAYER_TAP_KEY(2, KC_SCLN),  // to Fn overlay
  [2] = ACTION_FUNCTION(BOOTLOADER),
  [3] = ACTION_MODS_ONESHOT(MOD_LSFT),
  [4] = ACTION_MODS_ONESHOT(MOD_LCTL),
  [5] = ACTION_MODS_ONESHOT(MOD_LALT),
  [6] = ACTION_LAYER_TAP_KEY(3, KC_BSPC),
  [7] = ACTION_LAYER_SET_CLEAR(0),
  [8] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),
  [9] = ACTION_MODS_KEY(MOD_LALT, KC_BSPC),
};

#define NUMS KC_FN0
#define PUNC KC_FN1
#define REBOOT KC_FN2
#define SSFT KC_FN3
#define SCTL KC_FN4
#define SALT KC_FN5
#define AARW KC_FN6
#define NOLA KC_FN7
#define SHFB KC_FN8
#define BSWD KC_FN9
#define KLINE KC_FN10

#define BASE_LAYER\
  KEYMAP(\
         KC_Q,   KC_W,    KC_E,     KC_R,    KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P, \
         KC_A,   KC_S,    KC_D,     KC_F,    KC_G, KC_H, KC_J, KC_K,    KC_L,   PUNC, \
         KC_Z,   KC_X,    KC_C,     KC_V,    KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_ESC, KC_TAB,  KC_LGUI,  SSFT,    AARW, SCTL, SALT,          \
         NUMS,   KC_MINS, KC_EQUAL, KC_QUOT, KC_ENT)

#define LAYER1                                                          \
  KEYMAP(                                                               \
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5, \
         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10, \
         KC_DOT,  PLUS,    STAR,    KC_SLSH, KC_MINS, KC_F11,  KC_F12,  KC_F13, KC_F14, KC_F15, \
         NOLA,    KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO)

#define LAYER2                                                          \
  KEYMAP(                                                               \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
         REBOOT,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

#define ARROWS                                                          \
  KEYMAP(                                                               \
         KC_PGUP, KC_HOME, KC_UP,   KC_END,   KC_NUHS, EXCLM,   QUOTE,   PRCNT,   HAT,     DOLLR, \
         KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, ATPER,   TILDE,   PIPE,    AMP,     STAR,    PLUS, \
         KC_NO,   KC_NO,   KC_NO,   KC_NO,    POUND,   LPARN,   RPARN,   KC_LBRC, KC_RBRC, KC_NUBS, \
         NOLA,    KC_NO,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS, KC_SPC,   KC_NO,  KC_NO,   KC_NO)


//#define FNKEYS                                \
//  KEYMAP(                                                             \
//         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
//         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
//         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
//         KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, \
//         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  BASE_LAYER,
  LAYER1,
  LAYER2,
  ARROWS
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
