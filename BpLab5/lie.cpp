#include <iostream>

#include "platypus.h"

using std::cout;
using std::endl;

int main() {
    //system("color F0");
    setlocale(LC_ALL, "Russian");

    CartPlat_D4 Plat1("B1_������ ��������", "B2_6.5", "B3_2", "D1_1.6", "D2_������", "D4_�����",
                      "D3_���������");

    cout << endl;
    Plat1.show();

    cout << endl;
    return 0;
}