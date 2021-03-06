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

#define L1KEY KC_TAB
#define L2KEY KC_SPC

const uint16_t PROGMEM fn_actions[] = {
  #define LAYR1 KC_FN0
  [0] = ACTION_LAYER_TAP_KEY(2, L1KEY),  // to Fn overlay
  #define LAYR2 KC_FN1
  [1] = ACTION_LAYER_TAP_KEY(3, L2KEY),  // to Fn overlay
  #define REBOOT KC_FN2
  [2] = ACTION_FUNCTION(BOOTLOADER),
  #define SSFT KC_FN3
  [3] = ACTION_MODS_ONESHOT(MOD_LSFT),
  #define SCTL KC_FN4
  [4] = ACTION_MODS_ONESHOT(MOD_LCTL),
  #define SALT KC_FN5
  [5] = ACTION_MODS_ONESHOT(MOD_LALT),
  #define LAYR3 KC_FN6
  [6] = ACTION_LAYER_TAP_KEY(1, KC_SCLN),
  #define NOLA KC_FN7
  [7] = ACTION_LAYER_SET_CLEAR(0),
  #define SHFB KC_FN8
  [8] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_BSPC),
  #define BSWD KC_FN9
  [9] = ACTION_MODS_KEY(MOD_LALT, KC_BSPC),
  #define ESC KC_FN10
  [10] = ACTION_FUNCTION(CLEAR_MODIFIERS),
  #define SSUP KC_FN11
  [11] = ACTION_MODS_ONESHOT(MOD_LGUI),
  #define ZSHIFT KC_FN12
  [12] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z),
  #define GOL1 KC_FN13
  [13] = ACTION_LAYER_TOGGLE(2),
  #define GOL2 KC_FN14
  [14] = ACTION_LAYER_TOGGLE(3)
};

#define BASE_LAYER                                                      \
  KEYMAP(                                                               \
         KC_Q,  KC_W,    KC_E,     KC_R,    KC_T,  KC_Y, KC_U, KC_I,    KC_O,   KC_P, \
         KC_A,  KC_S,    KC_D,     KC_F,    KC_G,  KC_H, KC_J, KC_K,    KC_L,   LAYR3, \
         KC_Z,  KC_X,    KC_C,     KC_V,    KC_B,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         SSFT,  ESC,     SSUP,     KC_BSPC, LAYR1, SCTL, SALT,          \
         LAYR2, KC_MINS, KC_EQUAL, KC_QUOT, KC_ENT)

#define LAYER1                                                          \
  KEYMAP(KC_1,           KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,  KC_9,    KC_0, \
         EXCLM,          QUOTE,   POUND,   DOLLR,   PRCNT,    HAT,     AMP,     STAR,  LPARN,   RPARN, \
         PLUS,           KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, KC_NUBS, KC_NUHS, TILDE, KC_LBRC, KC_RBRC, \
         KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, \
         SHIFT(KC_SCLN), KC_DOT,  PIPE,    LBRCE,   RBRCE)

#define LAYER2                                                          \
  KEYMAP(                                                               \
         KC_GRAVE,    CALT(KC_LEFT), CALT(KC_UP), CALT(KC_DOWN), CALT(KC_RIGHT), KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5, \
         KC__VOLUP,   CTRL(KC_LEFT), CTRL(KC_UP), CTRL(KC_DOWN), CTRL(KC_RIGHT), KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10, \
         KC__VOLDOWN, ALT(KC_LEFT),  ALT(KC_UP),  ALT(KC_DOWN),  ALT(KC_RIGHT),  KC_F11,  KC_F12,  KC_F13, KC_F14, KC_F15, \
         KC_TRNS,     KC_TRNS,       KC_TRNS,     KC_TRNS,       L1KEY,          KC_TRNS, KC_TRNS, \
         KC_TRNS,     KC_HOME,       KC_PGUP,     KC_PGDN,       KC_END)

#define LAYER3                                                          \
  KEYMAP(                                                               \
         KC_ESC,  KC_QUOT, ATPER,   KC_INS,  KC_DEL,   KC_CUT,   KC_FIND,    KC_NO, KC_NO,          KC_NO, \
         KC_TAB,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,   KC_COPY,  KC_AGAIN,   KC_NO, SHIFT(KC_SCLN), KC_TRNS, \
         KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, KC_PASTE, KC_EXECUTE, KC_NO, KC_NO,          KC_NO, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, GOL1,     KC_TRNS,  KC_TRNS, \
         GOL2,    KC_TRNS, KC_TRNS, KC_TRNS, REBOOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0: mostly letters */
  BASE_LAYER,
  LAYER3,
  LAYER1,
  LAYER2
};

void clear_modifiers(keyevent_t);

void clear_modifiers(keyevent_t event) {
  //clear mods if sticky set, else die
  //also deactivt
  uint8_t osmods = get_oneshot_locked_mods();

  if (osmods || (layer_state != default_layer_state)) {
    if (!event.pressed) {
      layer_clear();
      clear_oneshot_locked_mods();
      del_mods(osmods);
    }
  } else {
    if (event.pressed) {
      add_key(KC_ESC);
    } else {
      del_key(KC_ESC);
    }
  }
  send_keyboard_report();
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  } else if (id == CLEAR_MODIFIERS) {
    clear_modifiers(record->event);
  }
}
