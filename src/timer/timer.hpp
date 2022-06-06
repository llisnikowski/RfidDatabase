#pragma once

class Timer
{
public:
    Timer(int time);
    ~Timer();

    bool timeIsUp();
    void resetTime();

private:
    int delay;
    unsigned long nextTime;
};


