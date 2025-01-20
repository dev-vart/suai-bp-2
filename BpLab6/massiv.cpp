#include "massiv.h"

Massiv::Massiv() : size(0), randomgen() {
    for (size_t i = 0; i < size; ++i) {
        array[i] = 0;
    }
}

Massiv::Massiv(const float* userarray, const size_t& usersize) : size(usersize) {
    if (usersize > capacity)
        throw MyException("Ошибка: размер массива не может быть больше " + std::to_string(capacity) + "!",
                          true);
    for (size_t i = 0; i < size; ++i) {
        array[i] = userarray[i];
    }
}

Massiv::~Massiv() { delete[] array; }

void Massiv::show() const {
    cout << "Массив[" << size << (size < 10 ? "]:  " : "]: ");
    for (size_t i = 0; i < size; ++i) cout << std::setw(6) << array[i] << ' ';
    cout << endl << "Индекс:     ";
    for (size_t i = 0; i < size; ++i) cout << std::setw(6) << i << ' ';
    cout << endl;
}

float Massiv::sumpositive() const {
    float sum{};
    for (size_t i = 0; i < size; ++i) {
        if (array[i] > 0) {
            sum += array[i];
        }
    }
    return sum;
}

float Massiv::multMaxMin() const {
    float product = 1, mxabs = array[0], mnabs = array[0];
    int mxi{}, mni{};

    for (size_t i = 0; i < size; ++i) {
        if (abs(array[i]) > abs(mxabs)) {
            mxabs = array[i];
            mxi = i;
        }
        if (abs(array[i]) < abs(mnabs)) {
            mnabs = array[i];
            mni = i;
        }
    }
    size_t left = (mxi < mni ? mxi : mni);
    size_t right = (mxi < mni ? mni : mxi);
    cout << "Считаем произведение между элементами " << left << " и " << right << ": " << endl;
    if (right - left <= 1)
        throw MyException("Ошибка: невозможно посчитать произведение, между рядом стоящими элементами!",
                          false);
    for (size_t i = left + 1; i < right; ++i) {
        product *= array[i];
        cout << array[i] << (i != right - 1 ? " * " : " = ");
    }
    if (product != 1) cout << product << endl;
    return product;
}

void Massiv::ShellSortReversed() {
    int step, i, j;
    float tmp{};
    step = size / 2;
    while (step > 0) {
        for (i = 0; i < static_cast<int>(size) - step; i++) {
            j = i;
            while (j >= 0) {
                if (array[j] < array[j + step]) {
                    tmp = array[j + step];
                    array[j + step] = array[j];
                    array[j] = tmp;
                    j -= step;
                } else {
                    j = -1;
                }
            }
        }
        step /= 2;
    }
}
