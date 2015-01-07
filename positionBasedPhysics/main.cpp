#include <iostream>

#include "worldstate.h"
#include "simulator.h"
#include "particle.h"
#include "vector/vector2d.h"

using namespace std;

/*
http://www.devx.com/getHelpOn/10MinuteSolution/17298/0/page/3
*/

int main() {
    cout << "Hello, world!" << endl;

    worldstate* myWorldState = new worldstate();
    simulator* mySimulator = new simulator();

    vector2D tempVector (1, 0);
    particle tempParticle;

    tempParticle.setVelocity(tempVector);
    cout << tempParticle.getVelocity().getX() << endl;

    int tempInt = myWorldState->addParticle(tempParticle);
    cout << tempInt << endl;

    mySimulator->simulate(myWorldState, 1);

    cout << endl << myWorldState->getParticle(tempInt).getPosition().getX() << endl;

    delete myWorldState;
    myWorldState = nullptr;

    delete mySimulator;
    mySimulator = nullptr;

    cout << endl << "finished!" << endl;

    return 0;
}
