#pragma once

#include <iomanip>
#include <iostream>
#include <string>

#include "myexception.h"
#include "rndgen.h"

using std::cout;
using std::endl;
using std::size_t;

class Massiv {
   public:
    Massiv();
    Massiv(const float* userarray, const size_t& usersize);
    ~Massiv();
    void show() const;
    float sumpositive() const;
    float multMaxMin() const;
    void ShellSortReversed();

   private:
    static const size_t capacity = 30;
    size_t size{};
    RandomGen randomgen;
    float* array = new float[capacity];
    bool full() const { return size == capacity; };
    bool empty() const { return size == 0; };
};