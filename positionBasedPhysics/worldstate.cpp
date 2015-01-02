#include "worldstate.h"

worldstate::worldstate() {
    for (int index = 0; index < particlePoolSize; index++) {
        particlePoolFlag[index] = false;
    }

    for (int index = 0; index < softforcePoolSize; index++) {
        softforcePool[index] = nullptr;
    }

    for (int index = 0; index < constraintPoolSize; index++) {
        constraintPool[index] = nullptr;
    }
}

worldstate::~worldstate() {
    //delete the data referenced to by softForcePool and constraintPool as these arrays contain pointers
    //...

    delete[] &particlePool;
    delete[] &softforcePool;
    delete[] &constraintPool;

    delete &particlePoolSize;
    delete &softforcePoolSize;
    delete &constraintPoolSize;
}

particle* worldstate::getParticle(int index) {
    if (particlePoolFlag == false) {
        return nullptr;
    } else {
        return &(particlePool[index]);
    }
}

softforce* worldstate::getSoftforce(int index) {
    return softforcePool[index];
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
    for (int i = 0; i < softforcePoolSize; i++) {
        if (softforcePool[i]->getUsingParticle(index)) {
            removeSoftforce(i);
        }
    }

    //remove all constraints related to this particle;
    for (int i = 0; i < constraintPoolSize; i++) {
        if (constraintPool[i]->getUsingParticle(index)) {
            removeConstraint(i);
        }
    }

    if (index >= 0 && index < particlePoolSize) {
        particlePoolFlag[index] = false;
        particlePool[index].clear();
    }
}

void worldstate::removeSoftforce(int index) {
    if (index >= 0 && index < softforcePoolSize) {
        delete softforcePool[index];
        softforcePool[index] = nullptr;
    }
}

void worldstate::removeConstraint(int index) {
    if (index >= 0 && index < constraintPoolSize) {
        delete constraintPool[index];
        constraintPool[index] = nullptr;
    }
}

int worldstate::addParticle(particle newParticle) {
    for (int index = 0; index < particlePoolSize; index++) {
        if (particlePoolFlag[index] == false) {
            particlePool[index] = newParticle;
            particlePoolFlag[index] = true;
            return index;
        }
    }
    return -1;
}

bool worldstate::addSoftforce(softforce* newSoftforce) {
    for (int index; index < softforcePoolSize; index++) {
        if (softforcePool[index] == nullptr) {
            softforcePool[index] = newSoftforce;
            return true;
        }
    }
    return false;
}

bool worldstate::addConstraint(constraint* newConstraint) {
    for (int index; index < constraintPoolSize; index++) {
        if (constraintPool[index] == nullptr) {
            constraintPool[index] = newConstraint;
            return true;
        }
    }
    return false;
}
