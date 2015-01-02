#include "worldstate.h"

worldstate::worldstate() {
    //ctor
}

worldstate::~worldstate() {
    //delete the data referenced to by softForcePool and constraintPool as these arrays contain pointers
    //...

    delete[] &particlePool;
    delete[] &softForcePool;
    delete[] &constraintPool;

    delete &particlePoolSize;
    delete &softForcePoolSize;
    delete &constraintPoolSize;
}

particle* worldstate::getParticle(int index) {
    if (particlePoolFlag == false) {
        return nullptr;
    } else {
        return &(particlePool[index]);
    }
}

softforce* worldstate::getSoftForce(int index) {
    return softForcePool[index];
}

constraint* worldstate::getConstraint(int index) {
    return constraintPool[index];
}

particle* worldstate::getParticlePool() {
    return &(particlePool[0]);
}

int worldstate::getParticlePoolSize() {
    return particlePoolSize;
}

void worldstate::removeParticle(int index) {
    //remove all soft forces related to this particle;
    for (int i = 0; i < softForcePoolSize; i++) {
        if (softForcePool[i].getUsingParticle(index)) {
            removeSoftForce(i);
        }
    }

    //remove all constraints related to this particle;
    for (int i = 0; i < constraintPoolSize; i++) {
        if (constraintPool[i].getUsingParticle(index)) {
            removeConstraint(i);
        }
    }

    if (index >= 0 && index < particlePoolSize) {
        particlePoolFlag[index] = false;
        particlePool[index].clear();
    }
}

void worldstate::removeSoftForce(int index) {
    if (index >= 0 && index < softForcePoolSize) {
        delete softForcePool[index];
        softForcePool[index] = nullptr;
    }
}

void worldstate::removeConstraint(int index) {
    if (index >= 0 && index < constraintPoolSize) {
        delete constraintPool[index];
        constraintPool[index] = nullptr;
    }
}
