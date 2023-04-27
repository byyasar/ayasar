# Bootloader selection
# Cannot use `BOOTLOADER = stm32duino` due to the need to override
# `MCU_LDSCRIPT`, therefore all parameters need to be specified here manually.
OPT_DEFS += -DBOOTLOADER_STM32DUINO
MCU_LDSCRIPT = STM32F103x6_stm32duino_bootloader
BOOTLOADER_TYPE = stm32duino
#DFU_ARGS = -d 1EAF:0003 -a 2 -R
#DFU_SUFFIX_ARGS = -v 1EAF -p 0003

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

# LTO is required to fit the firmware into the available 24K of flash
LTO_ENABLE = yes
EEPROM_DRIVER = transient
ENCODER_ENABLE = yes   # Enable encoder
OLED_ENABLE=yes # Oled
#OLED_DRIVER = SSD1306

OPT_DEFS += -DHAL_USE_I2C=TRUE


