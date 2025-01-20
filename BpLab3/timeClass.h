#pragma once

#include <iostream>

class Time {
    int hour;    
    int min;
    int sec;
    public:
        Time();
        Time(int hour, int min, int sec);
        Time(const Time& otherTime);
        ~Time();
        int isValid();
        void show();
        Time operator+=(int m);
        friend Time operator-(const Time& a, const Time& b);
        Time& operator=(Time e);
        friend bool operator==(const Time& a, const Time& b);
        friend bool operator!=(const Time& a, const Time& b);
        void normal();
};
