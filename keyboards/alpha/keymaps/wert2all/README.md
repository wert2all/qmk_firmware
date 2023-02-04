# Alpha 28-Key Keyboard Alternate Keymap
Alternate keymap for [Alpha 28-key keyboard](https://github.com/qmk/qmk_firmware/tree/master/keyboards/alpha).

## How-to

Build: 

    ./util/docker_build.sh alpha:wert2all

Generate keymap.json

    ./util/docker_cmd.sh qmk c2json -kb alpha -km wert2all -o keyboards/alpha/keymaps/wert2all/keymap.json keyboards/alpha/keymaps/wert2all/keymap.c

From vderm keymap

## Description
Instead of going up and down layers like in the original Alpha keyboard, I've made the bottom row keys all have alternate functions:
+ Like in the original Alpha28 keymap, the 2U spacebar is a shift key when held down and space when tapped
+ Z and M are Ctrl keys when held down or Z and M when tapped
+ X and N are Alt keys
+ C activates the function keys layer (arrows, page up/dn, esc, tab, etc.)
+ V activates the characters and numbers layer
+ C and V combined activated the F-keys layer (F1, F2, F3, etc.)
+ The enter key is an enter key in the home layer, backspace in the function keys and characters/numbers layer and a delete in the F-keys layer
+ While in the other layers, the bottom row acts like a "regular" bottom modified row: ctrl, alt, winkey

## Keymap
![keymap](https://imgur.com/ZbDz0eL.jpg)
