#include <iostream>
#include <limits>
#include "WorkerClass.h"

using std::cin;
using std::cout;
using std::endl;

int menuAdd();

bool validIntInput(int &val);

void showError(int &menuItem);

Intern I1;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("cls");

    // Senior S1;
    // Director D1;

    while (true)
    {
        int menuItem{};

        cout << "------- МЕНЮ -------"
             << endl;
        cout << "1. Добавить работника"
             << endl;
        cout << "2. Показать работника"
             << endl;
        cout << "...введите -1 для выхода"
             << endl
             << endl;
        cout << "Введите пункт меню: " << endl;

        if (!validIntInput(menuItem))
        {
            showError(menuItem);
            continue;
        }

        switch (menuItem)
        {
        case 1:
            menuAdd();
            break;
        case 2:
            system("cls");
            cout << "--- ПОКАЗАТЬ РАБОТНИКА ---" << endl;
            // menuShow();
            break;
        case -1:
            system("cls");
            cout << "--- Пока! ---" << endl;
            return 0;
            break;
        default:
            showError(menuItem);
            break;
        }
    }

    return 0;
}

int menuAdd()
{
    system("cls");

    char nas{};
    char Cname[101], Ceducation[68], Cposition[68];
    string name{}, education{}, position{};
    int beginYear{}, wage{}, trialDuration{}, bonus{};

    while (true)
    {
        int menuItem{};

        cout << "--- ДОБАВИТЬ РАБОТНИКА ---" << endl;
        cout << "1. Добавить Стажера" << endl;
        cout << "2. Добавить Руководителя" << endl;
        cout << "3. Добавить Директора" << endl;
        cout << "...введите -1 для выхода в основное меню" << endl;

        if (!validIntInput(menuItem))
        {
            showError(menuItem);
            continue;
        }

        switch (menuItem)
        {
        case 1:
            system("cls");
            cout << "Подсказка: Имя_Образование_ГодПоступления_Оклад_Должность_ДлительностьИспытательныйСрока_Надбавка" << endl
                 << endl;
            cout << "Введите данные стажера(для разделения используйте пробел): " << endl;
            scanf("%100s %67s %d %d %67s %d %d%c", Cname, Ceducation, &beginYear, &wage, Cposition, &trialDuration, &bonus, &nas);
            name = Cname;
            education = Ceducation;
            position = Cposition;
            I1.show();
//            printf("|||%s %s %d %d %s %d | %d|||", Cname, Ceducation, beginYear, wage, Cposition, trialDuration, bonus);
            printf("|||%s|||", Cname);

            I1.set(name, education, beginYear, wage, position, trialDuration, bonus);
            I1.show();
            break;
        case 2:
            system("cls");
            cout << "Введите данные руководителя:" << endl;
            break;
        case 3:
            system("cls");
            cout << "Введите данные директора:" << endl;
            break;
        case -1:
            system("cls");
            return 0;
            break;
        default:
            showError(menuItem);
            break;
        }
    }
}

bool validIntInput(int &val)
{
    if (!(cin >> val))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return true;
}

void showError(int &menuItem)
{
    system("cls");
    if (menuItem == 0)
        cout << "\033[31m" << "Ошибка: Это не является пунктом меню! Попробуйте ещё раз" << "\033[0m" << endl
             << endl;
    else
        cout << "\033[31m" << "Ошибка: " << menuItem << " не является пунктом меню! Попробуйте ещё раз" << "\033[0m" << endl
             << endl;
}