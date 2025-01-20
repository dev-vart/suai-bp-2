#pragma once

#include <chrono>
#include <iostream>
#include <thread>

class stopwatch {
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point stopTime;
    std::chrono::duration<double> timePassed;
    public:
        stopwatch();
        stopwatch(std::chrono::system_clock::time_point startTime, std::chrono::duration<double> timePassed);
        stopwatch(stopwatch& otherStopWatch);
        ~stopwatch();
        void start();
        void stop();
        void show();
        void delay(int milliseconds);
};
