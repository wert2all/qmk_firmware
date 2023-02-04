#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* RGB */
#define RGBLED_NUM 5
#define RGBLIGHT_SLEEP

#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#define RGBLIGHT_DEFAULT_HUE 234
#define RGBLIGHT_DEFAULT_VAL 190

#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_MOOD + 2
