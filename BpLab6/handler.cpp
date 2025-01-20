#include <iomanip>
#include <iostream>
#include <limits>

#include "massiv.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

void inputsize(size_t& size);

void userfill(float* userarray, size_t& usersize, RandomGen randomgen);

void usershow(const float* userarray, const size_t& usersize);

void showinfoMassiv(Massiv M);

int main() {
    setlocale(LC_ALL, "Russian");
    system("cls");

    size_t usersize{};
    inputsize(usersize);
    float* userarray = new float[usersize];
    RandomGen randomgen;

    try {
        cout << endl;
        userfill(userarray, usersize, randomgen);
        cout << "=== Исходный массив ===" << endl;
        usershow(userarray, usersize);

        cout << endl;
        Massiv M(userarray, usersize);
        cout << "=== Класс Massiv ===" << endl;
        M.show();

        cout << endl;
        cout << "=== Информация о Massiv ===" << endl;
        showinfoMassiv(M);

        cout << endl;
        M.ShellSortReversed();
        cout << "=== Отсортированный по убыванию Massiv ===" << endl;
        M.show();

    } catch (const MyException& e) {
        cerr << "Поймано исключение: " << e.what() << std::endl;
        if (e.fatal_error) {
            cerr << endl << "Аварийное завершение работы программы" << endl;
            return 1;
        }
    } catch (const std::exception& e) {
        cerr << "Поймано стандартное исключение: " << e.what() << std::endl;
        cerr << endl << "Аварийное завершение работы программы" << endl;
        return 2;
    } catch (...) {
        cerr << "Поймано неизвестное исключение." << std::endl;
        cerr << endl << "Аварийное завершение работы программы" << endl;
        return 3;
    }

    cout << endl << "Нормальное завершение работы программы" << endl;

    return 0;
}

void inputsize(size_t& size) {
    cout << "Введите размер массива (1-30): ";
    cin >> size;
    while (cin.fail() || cin.peek() != '\n' || size < 1 || size > 50) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Некорректные данные. Повторите ввод: ";
        cin >> size;
    }
}

void userfill(float* userarray, size_t& usersize, RandomGen randomgen) {
    for (size_t i = 0; i < usersize; ++i) {
        userarray[i] = randomgen.rndreal(-9, 9);
    }
}

void usershow(const float* userarray, const size_t& usersize) {
    cout << "Массив[" << usersize << (usersize < 10 ? "]:  " : "]: ");
    for (size_t i = 0; i < usersize; ++i) cout << std::setw(6) << userarray[i] << ' ';
    cout << endl << "Индекс:     ";
    for (size_t i = 0; i < usersize; ++i) cout << std::setw(6) << i << ' ';
    cout << endl;
}

void showinfoMassiv(Massiv M) {
    cout << "Сумму положительных элементов массива: " << M.sumpositive() << endl;
    cout << "Произведение элементов массива, расположенных "
            "между максимальным по модулю и минимальным по "
            "модулю элементами"
         << endl;
    M.multMaxMin();
}
