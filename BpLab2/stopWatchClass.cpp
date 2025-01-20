#include "stopWatchClass.h"

stopwatch::stopwatch() : timePassed(std::chrono::duration<double>::zero()){
    std::cout << "Stopwatch created." << std::endl;
}

stopwatch::stopwatch(stopwatch& otherStopWatch)
    : startTime(otherStopWatch.startTime), timePassed(otherStopWatch.timePassed) {
    std::cout << "Stopwatch copied." << std::endl;
}

stopwatch::stopwatch(std::chrono::system_clock::time_point start, std::chrono::duration<double> time)
    : startTime(start), timePassed(time) {
    std::cout << "Stopwatch initialised." << std::endl;
}

stopwatch::~stopwatch()
{
    stopTime = std::chrono::system_clock::now();
    timePassed += stopTime - startTime;
    std::cout << "Stopwatch destroyed. Seconds passed: " << timePassed.count() << std::endl;
}

void stopwatch::start()
{
    startTime = std::chrono::system_clock::now();
    std::cout << "Stopwatch started." << std::endl;
}

void stopwatch::stop()
{
    stopTime = std::chrono::system_clock::now();
    timePassed += stopTime - startTime;
    std::cout << "Stopwatch stopped." << std::endl;
}

void stopwatch::show()
{   
    std::cout << "Seconds passed: " << timePassed.count() << std::endl;
}

void stopwatch::delay(int milliseconds) 
{
    auto start = std::chrono::steady_clock::now();
    while (std::chrono::steady_clock::now() - start < std::chrono::milliseconds(milliseconds)) { }
}