/* Copyright 2020 undermark5
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define NUMLOCK_MASK (1 << USB_LED_NUM_LOCK)
#define CAPSLOCK_MASK (1 << USB_LED_CAPS_LOCK)
#define SCRLLOCK_MASK (1 << USB_LED_SCROLL_LOCK)
#define COMPOSE_MASK (1 << USB_LED_COMPOSE)
#define KANA_MASK (1 << USB_LED_KANA)


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUMLOCK
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    KC_00 = SAFE_RANGE,
    KC_WINLOCK
};

/* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
   ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
   ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────┼─────────┼─────────┼─────────┼─────────┤
         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
   ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────├─────────├─────────├─────────├         ┤
         KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,
   ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────────────────┼─────────┼─────────┼─────────┼─────────┤
         KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
   ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴─────────┴──┬──────┴───────┬───────────┬─────────┼─────────┼─────────┼─────────┼         ┤
     KC_TRNS,    KC_TRNS,    KC_TRNS,                              KC_TRNS,                               KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
   └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴──────────────┴──────────────┴───────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
/* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
     KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,          KC_F5,    KC_F6,    KC_F7,    KC_F8,          KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_PSCR,  KC_SLCK,  KC_PAUS,   TG(1),
/* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤ */
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,       KC_BSPC,         KC_INS,   KC_HOME,  KC_PGUP,  KC_NO,
/* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────┼─────────┼─────────┼─────────┼─────────┤ */
          KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,        KC_DEL,   KC_END,   KC_PGDN,  KC_NO,
/* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────├─────────├─────────├─────────├         ┤ */
          KC_CAPS,       KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,   KC_SCLN,  KC_QUOT,    KC_ENT,               KC_NO,    KC_NO,    KC_NO,
/* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────────────────┼─────────┼─────────┼─────────┼─────────┤ */
          KC_LSFT,          KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,                    KC_NO,    KC_UP,    KC_NO,    KC_NO,
/* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴─────────┴──┬──────┴───────┬───────────┬─────────┼─────────┼─────────┼─────────┼         ┤ */
      KC_LCTL,    KC_LGUI,    KC_LALT,                              KC_SPC,                                KC_RALT,         MO(2),      KC_APP,    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
/* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴──────────────┴──────────────┴───────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
  ),

  [1] = LAYOUT(
/* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤ */
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,         KC_NLCK,  KC_PSLS,  KC_PAST,   KC_PMNS,
/* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────┼─────────┼─────────┼─────────┼─────────┤ */
         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_P7,    KC_P8,    KC_P9,     KC_PPLS,
/* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────├─────────├─────────├─────────├         ┤ */
         KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,             KC_P4,    KC_P5,    KC_P6,
/* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────────────────┼─────────┼─────────┼─────────┼─────────┤ */
         KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,                    KC_P1,    KC_P2,    KC_P3,     KC_PENT,
/* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴─────────┴──┬──────┴───────┬───────────┬─────────┼─────────┼─────────┼─────────┼         ┤ */
     KC_TRNS,    KC_TRNS,    KC_TRNS,                              KC_TRNS,                               KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_P0,    KC_00,    KC_PDOT
/* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴──────────────┴──────────────┴───────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
  ),

  [2] = LAYOUT(
/* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤ */
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────┼─────────┼─────────┼─────────┼─────────┤ */
         KC_TRNS,  KC_TRNS,   GUI_ON,  KC_TRNS,  RESET,    KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────├─────────├─────────├─────────├         ┤ */
         KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,
/* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────────────────┼─────────┼─────────┼─────────┼─────────┤ */
         KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴─────────┴──┬──────┴───────┬───────────┬─────────┼─────────┼─────────┼─────────┼         ┤ */
     KC_TRNS,    GUI_OFF,    KC_TRNS,                              KC_TRNS,                               KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
/* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴──────────────┴──────────────┴───────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
  ),

  [3] = LAYOUT(
/* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤ */
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────┼─────────┼─────────┼─────────┼─────────┤ */
         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────├─────────├─────────├─────────├         ┤ */
         KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,
/* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────────────────┼─────────┼─────────┼─────────┼─────────┤ */
         KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
/* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴─────────┴──┬──────┴───────┬───────────┬─────────┼─────────┼─────────┼─────────┼         ┤ */
     KC_TRNS,    KC_TRNS,    KC_TRNS,                              KC_TRNS,                               KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
/* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴──────────────┴──────────────┴───────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_00:
            if (record->event.pressed) {
                SEND_STRING("00");
            }
            break;
    }
    return true;
}

bool led_update_user(led_t led_state) {

    if (!(1 & led_state.raw)) {
        dprintf("%d\n", !(1 & led_state.raw));
        register_code(KC_NLCK);
        unregister_code(KC_NLCK);
    }
    return true;
}

void keyboard_post_init_user(void) {
// Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
}
