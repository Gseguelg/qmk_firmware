# USER_NAME = gseguelg  # uses files from users\gseguelg
TAP_DANCE_ENABLE = yes

RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = no
# CONSOLE_ENABLE = yes
MOUSEKEY_ENABLE = no    # Mouse keys(+1482)
USE_CCACHE = yes  # permite compilar más rápido utilizando el cache
LTO_ENABLE = yes # Link Time Optimization

OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes   # 128X32 OLED Screen

WPM_ENABLE = no   # WPM Calculation

SEND_STRING_ENABLE = yes

VIA_ENABLE = no    # Configuring keyboard with VIA
MIDI_ENABLE = no    # MIDI controls
# Enable debug information in the final binaries
# DEBUG_ENABLE = yes
# Disable optimisations for debugging purposes
# OPT = g

CFLAGS                 += -flto
EXTRAFLAGS             += -flto
