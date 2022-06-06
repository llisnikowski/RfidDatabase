#pragma once
#include <Arduino.h>

class Person;

void displayMessage(String text);
void displayMessage(String text1, String text2);
void displayCenterText(int x, int y, String text);
void displayName(Person &person);