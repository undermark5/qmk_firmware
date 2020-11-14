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
#include <print.h>
#include <rgblight.h>
#include <mousekey.h>
#include <string.h>

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUMLOCK
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    KC_00 = SAFE_RANGE
};

/* ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐ */
/*  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,//*/
/* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤ */
/*  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,//*/
/* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────┼─────────┼─────────┼─────────┼─────────┤ */
/*       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,//*/
/* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────├─────────├─────────├─────────├         ┤ */
/*       KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,           //*/
/* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────────────────┼─────────┼─────────┼─────────┼─────────┤ */
/*       KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,//*/
/* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴─────────┴──┬──────┴───────┬───────────┬─────────┼─────────┼─────────┼─────────┼         ┤ */
/*   KC_TRNS,    KC_TRNS,    KC_TRNS,                              KC_TRNS,                               KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS            //*/
/* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴──────────────┴──────────────┴───────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */

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
    KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,//*/
/* ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─┴───────┬─┴───────┬─┴─────────┴─────────┼─────────┼─────────┼─────────┼─────────┤ */
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,      KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,//*/
/* ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────────────────┼─────────┼─────────┼─────────┼─────────┤ */
         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,//*/
/* ├──────────────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴──┬──────┴────────────────├─────────├─────────├─────────├         ┤ */
         KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,             KC_TRNS,  KC_TRNS,  KC_TRNS,           //*/
/* ├─────────────────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───┬─────┴───────────────────────┼─────────┼─────────┼─────────┼─────────┤ */
         KC_TRNS,          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,//*/
/* ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴─────────┴──┬──────┴───────┬───────────┬─────────┼─────────┼─────────┼─────────┼         ┤ */
     KC_TRNS,    KC_TRNS,    KC_TRNS,                              KC_TRNS,                               KC_TRNS,         KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS            //*/
/* └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴──────────────┴──────────────┴───────────┴─────────┴─────────┴─────────┴─────────┴─────────┘ */
  )
};

static uint16_t num_lock_timer;
static uint16_t elapsed = 0;
static uint16_t old_elapsed = 0;
static bool timer_overflow = false;
void matrix_scan_user(void) {
    led_t led = host_keyboard_led_state();
    old_elapsed = elapsed;
    elapsed = timer_elapsed(num_lock_timer);
    if (!timer_overflow && elapsed < old_elapsed) {
        timer_overflow = true;
    }
    // uprintf("elapsed: %d  %d\n", elapsed, timer_overflow);
    if (!led.num_lock && (elapsed > 500 || timer_overflow)) {
        num_lock_timer = timer_read();
        timer_overflow = false;
        elapsed = 0;
        // uprintf("change numlock\n");
        tap_code(KC_NLCK);
    //    tap_code(KC_MS_D);x
        move_mouse(rand() % 10000, rand() % 10000);
        rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 255);
        rgblight_set_speed(255);
    }
}

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

const uint32_t LEDS_COMMAND = 0x7364656c;
const uint32_t SDEL_COMMAND = 0x6c656473;

void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (length > 2048) {
        return;
    }
    static uint8_t cmd[4];
    static uint8_t buf[2048];
    memcpy(cmd, data, 4);
    // for (uint8_t i = 0; i < 4; i++) {
        uprintf("%x\n", *(uint32_t *) cmd);
        uprintf("%x\n", *(uint32_t *) "leds");
    // }
    switch (*(uint32_t *)cmd) {
    case LEDS_COMMAND:
        uprintf("LEDS COMMAND\n");
        break;
    case SDEL_COMMAND:
        uprintf("SDEL COMMAND\n");
        break;
    }
    for (uint8_t i = 0; i < length; i++) {
        uprintf("%x\n", data[i]);
    }
}

void keyboard_post_init_user(void) {
// Customise these values to desired behaviour
  debug_enable=true;
    led_t led = host_keyboard_led_state();
    if (!led.num_lock) {
        num_lock_timer = timer_read();
        uprintf("change numlock\n");
        tap_code(KC_NLCK);
    }
    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
}
