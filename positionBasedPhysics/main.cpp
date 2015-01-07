#include <iostream>

#include "classes/worldstate.h"
#include "classes/simulator.h"

using namespace std;

/*
http://www.devx.com/getHelpOn/10MinuteSolution/17298/0/page/3
*/

int main() {
    cout << "Hello, world!" << endl;

    worldstate* myWorldState = new worldstate();
    simulator* mySimulator = new simulator();

    delete myWorldState;
    myWorldState = nullptr;

    delete mySimulator;
    mySimulator = nullptr;

    cout << endl << "finished!" << endl;

    return 0;
}
