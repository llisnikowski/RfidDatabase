#include "objects.hpp"
#include <Wire.h>

RfidRc522 rfid(rfidSS, rfidReset);
WifiCommunication wifi;
Database database;
Buzzer buzzer(buzzerPin);
Led ledGreen(ledGreenPin);
Led ledRed(ledRedPin);
Adafruit_SSD1306 display(screenWidth, screenHeight, &Wire);