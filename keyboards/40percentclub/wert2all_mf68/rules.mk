# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = yes         # Console for debug(+400)
COMMAND_ENABLE = yes         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI controls
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
AUTO_SHIFT_ENABLE = no 	# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_auto_shift.md
LAYOUTS = 68_ansi
VIA_ENABLE = yes
LTO_ENABLE = yes
