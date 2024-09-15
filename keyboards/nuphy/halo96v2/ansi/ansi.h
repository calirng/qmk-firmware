/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "color.h"
#include "quantum_keycodes.h"

enum custom_keycodes {
    RF_DFU = QK_KB_0,
    LNK_USB,
    LNK_RF,
    LNK_BLE1,
    LNK_BLE2,
    LNK_BLE3,

    MAC_TASK,
    MAC_SEARCH,
    MAC_VOICE,
    MAC_CONSOLE,
    MAC_DND,

    WIN_LOCK,
    DEV_RESET,
    SLEEP_MODE,
    BAT_SHOW,
    RGB_TEST,
    SHIFT_GRV,

    SIDE_VAI,
    SIDE_VAD,
    SIDE_MOD_A,
    SIDE_MOD_B,
    SIDE_HUI,
    SIDE_SPI,
    SIDE_SPD,

    TOG_USB_SLP,
    TOG_CAPS_IND,
    DEBOUNCE_PRESS_INC,
    DEBOUNCE_PRESS_DEC,
    DEBOUNCE_PRESS_SHOW,
    SLEEP_TIMEOUT_INC,
    SLEEP_TIMEOUT_DEC,
    SLEEP_TIMEOUT_SHOW,
    MAC_GLOBE,
    DEBOUNCE_RELEASE_INC,
    DEBOUNCE_RELEASE_DEC,
    DEBOUNCE_RELEASE_SHOW,
    TOG_DEEP_SLEEP,
    TOG_POWER_ON_ANIMATION,
    TOG_BAT_IND_NUM,
    SOCDON,
    SOCDOFF,
    SOCDTOG,
    FW_VERSION,
};

#define MAC_PRT G(S(KC_3))
#define MAC_PRTA G(S(KC_4))
#define WIN_PRTA G(S(KC_S))

// struct to save configs
typedef struct {
    uint8_t been_initiated;
    uint8_t usb_sleep_toggle : 1;
    uint8_t deep_sleep_toggle : 1;
    uint8_t sleep_toggle : 1;
    uint8_t debounce_press_ms;
    uint8_t debounce_release_ms;
    uint8_t sleep_timeout;
    uint8_t caps_indicator_type;
    // (top) side light config
    uint8_t side_mode_a;
    uint8_t side_mode_b;
    uint8_t side_brightness;
    uint8_t side_speed;
    uint8_t side_rgb;
    uint8_t side_color;
    uint8_t side_use_custom_color : 1;
    HSV     side_custom_color;
    uint8_t power_show : 1;
    uint8_t battery_indicator_brightness;
    // custom keys highlight
    uint8_t toggle_custom_keys_highlight : 1;
    uint8_t detect_numlock_state : 1;
    uint8_t battery_indicator_numeric : 1;
    uint8_t show_socd_indicator : 1;
} kb_config_t;

#ifdef VIA_ENABLE
enum via_indicator_value {
    id_usb_sleep_toggle    = 0,
    id_debounce_press      = 1,
    id_debounce_release    = 2,
    id_sleep_timeout       = 3,
    id_caps_indicator_type = 4,
    id_sleep_toggle        = 5,
    id_deep_sleep_toggle   = 6,
    // side light controls
    id_side_light_mode_a            = 10,
    id_side_light_mode_b            = 11,
    id_side_light_speed             = 12,
    id_side_light_color             = 13,
    id_side_light_brightness        = 14,
    id_side_use_custom_color        = 15,
    id_side_custom_color            = 16,
    id_power_on_animation           = 20,
    id_battery_indicator_brightness = 21,
    id_toggle_custom_keys_highlight = 22,
    id_toggle_detect_numlock_state  = 23,
    id_battery_indicator_numeric    = 24,
    id_toggle_socd_indicator        = 25,
};

// function declaration
void indicator_config_set_value(uint8_t *data);
void indicator_config_get_value(uint8_t *data);
void _set_color(HSV *color, uint8_t *data);
void _get_color(HSV *color, uint8_t *data);
#endif

extern kb_config_t g_config;

void save_config_to_eeprom(void);
void load_config_from_eeprom(void);
void init_g_config(void);
