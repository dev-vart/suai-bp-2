#pragma once

#include <algorithm>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::size_t;
using std::vector;

template <typename T>
class Massiv {
   public:
    Massiv();
    explicit Massiv(const vector<T>& vec);
    ~Massiv();
    T* begin() const { return array; };
    T* end() const { return array + size; };
    void show() const;
    void multiply(const T& mult);
    void shiftRight(size_t shift);
    int squareMoreThanP(int p) const;

   private:
    static const size_t capacity = 10;
    size_t size{};
    T* array = new T[capacity];
};

template <typename T>
Massiv<T>::Massiv() : size(0) {
    std::fill(begin(), end(), 0);
}

template <typename T>
Massiv<T>::Massiv(const vector<T>& vec) : size(vec.size()) {
    if (size > capacity) {
        throw std::out_of_range("Ошибка: размер массива не может быть больше " + std::to_string(capacity) +
                                "!");
    }
    for (size_t i = 0; i < size; ++i) {
        array[i] = vec[i];
    }
}

template <typename T>
Massiv<T>::~Massiv() {
    delete[] array;
}

template <typename T>
void Massiv<T>::show() const {
    cout << "Massiv[" << size << (size < 10 ? "]:  " : "]: ");
    std::for_each(begin(), end(), [](const T& x) { cout << std::setw(6) << x << " "; });
    cout << endl << "Индекс:     ";
    for (size_t i = 0; i < size; ++i) cout << std::setw(6) << i << ' ';
    cout << endl;
}

template <typename T>
void Massiv<T>::multiply(const T& mult) {
    std::for_each(begin(), end(), [mult](T& x) { x *= mult; });
}

template <typename T>
void Massiv<T>::shiftRight(size_t shift) {
    if (size == 0) return;
    shift %= size;
    if (shift == 0) return;
    std::rotate(begin(), array + (size - shift), end());
}

template <typename T>
int Massiv<T>::squareMoreThanP(int p) const {
    int count = 0;
    std::for_each(begin(), end(), [&count, p](const T& x) { count += ((x * x) > p); });
    return count;
}