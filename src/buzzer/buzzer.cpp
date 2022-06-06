#include "buzzer.hpp"

Buzzer::Buzzer(uint8_t pin, uint8_t channel)
    :pin(pin), channel(channel), mode(BuzzerMode::Off), timer(0)
{
}

Buzzer::~Buzzer()
{
}

void Buzzer::begin()
{
    pinMode(pin, OUTPUT);
    ledcAttachPin(pin, channel);
}

void Buzzer::turnOn(int tone)
{
    mode = BuzzerMode::On;
    ledcWriteTone(channel, tone);
}

void Buzzer::turnOff()
{
    mode = BuzzerMode::Off;
    ledcWriteTone(channel, 0);
}


void Buzzer::impuls(int time, int tone)
{
    mode = BuzzerMode::Impuls;
    timer = millis() + static_cast<unsigned long>(time);
    ledcWriteTone(channel, tone);
}

void Buzzer::update()
{
    if(millis() >= timer){
        if(mode == BuzzerMode::Impuls){
            turnOff();
        }
    }
}