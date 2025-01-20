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

        cout << "------- ���� -------"
             << endl;
        cout << "1. �������� ���������"
             << endl;
        cout << "2. �������� ���������"
             << endl;
        cout << "...������� -1 ��� ������"
             << endl
             << endl;
        cout << "������� ����� ����: " << endl;

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
            cout << "--- �������� ��������� ---" << endl;
            // menuShow();
            break;
        case -1:
            system("cls");
            cout << "--- ����! ---" << endl;
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

        cout << "--- �������� ��������� ---" << endl;
        cout << "1. �������� �������" << endl;
        cout << "2. �������� ������������" << endl;
        cout << "3. �������� ���������" << endl;
        cout << "...������� -1 ��� ������ � �������� ����" << endl;

        if (!validIntInput(menuItem))
        {
            showError(menuItem);
            continue;
        }

        switch (menuItem)
        {
        case 1:
            system("cls");
            cout << "���������: ���_�����������_��������������_�����_���������_������������������������������_��������" << endl
                 << endl;
            cout << "������� ������ �������(��� ���������� ����������� ������): " << endl;
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
            cout << "������� ������ ������������:" << endl;
            break;
        case 3:
            system("cls");
            cout << "������� ������ ���������:" << endl;
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
        cout << "\033[31m" << "������: ��� �� �������� ������� ����! ���������� ��� ���" << "\033[0m" << endl
             << endl;
    else
        cout << "\033[31m" << "������: " << menuItem << " �� �������� ������� ����! ���������� ��� ���" << "\033[0m" << endl
             << endl;
}