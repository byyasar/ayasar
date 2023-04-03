#pragma once
#include_next "board.h"
#undef STM32F103xB
#define STM32F103x6
#define HAL_USE_I2C TRUE



