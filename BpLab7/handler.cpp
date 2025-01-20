#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>

#include "massiv.h"
#include "rndgen.h"

#define MAX_ARRAY_SIZE 10
#define INT_P 10

#define MENU_SHORT 1
#define MENU_REAL 2

#define MENU_MAIN_SHIFT 1
#define MENU_MAIN_MULT10 2
#define EXIT_MENU 3

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::vector;

void inputsize(size_t& size);

void menuShortorReal(unsigned& menupoint);

void menuMain(unsigned& menupoint);

void wait();

template <typename T>
void vecShow(const vector<T>& vecShort);

template <typename T>
void showState(const vector<T>& userVec, const Massiv<T>& M);

template <typename T>
void cycleMenu(const vector<T>& vec, Massiv<T>& M);

int main() {
    setlocale(LC_ALL, "");
    printf("\033[H\033[J");

    size_t usersize{};
    unsigned menupoint{};
    RandomGen randomgen;

    inputsize(usersize);

    // ����� �����
    vector<short> vecShort(usersize);
    std::generate(vecShort.begin(), vecShort.end(), [&randomgen]() { return randomgen.rnd(-5, 5); });
    Massiv<short> MS(vecShort);

    // ������������ �����
    vector<float> vecReal(usersize);
    std::generate(vecReal.begin(), vecReal.end(), [&randomgen]() { return randomgen.rndreal(-5, 5); });
    Massiv<float> MR(vecReal);

    bool exit_program(false);
    while (!exit_program) {
        printf("\033[H\033[J");
        menuShortorReal(menupoint);
        switch (menupoint) {
            case MENU_SHORT:
                cycleMenu(vecShort, MS);
                break;
            case MENU_REAL:
                cycleMenu(vecReal, MR);
                break;
            case EXIT_MENU:
                exit_program = true;
                break;
        }
    }

    cout << endl << "--- ���������� ������ ��������� ---" << endl;

    return 0;
}

void inputsize(size_t& size) {
    cout << "������� ������ ������� (1-" << MAX_ARRAY_SIZE << "): ";
    cin >> size;
    while (cin.fail() || cin.peek() != '\n' || size < 1 || size > MAX_ARRAY_SIZE) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "������������ ������. ��������� ����: ";
        cin >> size;
    }
}

void menuShortorReal(unsigned& menupoint) {
    cout << "=== ���� ===" << endl;
    cout << "1. ����� �����" << endl;
    cout << "2. ������������ �����" << endl;
    cout << "3. �����" << endl;
    cout << "������� ����� ����: ";
    cin >> menupoint;
    while (cin.fail() || cin.peek() != '\n' || menupoint > 3) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "��� �� ����� ����. ��������� ����: ";
        cin >> menupoint;
    }
}

void menuMain(unsigned& menupoint) {
    cout << "=== ���� ===" << endl;
    cout << "1. C������� ��� �������� ������� ������ �� 2 ��������" << endl;
    cout << "2. �������� ��� �������� ������� �� 10" << endl;
    cout << "3. �����" << endl;
    cout << "������� ����� ����: ";
    cin >> menupoint;
    while (cin.fail() || cin.peek() != '\n' || menupoint > 3) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "��� �� ����� ����. ��������� ����: ";
        cin >> menupoint;
    }
}

template <typename T>
void vecShow(const vector<T>& vec) {
    cout << "������[" << vec.size() << (vec.size() < 10 ? "]:  " : "]: ");
    std::for_each(vec.begin(), vec.end(), [](T x) { cout << std::setw(6) << x << " "; });

    cout << endl << "������:     ";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << std::setw(6) << i << ' ';
    }

    cout << endl;
}

void wait() {
    getchar();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
void showState(const vector<T>& userVec, const Massiv<T>& M) {
    cout << "=== �������� ������ ===" << endl;
    vecShow(userVec);
    cout << endl;

    cout << "=== ������ ������ Massiv ===" << endl;
    M.show();
}

template <typename T>
void cycleMenu(const vector<T>& vec, Massiv<T>& M) {
    unsigned menupoint{};
    bool exit_program(false);
    while (!exit_program) {
        printf("\033[H\033[J");
        showState(vec, M);
        cout << endl
             << "���������� ���������, ������� ������� ������ p (p=" << INT_P
             << "): " << M.squareMoreThanP(10) << endl
             << endl;
        menuMain(menupoint);
        switch (menupoint) {
            case MENU_MAIN_SHIFT:
                M.shiftRight(2);
                break;
            case MENU_MAIN_MULT10:
                M.multiply(10);
                break;
            case EXIT_MENU:
                exit_program = true;
                break;
        }
    }
}
