#include "particlepool.h"

particlePool::particlePool(const int& initialParticlePoolSize) {
    if (initialParticlePoolSize > 0) {
        initialize(initialParticlePoolSize);
    }
}

particlePool::~particlePool() {
    delete[] myParticlePool;
    myParticlePool = nullptr;

    delete[] myParticlePoolFlag;
    myParticlePoolFlag = nullptr;
}

const particle particlePool::getParticle(const int& index) const {
    particle tempParticle;
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            tempParticle = myParticlePool[index];
        }
    }
    return tempParticle;
}

const vector particlePool::getPosition(const int& index) const {
    vector tempVector;
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            tempVector = myParticlePool[index].getPosition();
        }
    }
    return tempVector;
}

const vector particlePool::getVelocity(const int& index) const {
    vector tempVector;
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            tempVector = myParticlePool[index].getVelocity();
        }
    }
    return tempVector;
}

const vector particlePool::getAcceleration(const int& index) const {
    vector tempVector;
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            tempVector = myParticlePool[index].getAcceleration();
        }
    }
    return tempVector;
}

const float particlePool::getMass(const int& index) const {
    float tempFloat = -1;
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            tempFloat = myParticlePool[index].getMass();
        }
    }
    return tempFloat;
}

void particlePool::setParticle(const int& index, const particle& newParticle) {
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            myParticlePool[index] = newParticle;
        }
    }
}

void particlePool::setPosition(const int& index, const vector& newPosition) {
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            myParticlePool[index].setPosition(newPosition);
        }
    }
}

void particlePool::setVelocity(const int& index, const vector& newVelocity) {
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            myParticlePool[index].setVelocity(newVelocity);
        }
    }
}

void particlePool::setAcceleration(const int& index, const vector& newAcceleration) {
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            myParticlePool[index].setAcceleration(newAcceleration);
        }
    }
}

void particlePool::clearAcceleration() {
    for (int index = 0; index < particlePoolSize; index++) {
        myParticlePool[index].clearAcceleration();
    }
}

int particlePool::addParticle(const particle& newParticle) {
    int tempInt = -1;
    for (int index = 0; index < particlePoolSize; index++) {
        if (myParticlePoolFlag[index] == false) {
            myParticlePool[index] = newParticle;
            myParticlePoolFlag[index] = true;
            tempInt = index;
            break;
        }
    }
    return tempInt;
}

void particlePool::removeParticle(const int& index) {
    if (index >= 0 && index < particlePoolSize) {
        if (myParticlePoolFlag[index] == true) {
            myParticlePool[index].clear();
            myParticlePoolFlag[index] = false;
        }
    }
}

int particlePool::getParticlePoolSize() const {
    return particlePoolSize;
}

void particlePool::initialize(const int& newParticlePoolSize) {
    if (newParticlePoolSize < 1) {
        return;
    }

    clear();

    particlePoolSize = newParticlePoolSize;

    #if true    //this code will crash the program during assignments of particlePool objects (if *this is used)
    myParticlePool = new particle [particlePoolSize];
    myParticlePoolFlag = new bool [particlePoolSize];
    #endif
}

void particlePool::clear() {
    delete[] myParticlePool;
    myParticlePool = nullptr;

    delete[] myParticlePoolFlag;
    myParticlePoolFlag = nullptr;

    particlePoolSize = 0;
}

particlePool& particlePool::operator=(const particlePool& newValue) {
    if (this == &newValue) {
        return *this;
    }

    if (particlePoolSize != newValue.particlePoolSize) {
        initialize(newValue.particlePoolSize);
    }

/*  //iterate over all particles, not interesting as long as the arrays don't work
    for (int index = 0; index < particlePoolSize; index++) {
        myParticlePool[index] = newValue.myParticlePool[index];
        myParticlePoolFlag[index] = newValue.myParticlePoolFlag[index];
    }
*/

    *this;
}
