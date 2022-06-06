#pragma once
#include <Arduino.h>

enum class LedMode{
    Off,
    On,
    Impuls,
    Blink,
    BlinkInfinity
};

class Led
{
public:
    explicit Led(uint8_t pin);
    ~Led();
    void begin();

    void turnOff();
    void turnOn();
    void toggle();
    void impuls(int time);
    void blink(int delay, int count=0);

    void update();
private:
    void setTimer(int delay);
    void setOnOffMode();
    void toggleWithoutMode();

    uint8_t pin;
    LedMode mode;
    unsigned long timer;
    int counter;
    int period;
    bool state;
};


