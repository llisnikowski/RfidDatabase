#include "led.hpp"


Led::Led(uint8_t pin)
    :pin(pin)
{
}

Led::~Led()
{
}

void Led::begin()
{
    pinMode(pin, OUTPUT);
}

void Led::turnOff()
{
    mode = LedMode::Off;
    state = false;
    digitalWrite(pin, LOW);
}

void Led::turnOn()
{
    mode = LedMode::On;
    state = true;
    digitalWrite(pin, HIGH);
}

void Led::toggle()
{
    if(digitalRead(pin)){
        turnOff();
    }
    else{
        turnOn();
    }
}

void Led::impuls(int time)
{
    mode = LedMode::Impuls;
    digitalWrite(pin, HIGH);
    state = true;
    setTimer(time);
}

void Led::blink(int delay, int count)
{
    if(mode != LedMode::Off && mode != LedMode::On) turnOff();
    if(count == 0){
        mode = LedMode::BlinkInfinity;
    }
    else{
        mode = LedMode::Blink;
        counter = count-1;
    }
    toggleWithoutMode();
    period = delay;
    setTimer(delay);
}

void Led::update()
{
    if(timer<=millis()){
        switch (mode)
        {
        case LedMode::Impuls:
            turnOff();
            break;
        case LedMode::Blink:
            toggleWithoutMode();
            setTimer(period);
            if(!(--counter)){
                setOnOffMode();
            }
            break;
        case LedMode::BlinkInfinity:
            toggleWithoutMode();
            setTimer(period);
            break;
        }
    }
}



void Led::setTimer(int delay)
{
    timer = millis() + static_cast<unsigned long>(delay);
}

void Led::setOnOffMode()
{
    if(state){
        mode = LedMode::On;
    }
    else{
        mode = LedMode::Off;
    }
}

void Led::toggleWithoutMode()
{
    if(state){
        digitalWrite(pin,LOW);
        state = false;
    }
    else{
        digitalWrite(pin,HIGH);
        state = true;
    }
}