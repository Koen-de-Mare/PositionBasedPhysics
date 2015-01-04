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
    t1 = new particle [particlePoolSize];       //final state

    for (int i = 0; i < particlePoolSize; i++) {
        t0[i] = *(world->getParticle(i));
        tP[i] = *(world->getParticle(i));
    }

    timeUnit tempTime = deltaTime / projectionIterationsNumber;

    for (int i = 0; i < projectionIterationsNumber; i++) {
        project(tempTime);
    }

    for (int i = 0; i < relaxationIterationsNumber; i++) {
        Relax();
    }

    integrate(deltaTime);

    delete[] t0;
    delete[] tP;
    delete[] t1;

    t0 = nullptr;
    tP = nullptr;
    t1 = nullptr;
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
        relaxationIterationsNumber = 0;
    }
}

void simulator::project(timeUnit deltaTime) {   //writes results to tP

}

void simulator::Relax() {                       //writes results to t1 or *(world->getParticle())

}

void simulator::integrate(timeUnit deltaTime) { //writes results to *(world->getParticle())

}
