/* Copyright 2020 Sergey Vlasov <sigprof@gmail.com>
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
// OLED

enum tap_dances {
    TD_OLED,
};

enum tap_modes {
    // Modes between TAP_FIRST and TAP_LAST (inclusive) can be switched with a keypress.
    TAP_FIRST,
    TAP_VOLUME = TAP_FIRST,
    TAP_SCROLL,    
    TAP_LAST = TAP_SCROLL
};

static enum tap_modes test_mode = TAP_FIRST;

static void dance_oled_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (test_mode < TAP_LAST) {
        ++test_mode;
    } else {
        test_mode = TAP_FIRST;
    }
    oled_clear();
}

qk_tap_dance_action_t tap_dance_actions[] = {[TD_OLED] = ACTION_TAP_DANCE_FN(dance_oled_finished)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {LAYOUT_ortho_1x1(TD(TD_OLED))};

// `bool oled_is_dirty(void)` does not exist at the moment
extern OLED_BLOCK_TYPE oled_dirty;

static void show_volume(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void show_scroll(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x80, 0x80, 0x80, 0x80, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA6, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0x80, 0x80, 0x80, 0x80, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_scroll_set_area(0, 0);
    return rotation;
}

bool oled_task_user(void) {
    switch (test_mode) {
        case TAP_VOLUME:
            show_volume();
            break;
        case TAP_SCROLL:
            show_scroll();
            break;
    }
    return false;
}

// Encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (test_mode) {
        case TAP_VOLUME:
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
            break;
        case TAP_SCROLL:
            if (clockwise) {
                tap_code(KC_WH_U);
            } else {
                tap_code(KC_WH_D);
            }
            break;
    }
    return false;
}