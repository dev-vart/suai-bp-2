#include "WorkerClass.h"

#include <ctime>
#include <string>

Worker::Worker(const string &name, const string &education, int beginYear, int wage)
    : name(name), education(education), beginYear(beginYear), wage(wage) {
    // cout << "������ ";show();
}

Intern::Intern(const string &name, const string &education, int beginYear, int wage, const string &position,
               int trialDuration, int bonus)
    : Worker(name, education, beginYear, wage),
      position(position),
      trialDuration(trialDuration),
      bonus(bonus) {
    internCnt++;
    // cout << "������ "; show();
}

Senior::Senior(const string &name, const string &education, int beginYear, int wage, const string &department,
               int subordinatesNumber, int bonus)
    : Worker(name, education, beginYear, wage),
      department(department),
      subordinatesNumber(subordinatesNumber),
      bonus(bonus) {
    seniorCnt++;
    // cout << "������ ";show();
}

Director::Director(const string &name, const string &education, int beginYear, int wage, int departmentNumber,
                   int bonus)
    : Worker(name, education, beginYear, wage), departmentNumber(departmentNumber), bonus(bonus) {
    // cout << "������ ";show();
}

void Worker::show() {
    printf("��������� %s:\n    �����������: %s | ... ��� ����������� �� ������: %u | �����: %u\n",
           name.c_str(), education.c_str(), beginYear, wage);
}

void Intern::show() {
    printf(
        "������ %s:\n    �����������: %s | ��� ����������� �� ������: %u | �����: %u | ���������: %s | "
        "������������ �������������� �����: %u | ��������: %u\n\n",
        name.c_str(), education.c_str(), beginYear, wage, position.c_str(), trialDuration, bonus);
}

void Senior::show() {
    printf(
        "������������ %s:\n    �����������: %s | ��� ����������� �� ������: %u | �����: %u | �����: %s | "
        "���-�� �����������: %u | ��������: %u\n\n",
        name.c_str(), education.c_str(), beginYear, wage, department.c_str(), subordinatesNumber, bonus);
}

void Director::show() {
    printf(
        "�������� %s:\n    �����������: %s | ��� ����������� �� ������: %u | �����: %u | ���-�� �������: %u "
        "| ��������: %u\n\n",
        name.c_str(), education.c_str(), beginYear, wage, departmentNumber, bonus);
}

int Worker::set(const string &name, const string &education, int beginYear, int wage, int bonus) {
    if (name.size() > 99) {
        cout << "\033[31m"
             << "������: ������������ ������ ���� "
                "���"
                " - 99 ��������! ���������� �����!\n\n"
             << "\033[0m";
        return 1;
    } else if (education.size() > 66) {
        cout << "\033[31m"
             << "������: ������������ ������ ���� "
                "�����������"
                " - 66 ��������! ���������� �����!\n\n"
             << "\033[0m";
        return 2;
    } else if (beginYear < 2020) {
        cout << "\033[31m"
             << "������: ��� ����������� �� ������ �� ����� ���� ������ 2020! ���������� �����!\n\n"
             << "\033[0m";
        return 3;
    } else if (wage < 0 || bonus < 0) {
        cout << "\033[31m"
             << "������: ������ �������� ��� �������� �� ����� ���� �������������! ���������� �����!\n\n"
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
             << "������: ������������ ������ ���� "
                "���������"
                " - 66 ��������! ���������� �����!\n\n"
             << "\033[0m";
        return 2;
    } else if (trialDuration < 0) {
        cout << "\033[31m"
             << "������: ������������ �������������� ����� �� ����� ���� �������������! ���������� �����!\n\n"
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
             << "������: ������������ ������ ���� "
                "�����"
                " - 66 ��������! ���������� �����!\n\n"
             << "\033[0m";
        return 2;
    } else if (subordinatesNumber < 0) {
        cout << "\033[31m"
             << "������: ���������� ����������� �� ����� ���� �������������! ���������� �����!\n\n"
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
             << "������: ���������� ������� �� ����� ���� �������������! ���������� �����!\n\n"
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
        strRubles = "������";
    else if (sal % 10 == 2 || sal % 10 == 3 || sal % 10 == 4)
        strRubles = "�����";
    else if (sal % 10 == 1)
        strRubles = "�����";
    else
        strRubles = "������";

    return strRubles;
}

string Worker::getWorkExperience() {
    using namespace std;

    time_t t = time(nullptr);
    tm *const loctm = localtime(&t);
    unsigned years = 1900 + loctm->tm_year - beginYear;

    std::string strYears{};
    if (years % 100 >= 11 && years % 100 <= 20)
        strYears = "���";
    else if (years % 10 == 2 || years % 10 == 3 || years % 10 == 4)
        strYears = "����";
    else if (years % 10 == 1)
        strYears = "���";
    else
        strYears = "���";

    return std::to_string(years) + ' ' + strYears;
}

unsigned Worker::internCnt = 0;
unsigned Worker::seniorCnt = 0;

string Senior::getSubordinatesNumber() {
    string strInternCnt{};

    if (internCnt % 100 >= 11 && internCnt % 100 <= 20)
        strInternCnt = "��������";
    else if (internCnt % 10 == 2 || internCnt % 10 == 3 || internCnt % 10 == 4)
        strInternCnt = "�������";
    else if (internCnt % 10 == 1)
        strInternCnt = "������";
    else
        strInternCnt = "��������";

    return std::to_string(internCnt) + ' ' + strInternCnt;
}

string Director::getSubordinatesNumber() {
    string strSeniorCnt{};

    if (seniorCnt % 100 >= 11 && seniorCnt % 100 <= 20)
        strSeniorCnt = "�������������";
    else if (seniorCnt % 10 == 2 || seniorCnt % 10 == 3 || seniorCnt % 10 == 4)
        strSeniorCnt = "������������";
    else if (seniorCnt % 10 == 1)
        strSeniorCnt = "������������";
    else
        strSeniorCnt = "�������������";

    return std::to_string(seniorCnt) + ' ' + strSeniorCnt;
}

string Worker::getName() { return name; }