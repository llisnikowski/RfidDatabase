#include "basicFunctions.hpp"
#include "objects.hpp"
#include <Adafruit_SSD1306.h>
#include "displayFunctions.hpp"

void initAll()
{
  Serial.begin(115200);
  ledGreen.begin();
  ledRed.begin();
  SPI.begin();
  rfid.begin();
  wifi.begin(WIFI_SSID, WIFI_PASSWORD);
  wifi.setHostName(HOST_NAME);
  buzzer.begin();
  if(!display.begin(SSD1306_SWITCHCAPVCC, screenAddress)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;) delayUpdate(1000);
  }
  display.setTextColor(1);
}

void updateAll(){
  buzzer.update();
  ledGreen.update();
  ledRed.update();
}

void delayUpdate(int time){
  while(time>10){
    delay(10);
    time-=10;
    updateAll();
  }
  if(time){
    delay(time);
    updateAll();
  }
}

bool wifiConnect()
{
  displayMessage("Laczenie z wifi");
  while(wifi.status() != WL_CONNECTED) {  //łączenie z wifi
    delayUpdate(500);
  }
  displayMessage("Polaczono z wifi");
  delayUpdate(200);
  displayMessage("Sprawdzanie komunikacji z serwerem");
  delayUpdate(200);
  database.setWifiCommunication(&wifi);
  return database.ping();
}