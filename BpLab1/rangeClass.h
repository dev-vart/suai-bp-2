#pragma once

class Range
{   
    double left, right;
    public:
        void setLeft(double);
        void setRight(double);
        bool validrange();
        bool rangecheck(double);
};
