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

    //testing code for the new particlePool class (assignment in particular)

    particlePool t0;
    particlePool t1;
    particlePool t2;

    t0.initialize(20);
    cout << t0.getParticlePoolSize() << endl;

    //cout << (t2 = t0).getParticlePoolSize() << endl;  //crashes the program if particlePool creates arrays during assignment
    t2 = t1 = t1                                      //same as line above
    //t2 = t0;    //no problem here, even if particlePool creates arrays during assignment

    cout << t2.getParticlePoolSize() << endl;



    /*
    cout << "Hello, world!" << endl << endl;

    worldstate* myWorldstate = new worldstate();
    simulator* mySimulator = new simulator();

    {
    particlePool tempParticlePool;
    tempParticlePool = myWorldstate->getParticlePool();
    tempParticlePool.initialize(20);
    myWorldstate->setParticlePool(tempParticlePool);
    }

    int particle1, particle2;

    vector tempVector (1, 0);

    particle tempParticle;
    tempParticle.setVelocity(tempVector);   //1,0
    tempParticle.setPosition(tempVector);   //1,0
    particle1 = myWorldstate->addParticle(tempParticle);
    tempVector.clear();

    tempParticle.setPosition(tempVector);   //0, 0
    tempParticle.setVelocity(tempVector);   //0, 0
    particle2 = myWorldstate->addParticle(tempParticle);

    cout << endl;
    cout << "particle1 = " << particle1 << endl;
    cout << "particle2 = " << particle2 << endl;
    cout << endl;

    constraint* myConstraint;
    myConstraint = new distanceconstraint(particle1, particle2, 1, 1);

    int tempInt = myWorldstate->addConstraint(myConstraint);
    if (tempInt != -1) {
        cout << "myConstraint succesfully initialized!" << endl;
    } else {
        cout << "myConstraint could not be initialized!!!" << endl;
    }

    myConstraint = nullptr;

    cout << endl << "initial state:" << endl;

    cout << "particle1.X = " << myWorldstate->getParticle(particle1).getPosition().getX() << endl;
    cout << "particle1.vX = " << myWorldstate->getParticle(particle1).getVelocity().getX() << endl;
    cout << "particle1.aX = " << myWorldstate->getParticle(particle1).getAcceleration().getX() << endl;
    cout << endl;
    cout << "particle2.X = " << myWorldstate->getParticle(particle2).getPosition().getX() << endl;
    cout << "particle2.vX = " << myWorldstate->getParticle(particle2).getVelocity().getX() << endl;
    cout << "particle2.aX = " << myWorldstate->getParticle(particle2).getAcceleration().getX() << endl;

    mySimulator->setFullIterationsNumber(1);

    for (int i = 0; i < 10; i++) {
        cout << endl << endl << "New iteration!" << endl;
        mySimulator->simulate(myWorldstate, 0.2);
        cout << endl;
        cout << "particle1.X = " << myWorldstate->getParticle(particle1).getPosition().getX() << endl;
        cout << "particle1.vX = " << myWorldstate->getParticle(particle1).getVelocity().getX() << endl;
        cout << "particle1.aX = " << myWorldstate->getParticle(particle1).getAcceleration().getX() << endl;
        cout << endl;
        cout << "particle2.X = " << myWorldstate->getParticle(particle2).getPosition().getX() << endl;
        cout << "particle2.vX = " << myWorldstate->getParticle(particle2).getVelocity().getX() << endl;
        cout << "particle2.aX = " << myWorldstate->getParticle(particle2).getAcceleration().getX() << endl;
    }

    delete myWorldstate;
    myWorldstate = nullptr;

    delete mySimulator;
    mySimulator = nullptr;

    cout << endl << "finished!" << endl;
    */
    return 0;
}
