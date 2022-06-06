#include "timer.hpp"
#include <Arduino.h>

Timer::Timer(int time)
    :delay(time)
{
}

Timer::~Timer()
{
}

bool Timer::timeIsUp()
{
    return millis()>=nextTime;
}


void Timer::resetTime()
{
    nextTime = millis() + static_cast<unsigned long>(delay);
}