// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
// License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later
// version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details. You should have received a copy of the GNU General Public License along with this program. If not, see
// <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // oled_write_P(PSTR(get_highest_layer(layer_state)), false);
    } else {
        oled_write_ln_P(PSTR("2024-03-22 Miryoku"), false);
        oled_write_ln_P(PSTR("homerow mod"), false);
        oled_write_ln_P(PSTR("hold time"), false);
    }
    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        // top to right
        return OLED_ROTATION_180;
    }
}

#endif // OLED_ENABLE

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        tap_code(clockwise ? KC_VOLU : KC_VOLD);
    } else if (index == 1) {
        if (clockwise) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            tap_code(KC_SPC);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
        } else {
            register_code(KC_LGUI);
            tap_code(KC_SPC);
            unregister_code(KC_LGUI);
        }
    }
    return false;
}

#endif // ENCODER_ENABLE
