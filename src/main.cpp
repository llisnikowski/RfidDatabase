#if defined(arduino_main)
#include <Arduino.h>
#include <SPI.h>
#include "config.hpp"
#include "rfid/rfidRc522.hpp"
#include "wifi/wifiCommunication.hpp"
#include "configWifi.hpp"
//#include "database/database.hpp"



String HOST_NAME = "http://192.168.30.185/";

//#include <WiFi.h>
//#include <HTTPClient.h>

RfidRc522 rfid(rfidSS, rfidReset);
WifiCommunication wifi;


void setup() 
{
  Serial.begin(115200);
  SPI.begin();
  rfid.begin();

  wifi.begin(WIFI_SSID, WIFI_PASSWORD);
  wifi.setHostName(HOST_NAME);

  Serial.println("Connecting");
  while(wifi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  WifiExample(wifi);
  

}

void loop() 
{
  delay(100);
  rfidExample(rfid);


}

#endif