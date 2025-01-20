#include <iostream>
#include "timeClass.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << endl;
    Time TimeCreate;
    cout << endl;

    Time TimeInit(14, 59, 36);
    cout << endl;

    Time TimeCopy = TimeInit;

    cout << "\n----------- Adding to time -----------\n";    
    int minToAdd = 1345;
    TimeInit.show();
    cout << "                +     " << endl;
    cout << "               " << minToAdd << "     " << endl;
    cout << "                =     " << endl;
    TimeInit += minToAdd;
    TimeInit.show();

    cout << "\n----------- Subtracting one time from another -----------\n";    
    Time TimeMinus;
    TimeMinus = TimeCopy - TimeInit;
    TimeCopy.show();
    cout << "                -     " << endl;
    TimeInit.show();
    cout << "                =     " << endl;
    TimeMinus.show();

    cout << "\n----------- Checking for mistakes -----------\n";    
    Time TimeInitWrong(90, 23, 11);

    cout << "\n----------- Equality check -----------\n";
    TimeMinus.show();
    TimeCopy.show();
    cout  << "Are equal? " << ((TimeMinus == TimeCopy) ? "Times are equal" : "Times are different") << endl;
    cout << "Are different? " << ((TimeMinus != TimeCopy) ? "Times are different" : "Times are equal") << endl;

    cout << "\n----------- Destructors -----------\n"; 

    return 0;
}

