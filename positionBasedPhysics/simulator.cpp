#include "simulator.h"

simulator::simulator() {

}

simulator::~simulator() {
    delete[] t0;
    delete[] tP;
    delete[] t1;

    delete &t0;
    delete &tP;
    delete &t1;

    delete &particlePoolSize;

    delete &fullIterationsNumber;
    delete &projectionIterationsNumber;
    delete &relaxationIterationsNumber;
}

void simulator::simulate(worldstate* providedWorld, timeUnit deltaTime) {
    /*
    world = providedWorld;

    particlePoolSize = world->getParticlePoolSize();

    t0 = new particle [particlePoolSize];
    tP = new particle [particlePoolSize];
    t1 = new particle [particlePoolSize];

    for (int i = 0; i < particlePoolSize; i++) {
        t0[i] = *(world->getParticle(i));
        tP[i] = *(world->getParticle(i));
    }
    */

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

void simulator::Relax() {                       //writes results to t1

}

void simulator::integrate(timeUnit deltaTime) { //writes results to *(world->getParticle())

}
