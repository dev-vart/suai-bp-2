#include "TimeClass.h"

Time::Time() : hour(0), min(0), sec(0) {
    printf("Time %.2d:%.2d:%.2d created with default values\n", hour, min, sec);
}

Time::Time(int h, int m, int s) : hour(h), min(m), sec(s) {
    if (!isValid()) 
            printf("Time %.2d:%.2d:%.2d initialised\n", hour, min, sec);
}

Time::Time(const Time& otherTime) : hour(otherTime.hour), min(otherTime.min), sec(otherTime.sec) {
    if (!isValid()) 
            printf("Time %.2d:%.2d:%.2d copied\n", hour, min, sec);
}

Time::~Time() {
        printf("Time %.2d:%.2d:%.2d destroyed\n", hour, min, sec);
}

int Time::isValid() {
    int errorcnt{};

    if (hour < 0 || hour > 23) errorcnt++;
    if (min < 0 || min > 59) errorcnt++;
    if (sec < 0 || sec > 59) errorcnt++;

    if (errorcnt) {
        printf("Error: Time %.2d:%.2d:%.2d can't be initialised properly: wrong input. Errors found: %d\n", hour, min, sec, errorcnt);
        printf("Time initialisation example: 09:07:01\n");
    }

    return errorcnt;

}

void Time::show() {
    printf("This Time is %.2d:%.2d:%.2d\n", hour, min, sec);
}

Time Time::operator+=(int m) {
        min += m;
        normal();
        return *this;
}

void Time::normal() {
    min += (sec >= 0) ? sec / 60 : sec / 60 - 1;
    sec = (60 + sec) % 60;
    hour += (min >= 0) ? min / 60 : min / 60 - 1;
    min = (60 + min) % 60;
    hour = (24 + hour) % 24;
}

Time& Time::operator=(const Time e) {
    if (this != &e) {
        hour = e.hour;
        min = e.min;
        sec = e.sec;
    }
    return *this;
}

Time operator-(const Time& a, const Time& b) {
    Time TimeResult;
    TimeResult.hour = a.hour - b.hour;
    TimeResult.min = a.min - b.min;
    TimeResult.sec = a.sec - b.sec;
    TimeResult.normal();
    return TimeResult;
}

bool operator==(const Time& a, const Time& b) {
    if (a.hour != b.hour) return false;
    if (a.min != b.min) return false;
    if (a.sec != b.sec) return false;
    return true;
}

bool operator!=(const Time& a, const Time& b) {
    if (a.hour == b.hour) return false;
    if (a.min == b.min) return false;
    if (a.sec == b.sec) return false;
    return true;
}