#include <iostream>

#include "WorkerClass.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << endl;
    setlocale(LC_ALL, "Russian");
    Intern I1("������ ���������", "����", 2022);
    Intern I2("���� �����", "����", 2022);
    Intern I3("����� ������", "����", 2022);

    Senior S1("�������� �����", "���", 2020);
    Director D1("������ �������", "���");

    I1.set("������ ���������", "����", 2022, 22400, "DevOps", 1);
    I1.show();
    I2.set("���� �����", "����", 2022, 12400, "��������", 1);
    I2.show();
    I3.set("����� ������", "����", 2022, 26300, "�����������", 1);
    I3.show();

    S1.set("�������� �����", "���", 2020, 67120, "CRM");
    S1.show();

    D1.show();
    D1.set("������ �������", "���", 2024, 120399, -1, -2);
    D1.show();
    D1.set("������ �������", "���", 2023, 120399, 3, 34000);
    D1.show();

    cout << "========= �������� ========" << endl;
    cout << "������: " << I1.Worker::getSalary() << "(�����) + " << I1.getSalary() - I1.Worker::getSalary()
         << "(��������) = " << I1.getSalary() << ' ' << I1.getRublesRight() << endl;
    cout << "������������: " << S1.Worker::getSalary() << "(�����) + "
         << S1.getSalary() - S1.Worker::getSalary() << "(��������) = " << S1.getSalary() << ' '
         << S1.getRublesRight() << endl;
    cout << "��������: " << D1.Worker::getSalary() << "(�����) + " << D1.getSalary() - D1.Worker::getSalary()
         << "(��������) = " << D1.getSalary() << ' ' << D1.getRublesRight() << endl
         << endl;

    cout << "========= ���� ������ ========" << endl;
    cout << "������ " << I1.getName() << ": " << I1.getWorkExperience() << endl;
    cout << "������������ " << S1.getName() << ": " << S1.getWorkExperience() << endl;
    cout << "�������� " << D1.getName() << ": " << D1.getWorkExperience() << endl << endl;

    cout << "========= ����������� ========" << endl;
    cout << "������������ " << S1.getName() << ": " << S1.getSubordinatesNumber() << endl;
    cout << "�������� " << D1.getName() << ": " << D1.getSubordinatesNumber() << endl << endl;

    return 0;
}
