#include "simulator.h"

simulator::simulator() {

}

simulator::~simulator() {

}

void simulator::simulate(worldstate* providedWorld, timeUnit deltaTime) {
    //std::cout << "simulate call\n";
    timeUnit tempTime = deltaTime / fullIterationsNumber;

    for (int i = 0; i < projectionIterationsNumber; i++) {
        virtualSimulate(providedWorld, tempTime);
    }
}

void simulator::virtualSimulate(worldstate* providedWorld, timeUnit deltaTime) {
    //std::cout << "virtual simulate call\ninitializing...\n";
    world = providedWorld;

    particlePoolSize = world->getParticlePoolSize();

    t0 = new particle [particlePoolSize];       //initial state
    tP = new particle [particlePoolSize];       //state after projection
    t1 = new particle [particlePoolSize];       //state after relaxation
    tBuffer = new particle [particlePoolSize];  //temporal buffer

    for (int i = 0; i < particlePoolSize; i++) {
        t0[i] = world->getParticle(i);
        tP[i] = t0[i];
    }

    //std::cout << "initialized!\nprojecting...\n";

    timeUnit tempTime = deltaTime / projectionIterationsNumber;
    for (int i = 0; i < projectionIterationsNumber; i++) {
        project(tempTime);
    }

    //std::cout << "projected!\npreparing buffers...\n";

    for (int i = 0; i < particlePoolSize; i++) {
        t1[i] = tP[i];
    }

    //std::cout << "relaxing constraints...\n";

    for (int i = 0; i < relaxationIterationsNumber; i++) {
        Relax();
    }

    //std::cout << "constraint relaxation completed!\nintegrating...\n";

    integrate(deltaTime);

    //std::cout << "integrating finished\n";

    for (int i = 0; i < particlePoolSize; i++) {
        world->setParticle(t1[i], i);
    }
    //std::cout << "finished";

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
        tP[i].clearAcceleration();
        tBuffer[i] = tP[i];
    }

    for (int i = 0; i < world->getSoftforcePoolSize(); i++) {
        if (world->getSoftforce(i) != nullptr) {
            world->getSoftforce(i)->applySoftforce(tBuffer, tP, particlePoolSize, deltaTime);
        }
    }

    for (int i = 0; i < particlePoolSize; i++) {
        tP[i].setPosition(tP[i].getPosition() + tP[i].getVelocity() * deltaTime + tP[i].getAcceleration() * 0.5 * deltaTime * deltaTime);
        tP[i].setVelocity(tP[i].getVelocity() + tP[i].getAcceleration() * deltaTime);
    }
}

void simulator::Relax() {                       //writes results to t1
    for (int i = 0; i < particlePoolSize; i++) {
        tBuffer[i] = t1[i];
    }

    for (int i = 0; i < world->getConstraintPoolSize(); i++) {
        if (world->getConstraint(i) != nullptr) {
            world->getConstraint(i)->resolveConstraint(tBuffer, t1, particlePoolSize);
        }
    }
}

void simulator::integrate(timeUnit deltaTime) { //writes results to t1
    for (int i = 0; i < particlePoolSize; i++) {
        if (world->isParticleActive(i)) {
            t1[i].setVelocity((t1[i].getPosition() - t0[i].getPosition()) * 2 / deltaTime - t0[i].getVelocity());
        }
    }
}
