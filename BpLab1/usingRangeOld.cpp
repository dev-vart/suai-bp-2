#include <iostream>
#include "rangeClass.h"

using std::cout;
using std::endl;

int inputcheck(double& leftInput, double& rightInput);

int inputcheck(double& valueToCheck);

int main() {
    Range userRange;
    double leftInput{}, rightInput{}, valueToCheck{};
    int exitCodeInputCheck1{};

    do {
        cout << "Enter left and right range values: ";
        exitCodeInputCheck1 = inputcheck(leftInput, rightInput);
        if (exitCodeInputCheck1 == 1) {
            cout << "Wrong input. Try again.\n";
            fflush(stdin);
            continue;
        }
        if (exitCodeInputCheck1 == 2) {
            cout << "Left value must be less than right one. Try again.\n";
            continue;
        }
    } while (exitCodeInputCheck1);

    userRange.setLeft(leftInput);
    userRange.setRight(rightInput);

    int exitCodeInputCheck2{};

    do {
        cout << "Enter a value to check: ";
        exitCodeInputCheck2 = inputcheck(valueToCheck);
        if (exitCodeInputCheck2 == 1) {
            cout << "Wrong input. Try again.\n";
            fflush(stdin);
            continue;
        }
    } while (exitCodeInputCheck2);

    cout << (userRange.rangecheck(valueToCheck) ? "The value is in range!" : "The value is not in range.") ;

    return 0;
}

int inputcheck(double& leftInput, double& rightInput)
{
    char nas{};
    if (scanf("%lf %lf%c", &leftInput, &rightInput, &nas) != 3 || nas != '\n') {
        return 1;
    }
    if (leftInput >= rightInput) {
        return 2; 
    }
    return 0;
}

int inputcheck(double& valueToCheck)
{
    char nas{};
    if (scanf("%lf%c", &valueToCheck, &nas) != 2 || nas != '\n') {
        return 1;
    }
    return 0;
}

