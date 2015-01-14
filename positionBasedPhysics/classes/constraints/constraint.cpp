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
    if (particleIndex >= 0 && particleIndex < particlePoolSize) {
        return inBuffer[particleIndex].getPosition();
    } else {
        //the particleIndex supplied was invalid!
        vector tempVector;
        return tempVector;
    }
}

unit constraint::getDistance(const int& particleIndex1, const int& particleIndex2) const {
    if (particleIndex1 >= 0 && particleIndex1 < particlePoolSize && particleIndex2 >= 0 && particleIndex2 < particlePoolSize) {
        return (getPosition(particleIndex1) - getPosition(particleIndex2)).getLength();
    } else {
        //one of the particleIndices supplied was invalid
        return 0;
    }
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
