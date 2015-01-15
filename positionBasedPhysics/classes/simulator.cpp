#include "simulator.h"

simulator::simulator() {

}

simulator::~simulator() {

}

void simulator::simulate(worldstate* providedWorld, timeUnit deltaTime) {
    if (deltaTime <= 0) {
        std::cout << "ERROR! the deltaTime provided for the simulator is invalid!" << std::endl;
        return;
    }
    //std::cout << "simulate call\n";
    timeUnit tempTime = deltaTime / fullIterationsNumber;

    for (int i = 0; i < projectionIterationsNumber; i++) {
        virtualSimulate(providedWorld, tempTime);
    }
}

void simulator::virtualSimulate(worldstate* providedWorld, timeUnit deltaTime) {
    //std::cout << "virtual simulate call\ninitializing...\n";
    world = providedWorld;

    tP = t0 = world->getParticlePool();

    //std::cout << "initialized!\nprojecting...\n";

    timeUnit tempTime = deltaTime / projectionIterationsNumber;
    for (int i = 0; i < projectionIterationsNumber; i++) {
        project(tempTime);
    }

    //std::cout << "projected!\npreparing buffers...\n";

    t1 = tP;

    //std::cout << "relaxing constraints...\n";

    for (int i = 0; i < relaxationIterationsNumber; i++) {
        Relax();
    }

    //std::cout << "constraint relaxation completed!\nintegrating...\n";

    integrate(deltaTime);

    //std::cout << "integrating finished\n";

    world->setParticlePool(t1);

    //std::cout << "finished";

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

void simulator::project(timeUnit deltaTime) {       //writes results to tP
    tP.clearAcceleration();
    tBuffer = tP;

    //put this loop in worldState!
    for (int i = 0; i < world->getSoftforcePoolSize(); i++) {
        if (world->getSoftforce(i) != nullptr) {
            world->getSoftforce(i)->applySoftforce(&tBuffer, &tP);
        }
    }

    //put this loop somewhere else too
    for (int index = 0; index < world->getParticlePoolSize(); index++) {
        //tP[index].setPosition(tP[index].getPosition() + tP[index].getVelocity() * deltaTime + tP[index].getAcceleration() * 0.5 * deltaTime * deltaTime);
        //tP[index].setVelocity(tP[index].getVelocity() + tP[index].getAcceleration() * deltaTime);
    }
}

void simulator::Relax() {                           //writes results to t1
    tBuffer = t1;

    for (int i = 0; i < world->getConstraintPoolSize(); i++) {
        if (world->getConstraint(i) != nullptr) {
            world->getConstraint(i)->resolveConstraint(&tBuffer, &t1);
        }
    }
}

void simulator::integrate(timeUnit deltaTime) {     //writes results to t1
    for (int index = 0; index < particlePoolSize; index++) {
        if (world->isParticleActive(index)) {
            #if false
            t1[index].setVelocity((t1[index].getPosition() - t0[index].getPosition()) / deltaTime);
            #else
            t1[index].setVelocity((t1[index].getPosition() - t0[index].getPosition()) / deltaTime * 2 - t0[index].getVelocity());
            t1[index].setAcceleration((t1[index].getVelocity() - t0[index].getVelocity()) / deltaTime);
            #endif
        }
    }
}
