#include "displayFunctions.hpp"
#include "objects.hpp"
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "database/person.hpp"


void displayMessage(String text){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,20);
  display.print(text);
  display.display();
}

void displayMessage(String text1, String text2){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,20);
  display.print(text1);
  display.setCursor(0,40);
  display.print(text2);
  display.display();
}

void displayCenterText(int x, int y, String text){
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(x, y);
  display.print(text);
  display.display();
}

void displayName(Person &person){
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.print(person.name);
  display.setCursor(0, 35);
  display.print(person.lastName);
  display.setTextSize(1);
  display.setCursor(0, 50);
  switch (person.status)
  {
  case PersonStatus::noaccess:
    display.print("Brak dostepu");
    break;
  case PersonStatus::fullaccess:
    display.print("Pelen dostep");
    break;
  }
  display.display();
}