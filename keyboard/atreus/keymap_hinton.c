#include "keymap_common.h"

#define MAP(K00, K01, K02, K03, K04, K05, K06, K07, K08, K09,\
            K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,\
            K20, K21, K22, K23, K24, K25, K26, K27, K28, K29,\
            K30, K31, K32, K33, K34, K35, K36, K37, K38, K39) \
  KEYMAP (K00, K01, K02, K03, K04, K05, K06, K07, K08, K09,\
          K10, K11, K12, K13, K14, K15, K16, K17, K18, K19,             \
          K20, K21, K22, K23, K24, K25, K26, K27, K28, K29,             \
          K30, K31, K32, K33, K34, KC_LCTL, KC_LALT, K35, K36, K37, K38, K39)

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_FUNCTION(0),
  [1] = ACTION_LAYER_TAP_KEY(1, KC_MINS),
  [2] = ACTION_MODS_ONESHOT(MOD_LSFT),
  [3] = ACTION_LAYER_TAP_KEY(2, KC_EQUAL),
  [4] = ACTION_LAYER_SET(1, ON_PRESS),
  [5] = ACTION_LAYER_MOMENTARY(1)
};

// it would be nice for shift-lock to ignore layer two

#define KA_ESC KC_ESC
#define KA_BOOT KC_FN0
#define KA_NUMS KC_FN1
#define KA_SHIFT KC_FN2
#define KA_FUNS KC_FN3
#define KA_LOCKNUMS KC_FN4
#define KA_MONUMS KC_FN5

#define KA_BANG SHIFT(KC_1)
#define KA_DQUO SHIFT(KC_2)
#define KA_AMP SHIFT(KC_7)
#define KA_STAR SHIFT(KC_8)
#define KA_LPAR SHIFT(KC_9)
#define KA_RPAR SHIFT(KC_0)
#define KA_LBRA SHIFT(KC_LBRC)
#define KA_RBRA SHIFT(KC_RBRC)
#define KA_HAT SHIFT(KC_6)
#define KA_PIPE SHIFT(KC_NUBS)
#define KA_DOLR SHIFT(KC_4)
#define KA_PCNT SHIFT(KC_5)
#define KA_PND SHIFT(KC_3)
#define KA_PLUS SHIFT(KC_EQUAL)

#define QWERTY\
  MAP( KC_Q,   KC_W,   KC_E,    KC_R,     KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,   KC_S,   KC_D,    KC_F,     KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, \
       KC_Z,   KC_X,   KC_C,    KC_V,     KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
       KA_ESC, KC_TAB, KC_LGUI, KA_SHIFT, KC_BSPC, KC_SPC, KA_NUMS, KA_FUNS, KC_QUOT, KC_ENT)

#define NUMS\
  MAP( KC_7,   KC_8, KC_9,    KA_HAT,   KA_PCNT, KA_BANG, KC_LBRC,   KA_AMP,   KC_RBRC, KA_PIPE, \
       KC_4,   KC_5, KC_6,    KA_PND,   KC_MINS, KC_NUHS, KA_LPAR,   KA_DQUO,  KA_RPAR, SHIFT(KC_SCLN), \
       KC_1,   KC_2, KC_3,    KC_EQUAL, KA_PLUS, KC_NUBS, KA_LBRA,   KA_STAR,  KA_RBRA, SHIFT(KC_NUHS), \
       KC_DOT, KC_0, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KA_MONUMS, KC_GRAVE, KA_DOLR, KC_TRNS)

#define FNS                                                             \
  MAP( KC_HELP,     KC_HOME, KC_UP,   KC_END,   KC_PGUP,   KC_F1,  KC_F2,  KC_F3,   KC_F4,  KC_F5, \
       KA_LOCKNUMS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,   KC_F6,  KC_F7,  KC_F8,   KC_F9,  KC_F10, \
       KC_NO,       KC_APP,  KC_NO,   KC_NO,    KC_INSERT, KC_F11, KC_F12, KC_F13,  KC_F14, KC_F15, \
       KA_BOOT,     KC_NO,   KC_NO,   KC_NO,    KC_DELETE, KC_F16, KC_F17, KC_TRNS, KC_F18, KC_F20)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  QWERTY,
  NUMS,
  FNS
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
  case 0:
    bootloader();
    break;
  }
}
