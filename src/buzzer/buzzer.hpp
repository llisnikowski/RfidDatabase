#pragma once
#include <Arduino.h>

enum class BuzzerMode{
    Off,
    On,
    Impuls
};

class Buzzer
{
public:
    explicit Buzzer(uint8_t pin, uint8_t channel=0);
    ~Buzzer();
    void begin();

    void turnOn(int tone=1000);
    void turnOff();
    void impuls(int time=1000, int tone=1000);

    void update();

private:
    uint8_t pin;
    uint8_t channel;
    BuzzerMode mode;
    unsigned long timer;
};


