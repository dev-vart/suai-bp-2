#include "WorkerClass.h"

#include <ctime>
#include <string>

Worker::Worker(const string &name, const string &education, int beginYear, int wage)
    : name(name), education(education), beginYear(beginYear), wage(wage) {
    // cout << "Создан ";show();
}

Intern::Intern(const string &name, const string &education, int beginYear, int wage, const string &position,
               int trialDuration, int bonus)
    : Worker(name, education, beginYear, wage),
      position(position),
      trialDuration(trialDuration),
      bonus(bonus) {
    internCnt++;
    // cout << "Создан "; show();
}

Senior::Senior(const string &name, const string &education, int beginYear, int wage, const string &department,
               int subordinatesNumber, int bonus)
    : Worker(name, education, beginYear, wage),
      department(department),
      subordinatesNumber(subordinatesNumber),
      bonus(bonus) {
    seniorCnt++;
    // cout << "Создан ";show();
}

Director::Director(const string &name, const string &education, int beginYear, int wage, int departmentNumber,
                   int bonus)
    : Worker(name, education, beginYear, wage), departmentNumber(departmentNumber), bonus(bonus) {
    // cout << "Создан ";show();
}

void Worker::show() {
    printf("Сотрудник %s:\n    Образование: %s | ... Год поступления на работу: %u | Оклад: %u\n",
           name.c_str(), education.c_str(), beginYear, wage);
}

void Intern::show() {
    printf(
        "Стажер %s:\n    Образование: %s | Год поступления на работу: %u | Оклад: %u | Должность: %s | "
        "Длительность испытательного срока: %u | Надбавка: %u\n\n",
        name.c_str(), education.c_str(), beginYear, wage, position.c_str(), trialDuration, bonus);
}

void Senior::show() {
    printf(
        "Руководитель %s:\n    Образование: %s | Год поступления на работу: %u | Оклад: %u | Отдел: %s | "
        "Кол-во подчиненных: %u | Надбавка: %u\n\n",
        name.c_str(), education.c_str(), beginYear, wage, department.c_str(), subordinatesNumber, bonus);
}

void Director::show() {
    printf(
        "Директор %s:\n    Образование: %s | Год поступления на работу: %u | Оклад: %u | Кол-во отделов: %u "
        "| Надбавка: %u\n\n",
        name.c_str(), education.c_str(), beginYear, wage, departmentNumber, bonus);
}

int Worker::set(const string &name, const string &education, int beginYear, int wage, int bonus) {
    if (name.size() > 99) {
        cout << "\033[31m"
             << "Ошибка: Максимальный размер поля "
                "Имя"
                " - 99 символов! Попробуйте снова!\n\n"
             << "\033[0m";
        return 1;
    } else if (education.size() > 66) {
        cout << "\033[31m"
             << "Ошибка: Максимальный размер поля "
                "Образование"
                " - 66 символов! Попробуйте снова!\n\n"
             << "\033[0m";
        return 2;
    } else if (beginYear < 2020) {
        cout << "\033[31m"
             << "Ошибка: Год поступления на работу не может быть раньше 2020! Попробуйте снова!\n\n"
             << "\033[0m";
        return 3;
    } else if (wage < 0 || bonus < 0) {
        cout << "\033[31m"
             << "Ошибка: Размер зарплаты или надбавки не может быть отрицательным! Попробуйте снова!\n\n"
             << "\033[0m";
        return 4;
    }
    this->name = name;
    this->education = education;
    this->beginYear = beginYear;
    this->wage = wage;
    return 0;
}

int Intern::set(const string &name, const string &education, int beginYear, int wage, const string &position,
                int trialDuration, int bonus) {
    if (Worker::set(name, education, beginYear, wage, bonus))
        return 1;
    else if (position.size() > 66) {
        cout << "\033[31m"
             << "Ошибка: Максимальный размер поля "
                "Должность"
                " - 66 символов! Попробуйте снова!\n\n"
             << "\033[0m";
        return 2;
    } else if (trialDuration < 0) {
        cout << "\033[31m"
             << "Ошибка: Длительность испытательного срока не может быть отрицательной! Попробуйте снова!\n\n"
             << "\033[0m";
        return 3;
    }
    this->position = position;
    this->trialDuration = trialDuration;
    this->bonus = bonus;
    return 0;
}

