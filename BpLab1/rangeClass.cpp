#include "rangeClass.h"
#include <iostream>

void Range::setLeft(double value) 
{
    left = value;
}

void Range::setRight(double value) 
{
    right = value;
}

bool Range::validrange()
{
    if (left >= right){
        std::cout << "Left value must be less than right one. Try again!\n";
        return 0;
    }
    else
        return 1;
}

bool Range::rangecheck(double value) 
{
    if (value >= left && value < right)
        return 1;
    else
        return 0;
}