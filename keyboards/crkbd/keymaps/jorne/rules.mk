MOUSEKEY_ENABLE     = no     # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
RGBLIGHT_ENABLE     = yes    # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = yes     # Enable one-hand typing
VIA_ENABLE          = yes         # Enable VIA
OLED_ENABLE = yes
OLED_DRIVER_ENABLE = yes
OLED_DRIVER = SSD1306
LTO_ENABLE          = yes
NKRO_ENABLE = no           # USB Nkey Rollover

SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c

# VPATH += keyboards/crkbd/lib
# LIB_SRC += ssd1306.c i2c.c