int Senior::set(const string &name, const string &education, int beginYear, int wage,
                const string &department, int subordinatesNumber, int bonus) {
    if (Worker::set(name, education, beginYear, wage, bonus))
        return 1;
    else if (department.size() > 66) {
        cout << "\033[31m"
             << "Ошибка: Максимальный размер поля "
                "Отдел"
                " - 66 символов! Попробуйте снова!\n\n"
             << "\033[0m";
        return 2;
    } else if (subordinatesNumber < 0) {
        cout << "\033[31m"
             << "Ошибка: Количество подчиненных не может быть отрицательным! Попробуйте снова!\n\n"
             << "\033[0m";
        return 3;
    }
    this->department = department;
    this->subordinatesNumber = subordinatesNumber;
    this->bonus = bonus;
    return 0;
}

int Director::set(const string &name, const string &education, int beginYear, int wage, int departmentNumber,
                  int bonus) {
    if (Worker::set(name, education, beginYear, wage, bonus))
        return 1;
    else if (departmentNumber < 0) {
        cout << "\033[31m"
             << "Ошибка: Количество отделов не может быть отрицательным! Попробуйте снова!\n\n"
             << "\033[0m";
        return 2;
    }
    this->departmentNumber = departmentNumber;
    this->bonus = bonus;
    return 0;
}

int Worker::getSalary() { return wage; }

int Intern::getSalary() { return wage + bonus; }

int Senior::getSalary() { return wage + bonus; }

int Director::getSalary() { return wage + bonus; }

string Worker::getRublesRight() {
    string strRubles{};
    unsigned sal = getSalary();

    if (sal % 100 >= 11 && sal % 100 <= 20)
        strRubles = "рублей";
    else if (sal % 10 == 2 || sal % 10 == 3 || sal % 10 == 4)
        strRubles = "рубля";
    else if (sal % 10 == 1)
        strRubles = "рубль";
    else
        strRubles = "рублей";

    return strRubles;
}

string Worker::getWorkExperience() {
    using namespace std;

    time_t t = time(nullptr);
    tm *const loctm = localtime(&t);
    unsigned years = 1900 + loctm->tm_year - beginYear;

    std::string strYears{};
    if (years % 100 >= 11 && years % 100 <= 20)
        strYears = "лет";
    else if (years % 10 == 2 || years % 10 == 3 || years % 10 == 4)
        strYears = "года";
    else if (years % 10 == 1)
        strYears = "год";
    else
        strYears = "лет";

    return std::to_string(years) + ' ' + strYears;
}

unsigned Worker::internCnt = 0;
unsigned Worker::seniorCnt = 0;

string Senior::getSubordinatesNumber() {
    string strInternCnt{};

    if (internCnt % 100 >= 11 && internCnt % 100 <= 20)
        strInternCnt = "стажеров";
    else if (internCnt % 10 == 2 || internCnt % 10 == 3 || internCnt % 10 == 4)
        strInternCnt = "стажера";
    else if (internCnt % 10 == 1)
        strInternCnt = "стажер";
    else
        strInternCnt = "стажеров";

    return std::to_string(internCnt) + ' ' + strInternCnt;
}

string Director::getSubordinatesNumber() {
    string strSeniorCnt{};

    if (seniorCnt % 100 >= 11 && seniorCnt % 100 <= 20)
        strSeniorCnt = "руководителей";
    else if (seniorCnt % 10 == 2 || seniorCnt % 10 == 3 || seniorCnt % 10 == 4)
        strSeniorCnt = "руководителя";
    else if (seniorCnt % 10 == 1)
        strSeniorCnt = "руководитель";
    else
        strSeniorCnt = "руководителей";

    return std::to_string(seniorCnt) + ' ' + strSeniorCnt;
}

string Worker::getName() { return name; }