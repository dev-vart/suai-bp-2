#include <iostream>

#include "WorkerClass.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << endl;
    setlocale(LC_ALL, "Russian");
    Intern I1("Сергей Балакирев", "ГУАП", 2022);
    Intern I2("Петр Гусев", "ГУАП", 2022);
    Intern I3("Вадим Ручкин", "ГУАП", 2022);

    Senior S1("Григорий Лешин", "МГУ", 2020);
    Director D1("Кирилл Левский", "РТУ");

    I1.set("Сергей Балакирев", "ГУАП", 2022, 22400, "DevOps", 1);
    I1.show();
    I2.set("Петр Гусев", "ГУАП", 2022, 12400, "Помощник", 1);
    I2.show();
    I3.set("Вадим Ручкин", "ГУАП", 2022, 26300, "Программист", 1);
    I3.show();

    S1.set("Григорий Лешин", "МГУ", 2020, 67120, "CRM");
    S1.show();

    D1.show();
    D1.set("Кирилл Левский", "РТУ", 2024, 120399, -1, -2);
    D1.show();
    D1.set("Кирилл Левский", "РТУ", 2023, 120399, 3, 34000);
    D1.show();

    cout << "========= Зарплаты ========" << endl;
    cout << "Стажер: " << I1.Worker::getSalary() << "(оклад) + " << I1.getSalary() - I1.Worker::getSalary()
         << "(надбавка) = " << I1.getSalary() << ' ' << I1.getRublesRight() << endl;
    cout << "Руководитель: " << S1.Worker::getSalary() << "(оклад) + "
         << S1.getSalary() - S1.Worker::getSalary() << "(надбавка) = " << S1.getSalary() << ' '
         << S1.getRublesRight() << endl;
    cout << "Директор: " << D1.Worker::getSalary() << "(оклад) + " << D1.getSalary() - D1.Worker::getSalary()
         << "(надбавка) = " << D1.getSalary() << ' ' << D1.getRublesRight() << endl
         << endl;

    cout << "========= Опыт Работы ========" << endl;
    cout << "Стажер " << I1.getName() << ": " << I1.getWorkExperience() << endl;
    cout << "Руководитель " << S1.getName() << ": " << S1.getWorkExperience() << endl;
    cout << "Директор " << D1.getName() << ": " << D1.getWorkExperience() << endl << endl;

    cout << "========= Подчиненные ========" << endl;
    cout << "Руководитель " << S1.getName() << ": " << S1.getSubordinatesNumber() << endl;
    cout << "Директор " << D1.getName() << ": " << D1.getSubordinatesNumber() << endl << endl;

    return 0;
}
