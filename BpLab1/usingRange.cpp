#include <iostream>
#include <limits>
#include "rangeClass.h"

using std::cin;
using std::cout;
using std::endl;

int inputcheck(double& leftInput, double& rightInput);

int inputcheck(double& valueToCheck);

int main() 
{
    Range userRange;
    double leftInput{}, rightInput{}, valueToCheck{};
    int exitCodeInputCheck1{};

    do {
        cout << "Enter left and right range values: ";
        exitCodeInputCheck1 = inputcheck(leftInput, rightInput);

        if (exitCodeInputCheck1) {
            cout << "Wrong input. Try again!\n";
            continue;
        }

        userRange.setLeft(leftInput);
        userRange.setRight(rightInput);

        if (!userRange.validrange()) {
            exitCodeInputCheck1 = 1;
            continue;
        }

    } while (exitCodeInputCheck1);

    int exitCodeInputCheck2{};

    do {
        cout << "Enter a value to check: ";
        exitCodeInputCheck2 = inputcheck(valueToCheck);
        if (exitCodeInputCheck2) {
            cout << "Wrong input. Try again.\n";
            continue;
        }
    } while (exitCodeInputCheck2);
    cout << (userRange.rangecheck(valueToCheck) ? "The value is in range!" : "The value is not in range.") ;

    return 0;
}

int inputcheck(double& leftInput, double& rightInput)
{
    if (!(cin >> leftInput >> rightInput)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

int inputcheck(double& valueToCheck)
{
    if (!(cin >> valueToCheck)) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}
