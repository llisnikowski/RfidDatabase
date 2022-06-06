#pragma once
#include <stdint.h>

//constexpr char WIFI_SSID[] = "wifi name";
//constexpr char WIFI_PASSWORD[] = "*****";
//const String HOST_NAME = "http://192.168.**.***/";

#ifdef BOARD_DEVKIT
constexpr uint8_t rfidSS = 5;
constexpr uint8_t rfidReset = 34;
constexpr uint8_t ledGreenPin = 32;
constexpr uint8_t ledRedPin = 25;
constexpr uint8_t buzzerPin = 33;

constexpr uint8_t screenWidth = 128;
constexpr uint8_t screenHeight = 64;
constexpr uint8_t screenAddress = 0x3C;
#endif

#ifdef BOARD_FIREBEETLE
constexpr uint8_t rfidSS = 5;
constexpr uint8_t rfidReset = 34;
constexpr uint8_t ledGreen = 32;
constexpr uint8_t ledRed = 35;
constexpr uint8_t buzzerPin = 33;

constexpr uint8_t screenWidth = 128;
constexpr uint8_t screenHeight 64;
constexpr uint8_t screenAddress 0x3D;
#endif