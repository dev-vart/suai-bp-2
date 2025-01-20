#ifndef WORKER_CLASS_H
#define WORKER_CLASS_H

#include <string>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Worker {
   protected:
    string name{};
    string education{};
    unsigned beginYear{};
    unsigned wage{};
    static unsigned internCnt;
    static unsigned seniorCnt;

   public:
    explicit Worker(const string &name = "N/A", const string &education = "N/A", int beginYear = 2020,
                    int wage = 0);
    virtual void show();
    int set(const string &name, const string &education, int beginYear, int wage, int bonus);
    virtual int getSalary();
    string getRublesRight();
    string getWorkExperience();
    string getName();
};

class Intern : public Worker {
    string position{};
    unsigned trialDuration{};
    unsigned bonus{};

   public:
    explicit Intern(const string &name = "N/A", const string &education = "N/A", int beginYear = 2020,
                    int wage = 0, const string &position = "N/A", int trialDuration = 0, int bonus = 0);
    void show() override;
    int set(const string &name = "N/A", const string &education = "N/A", int beginYear = 2020,
            int wage = 20000, const string &position = "N/A", int trialDuration = 1, int bonus = 2000);
    int getSalary() override;
};

class Senior : public Worker {
    string department{};
    unsigned subordinatesNumber{};
    unsigned bonus{};

   public:
    explicit Senior(const string &name = "N/A", const string &education = "N/A", int beginYear = 2020,
                    int wage = 0, const string &department = "N/A", int subordinatesNumber = 0,
                    int bonus = 0);
    void show() override;
    int set(const string &name = "N/A", const string &education = "N/A", int beginYear = 2020,
            int wage = 50000, const string &department = "N/A", int subordinatesNumber = 5,
            int bonus = 15000);
    int getSalary() override;
    string getSubordinatesNumber();
};

class Director : public Worker {
    unsigned departmentNumber{};
    unsigned bonus{};

   public:
    explicit Director(const string &name = "N/A", const string &education = "N/A", int beginYear = 2020,
                      int wage = 0, int departmentNumber = 0, int bonus = 0);
    void show() override;
    int set(const string &name = "N/A", const string &education = "N/A", int beginYear = 2020,
            int wage = 100000, int departmentNumber = 1, int bonus = 30000);
    int getSalary() override;
    string getSubordinatesNumber();
};

#endif