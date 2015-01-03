#include <iostream>

#include "worldstate.h"

using namespace std;

int main() {
    cout << "Hello, world!" << endl;

    worldstate myWorldState;
    delete &myWorldState;

    return 0;
}
