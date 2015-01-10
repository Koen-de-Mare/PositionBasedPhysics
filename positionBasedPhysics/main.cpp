#include <iostream>

#include "worldstate.h"
#include "simulator.h"
#include "particle.h"
#include "vector/vector2d.h"
#include "constraints/distanceconstraint.h"
#include "constraints/positionconstraint.h"
#include "constraints/constraint.h"

using namespace std;

/*
http://www.devx.com/getHelpOn/10MinuteSolution/17298/0/page/3
*/

int main() {
    cout << "Hello, world!" << endl << endl;

    worldstate* myWorldState = new worldstate();
    simulator* mySimulator = new simulator();

    int particle1, particle2;

    vector2D tempVector (1, 0);

    particle tempParticle;
    tempParticle.setVelocity(tempVector);   //1,0
    tempParticle.setPosition(tempVector);   //1,0
    particle1 = myWorldState->addParticle(tempParticle);
    tempVector.clear();

    tempParticle.setPosition(tempVector);   //0, 0
    tempParticle.setVelocity(tempVector);   //0, 0
    particle2 = myWorldState->addParticle(tempParticle);

    constraint* myConstraint;
    myConstraint = new distanceconstraint(particle1, particle2, 1, 1);

    int tempInt = myWorldState->addConstraint(myConstraint);
    if (tempInt != -1) {
        cout << "myConstraint succesfully initialized!" << endl;
    } else {
        cout << "myConstraint could not be initialized!!!" << endl;
    }

    myConstraint = nullptr;

    cout << endl;
    cout << "particle1.X = " << myWorldState->getParticle(particle1).getPosition().getX() << endl;
    cout << "particle2.X = " << myWorldState->getParticle(particle2).getPosition().getX() << endl;

    mySimulator->setFullIterationsNumber(1);

    for (int i = 0; i < 10; i++) {
        cout << endl << "new iteration!" << endl;
        mySimulator->simulate(myWorldState, 0.2);
        cout << endl;
        cout << "particle1.X = " << myWorldState->getParticle(particle1).getPosition().getX() << endl;
        cout << "particle2.X = " << myWorldState->getParticle(particle2).getPosition().getX() << endl;
    }

    delete myWorldState;
    myWorldState = nullptr;

    delete mySimulator;
    mySimulator = nullptr;

    cout << endl << "finished!" << endl;

    return 0;
}
