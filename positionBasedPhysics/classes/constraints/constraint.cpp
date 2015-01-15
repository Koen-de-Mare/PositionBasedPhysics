#include "constraint.h"

constraint::constraint() {

}

constraint::~constraint() {

}

void constraint::resolveConstraint(particle* const newInBuffer, particle* newOutBuffer, const int& newParticlePoolSize) {
    inBuffer = newInBuffer;
    outBuffer = newOutBuffer;
    particlePoolSize = newParticlePoolSize;

    virtualResolveConstraint();

    inBuffer = nullptr;
    outBuffer = nullptr;
    particlePoolSize = 0;
}

vector constraint::getPosition(const int& particleIndex) const {
    vector tempVector;
    if (particleIndex >= 0 && particleIndex < particlePoolSize) {
        tempVector = inBuffer[particleIndex].getPosition();
    }
    return tempVector;
}

unit constraint::getDistance(const int& particleIndex1, const int& particleIndex2) const {
    unit tempUnit = -1;
    if (particleIndex1 >= 0 && particleIndex1 < particlePoolSize && particleIndex2 >= 0 && particleIndex2 < particlePoolSize) {
        tempUnit = (getPosition(particleIndex1) - getPosition(particleIndex2)).getLength();
    }
    return tempUnit;
}

const particle constraint::getParticle(const int& particleIndex) const {
    return inBuffer[particleIndex];
}

int constraint::getParticlePoolSize() const {
    return particlePoolSize;
}


void constraint::displace(const int& particleIndex, const vector& displacement) {
    if (particleIndex >= 0 && particleIndex < particlePoolSize) {
        if (getParticle(particleIndex).getMass() != INFINITY) {
            outBuffer[particleIndex].setPosition(outBuffer[particleIndex].getPosition() + displacement);
        }
    }
}

void constraint::setPosition(const int& particleIndex, const vector& newPosition) {
    if (particleIndex >= 0 && particleIndex < particlePoolSize) {
        displace(particleIndex, newPosition - inBuffer[particleIndex].getPosition());
    }
}
