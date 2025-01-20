#include <iostream>

#include "platypus.h"

using std::cout;
using std::endl;

int main() {
    //system("color F0");
    setlocale(LC_ALL, "Russian");

    CartPlat_D4 Plat1("B1_остров Тасмания", "B2_6.5", "B3_2", "D1_1.6", "D2_сериал", "D4_Перри",
                      "D3_Австралия");

    cout << endl;
    Plat1.show();

    cout << endl;
    return 0;
}