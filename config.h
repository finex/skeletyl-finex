/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

/* Handedness. */
#define MASTER_RIGHT


/* Fine tuning */
// - Reduce errors on fast typing
/* #define IGNORE_MOD_TAP_INTERRUPT */
// - Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD
// - enable TAPPING_FORCE_HOLD only on single keys (home row mods) in order to allow auto-repeat on all other keys (like backspace or space).
#define TAPPING_FORCE_HOLD_PER_KEY
// - Recommended for heavy chording
#define QMK_KEYS_PER_SCAN 4
// - Custom tapping term
#undef TAPPING_TERM
#define TAPPING_TERM 220
#define TAPPING_TERM_PER_KEY


// - Mouse tuning
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          10
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA     2
#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED  1
#undef MOUSEKEY_DECELERATED_SPEED
#define MOUSEKEY_DECELERATED_SPEED 12
#undef MOUSEKEY_SCROLL_DELAY
#define MOUSEKEY_SCROLL_DELAY   100
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      22
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    85


#define COMBO_COUNT 1


#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

/* VBUS detection. */
#define USB_VBUS_PIN GP19

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
