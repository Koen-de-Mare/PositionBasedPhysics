#include <iostream>

#include "worldstate.h"
#include "simulator.h"
#include "particles/particle.h"
#include "particles/particlePool.h"
#include "vector/vector2d.h"
#include "constraints/distanceconstraint.h"
#include "constraints/positionconstraint.h"
#include "constraints/constraint.h"

using namespace std;

using vector = vector2D;

int main() {
    cout << "Hello, world!" << endl << endl;

    worldstate* myWorldState = new worldstate();
    simulator* mySimulator = new simulator();

    int particle1, particle2;

    vector tempVector (1, 0);

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

    cout << endl << "initial state:" << endl;

    cout << "particle1.X = " << myWorldState->getParticle(particle1).getPosition().getX() << endl;
    cout << "particle1.vX = " << myWorldState->getParticle(particle1).getVelocity().getX() << endl;
    cout << "particle1.aX = " << myWorldState->getParticle(particle1).getAcceleration().getX() << endl;
    cout << endl;
    cout << "particle2.X = " << myWorldState->getParticle(particle2).getPosition().getX() << endl;
    cout << "particle2.vX = " << myWorldState->getParticle(particle2).getVelocity().getX() << endl;
    cout << "particle2.aX = " << myWorldState->getParticle(particle2).getAcceleration().getX() << endl;

    mySimulator->setFullIterationsNumber(1);

    for (int i = 0; i < 10; i++) {
        cout << endl << endl << "New iteration!" << endl;
        mySimulator->simulate(myWorldState, 0.2);
        cout << endl;
        cout << "particle1.X = " << myWorldState->getParticle(particle1).getPosition().getX() << endl;
        cout << "particle1.vX = " << myWorldState->getParticle(particle1).getVelocity().getX() << endl;
        cout << "particle1.aX = " << myWorldState->getParticle(particle1).getAcceleration().getX() << endl;
        cout << endl;
        cout << "particle2.X = " << myWorldState->getParticle(particle2).getPosition().getX() << endl;
        cout << "particle2.vX = " << myWorldState->getParticle(particle2).getVelocity().getX() << endl;
        cout << "particle2.aX = " << myWorldState->getParticle(particle2).getAcceleration().getX() << endl;
    }

    delete myWorldState;
    myWorldState = nullptr;

    delete mySimulator;
    mySimulator = nullptr;

    cout << endl << "finished!" << endl;

    return 0;
}
