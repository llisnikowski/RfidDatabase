#pragma once
#include <stdint.h>


#ifdef BOARD_DEVKIT
constexpr uint8_t rfidSS = 5;
constexpr uint8_t rfidReset = 34;
#endif

#ifdef BOARD_FIREBEETLE
constexpr uint8_t rfidSS = 5;
constexpr uint8_t rfidReset = 34;
#endif