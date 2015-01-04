#include <iostream>

#include "worldstate.h"

using namespace std;

/*
http://www.devx.com/getHelpOn/10MinuteSolution/17298/0/page/3
*/

int main() {
    cout << "Hello, world!" << endl;

    worldstate* myWorldState = new worldstate();
    delete myWorldState;
    myWorldState = nullptr;

    cout << endl << "finished!";

    return 0;
}
