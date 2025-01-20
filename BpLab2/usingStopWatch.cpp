#include <iostream>
#include <limits>
#include <chrono>
#include "stopWatchClass.h"

using std::cin;
using std::cout;
using std::endl;

int main() {

    stopwatch swd;
    swd.start();
    swd.delay(2000);
    swd.stop();
    swd.show();
    cout << endl;

    stopwatch swi(std::chrono::system_clock::now(), std::chrono::duration<double>::zero());
    swi.show();
    swi.start();
    swi.delay(1500);
    swi.stop();
    swi.show();
    cout << endl;


    stopwatch swc = swi;
    swi.show();
    swi.start();
    swc.delay(2100);
    swc.stop();
    swc.show();
    cout << endl;

    return 0;
}

