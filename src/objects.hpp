#pragma once 
#include "config.hpp"
#include "rfid/rfidRc522.hpp"
#include "wifi/wifiCommunication.hpp"
#include "configWifi.hpp"
#include "database/database.hpp"
#include "buzzer/buzzer.hpp"
#include "led/led.hpp"
#include <Adafruit_SSD1306.h>

extern RfidRc522 rfid;
extern WifiCommunication wifi;
extern Database database;
extern Buzzer buzzer;
extern Led ledGreen;
extern Led ledRed;
extern Adafruit_SSD1306 display;