#if defined(arduino_main)
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "objects.hpp"
#include "basicFunctions.hpp"
#include "displayFunctions.hpp"
#include "timer/timer.hpp"

void setup() 
{
  initAll();
  ledRed.blink(500);
  if(wifiConnect()){
    displayMessage("Udane polaczenie z serwerem");
    ledRed.turnOn();
    buzzer.impuls(200,1000);
  }
  else{
    displayMessage("Brak polaczenia z serwerem");
    for(int i=0; i<3;i++){
      buzzer.turnOn(2000);
      delayUpdate(200);
      buzzer.turnOff();
      delayUpdate(200);
    }
    for(;;);
  }

  displayMessage("Zbliz karte");

}

void loop() 
{

  if(rfid.detectCard()){
    timer5s.resetTime();
    RfidUid uid = rfid.getUid();
    Serial.println(uid.getFullUid());
    if(database.findUid(uid)){
      Person person = database.getPerson();
      displayName(person);
      switch (person.status)
      {
      case PersonStatus::noaccess:
        buzzer.impuls(200,2000);
        ledRed.blink(50,20);
        ledGreen.turnOff();
        break;
      case PersonStatus::fullaccess:
        buzzer.impuls(200,1000);
        ledRed.turnOn();
        ledGreen.blink(50,60);
        break;
      default:
        displayMessage("Brak osoby","w bazie danych");
        buzzer.impuls(100,1500);
        ledRed.blink(100,6);
        ledGreen.turnOff();
        break;
      }
    }
    else{
      displayMessage("Brak osoby","w bazie danych");
      buzzer.impuls(100,1500);
      ledRed.blink(100,6);
      ledGreen.turnOff();
    }
    rfid.stop();
    Serial.print(".");
    delayUpdate(500);
  }
  
  if(timer5s.timeIsUp()){
    displayMessage("Zbliz karte");
  }

  rfid.stop();
  updateAll();
  delay(10);
}
#endif





