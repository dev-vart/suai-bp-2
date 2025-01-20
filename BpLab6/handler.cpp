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
        cout << "=== �������� ������ ===" << endl;
        usershow(userarray, usersize);

        cout << endl;
        Massiv M(userarray, usersize);
        cout << "=== ����� Massiv ===" << endl;
        M.show();

        cout << endl;
        cout << "=== ���������� � Massiv ===" << endl;
        showinfoMassiv(M);

        cout << endl;
        M.ShellSortReversed();
        cout << "=== ��������������� �� �������� Massiv ===" << endl;
        M.show();

    } catch (const MyException& e) {
        cerr << "������� ����������: " << e.what() << std::endl;
        if (e.fatal_error) {
            cerr << endl << "��������� ���������� ������ ���������" << endl;
            return 1;
        }
    } catch (const std::exception& e) {
        cerr << "������� ����������� ����������: " << e.what() << std::endl;
        cerr << endl << "��������� ���������� ������ ���������" << endl;
        return 2;
    } catch (...) {
        cerr << "������� ����������� ����������." << std::endl;
        cerr << endl << "��������� ���������� ������ ���������" << endl;
        return 3;
    }

    cout << endl << "���������� ���������� ������ ���������" << endl;

    return 0;
}

void inputsize(size_t& size) {
    cout << "������� ������ ������� (1-30): ";
    cin >> size;
    while (cin.fail() || cin.peek() != '\n' || size < 1 || size > 50) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "������������ ������. ��������� ����: ";
        cin >> size;
    }
}

void userfill(float* userarray, size_t& usersize, RandomGen randomgen) {
    for (size_t i = 0; i < usersize; ++i) {
        userarray[i] = randomgen.rndreal(-9, 9);
    }
}

void usershow(const float* userarray, const size_t& usersize) {
    cout << "������[" << usersize << (usersize < 10 ? "]:  " : "]: ");
    for (size_t i = 0; i < usersize; ++i) cout << std::setw(6) << userarray[i] << ' ';
    cout << endl << "������:     ";
    for (size_t i = 0; i < usersize; ++i) cout << std::setw(6) << i << ' ';
    cout << endl;
}

void showinfoMassiv(Massiv M) {
    cout << "����� ������������� ��������� �������: " << M.sumpositive() << endl;
    cout << "������������ ��������� �������, ������������� "
            "����� ������������ �� ������ � ����������� �� "
            "������ ����������"
         << endl;
    M.multMaxMin();
}
