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
    for (int i = 0; i < softforcePoolSize; i++) {
        delete softforcePool[i];
    }

    for (int i = 0; i < constraintPoolSize; i++) {
        delete constraintPool[i];
    }
}

particle worldstate::getParticle(const int& index) {
    if (index >= 0 && index < pariclePoolSize) {
        return particlePool[index];
    } else {
        //the index was invalid
        return new particle;
    }
}

softforce* worldstate::getSoftforce(const int& index) {
    if (index >= 0 && index < softforcePoolSize) {
        return softforcePool[index];
    } else {
        //the index was invalid
        return nullptr;
    }
}

constraint* worldstate::getConstraint(const int& index) {
    if (index >= 0 && index < constraintPoolSize) {
        return constrainPool[index];
    } else {
        //the index was invalid
        return nullptr;
    }
}

void worldstate::setParticle(const particle& newParticle, const int& index) {
    particlePool[index] = newParticle;
}

int worldstate::addParticle(const particle& newParticle) {
    for (int index = 0; index < particlePoolSize; index++) {
        if (particlePoolFlag[index] == false) {
            particlePool[index] = newParticle;
            particlePoolFlag[index] = true;
            return index;
        }
    }
    return -1;
}

int worldstate::addSoftforce(softforce* const newSoftforce) {
    for (int i = 0; i < softforcePoolSize; i++) {
        if (softforcePool[i] == nullptr) {
            softforcePool[i] = newSoftforce;
            return i;
        }
    }
    return -1;
}

int worldstate::addConstraint(constraint* const newConstraint) {
    std::cout << "adding constraint...\n";
    for (int i = 0; i < constraintPoolSize; i++) {
        if (constraintPool[i] == nullptr) {
            constraintPool[i] = newConstraint;
            return i;
        }
    }
    return -1;
}

void worldstate::removeParticle(const int& index) {
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

void worldstate::removeSoftforce(const int& index) {
    if (index >= 0 && index < softforcePoolSize) {
        delete softforcePool[index];
        softforcePool[index] = nullptr;
    }
}

void worldstate::removeConstraint(const int& index) {
    if (index >= 0 && index < constraintPoolSize) {
        delete constraintPool[index];
        constraintPool[index] = nullptr;
    }
}

particle* worldstate::getParticlePool() {
    return particlePool;
}

int worldstate::getParticlePoolSize() const {
    return particlePoolSize;
}

int worldstate::getSoftforcePoolSize() const {
    return softforcePoolSize;
}

int worldstate::getConstraintPoolSize() const {
    return constraintPoolSize;
}

bool worldstate::isParticleActive(const int& index) const {
    if (index >= 0 && index < particlePoolSize) {
        return particlePoolFlag[index];
    } else {
        return false;
    }
}

void worldstate::operator=(const worldstate& newValue) {

}
