#pragma once
#include <stdint.h>


#ifdef BOARD_DEVKIT
constexpr uint8_t rfidSS = 5;
constexpr uint8_t rfidReset = 34;
constexpr uint8_t ledGreenPin = 32;
constexpr uint8_t ledRedPin = 25;
constexpr uint8_t buzzerPin = 33;
#endif

#ifdef BOARD_FIREBEETLE
constexpr uint8_t rfidSS = 5;
constexpr uint8_t rfidReset = 34;
constexpr uint8_t ledGreen = 32;
constexpr uint8_t ledRed = 35;
constexpr uint8_t buzzerPin = 33;
#endif