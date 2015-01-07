#include "simulator.h"

simulator::simulator() {

}

simulator::~simulator() {

}

void simulator::simulate(worldstate* providedWorld, timeUnit deltaTime) {
    timeUnit tempTime = deltaTime / fullIterationsNumber;

    for (int i = 0; i < projectionIterationsNumber; i++) {
        virtualSimulate(providedWorld, tempTime);
    }
}

void simulator::virtualSimulate(worldstate* providedWorld, timeUnit deltaTime) {
    world = providedWorld;

    particlePoolSize = world->getParticlePoolSize();

    t0 = new particle [particlePoolSize];       //initial state
    tP = new particle [particlePoolSize];       //state after projection
    t1 = new particle [particlePoolSize];       //state after relaxation
    tBuffer = new particle [particlePoolSize];  //temporal buffer

    for (int i = 0; i < particlePoolSize; i++) {
        t0[i] = *(world->getParticle(i));
        tP[i] = t0[i];
    }

    timeUnit tempTime = deltaTime / projectionIterationsNumber;
    for (int i = 0; i < projectionIterationsNumber; i++) {
        project(tempTime);
    }

    for (int i = 0; i < particlePoolSize; i++) {
        t1[i] = tP[i];
    }

    for (int i = 0; i < relaxationIterationsNumber; i++) {
        Relax();
    }

    integrate(deltaTime);

    for (int i = 0; i < particlePoolSize; i++) {
        *(world->getParticle(i)) = t1[i];
    }

    delete[] t0;
    delete[] tP;
    delete[] t1;
    delete[] tBuffer;

    t0 = nullptr;
    tP = nullptr;
    t1 = nullptr;
    tBuffer = nullptr;

    world = nullptr;
}

void simulator::setFullIterationsNumber(int newFullIterationsNumber) {
    if (newFullIterationsNumber > 0) {
        fullIterationsNumber = newFullIterationsNumber;
    } else {
        fullIterationsNumber = 1;
    }
}

void simulator::setProjectionIterationsNumber(int newProjectionIterationsNumber) {
    if (newProjectionIterationsNumber > 0) {
        projectionIterationsNumber = newProjectionIterationsNumber;
    } else {
        projectionIterationsNumber = 1;
    }
}

void simulator::setRelaxationIterationsNumber(int newRelaxationIterationsNumber) {
    if (newRelaxationIterationsNumber > 0) {
        relaxationIterationsNumber = newRelaxationIterationsNumber;
    } else {
        relaxationIterationsNumber = 1;
    }
}

void simulator::project(timeUnit deltaTime) {   //writes results to tP
    for (int i = 0; i < particlePoolSize; i++) {
        tBuffer[i] = tP[i];
    }

    for (int i = 0; i < world->getSoftforcePoolSize(); i++) {
        world->getSoftforce(i)->applySoftforce(tBuffer, tP, particlePoolSize, deltaTime);
    }
}

void simulator::Relax() {                       //writes results to t1
    for (int i = 0; i < particlePoolSize; i++) {
        tBuffer[i] = t1[i];
    }

    for (int i = 0; i < world->getConstraintPoolSize(); i++) {
        world->getConstraint(i)->resolveConstraint(tBuffer, t1, particlePoolSize);
    }
}

void simulator::integrate(timeUnit deltaTime) { //writes results to t1
    for (int i = 0; i < particlePoolSize; i++) {
        if (world->isParticleActive(i)) {

        }
    }
}
