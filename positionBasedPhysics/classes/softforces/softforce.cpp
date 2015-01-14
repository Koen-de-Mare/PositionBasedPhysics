#include "softforce.h"

softforce::softforce() {

}

softforce::~softforce() {

}

void softforce::applySoftforce(particle* const newInBuffer, particle* newOutBuffer, const int& newParticlePoolSize) {
    inBuffer = newInBuffer;
    outBuffer = newOutBuffer;
    particlePoolSize = newParticlePoolSize;

    virtualApplySoftforce();

    inBuffer = nullptr;
    outBuffer = nullptr;
    particlePoolSize = 0;
}

vector softforce::getPosition(const int& particleIndex) const {
    if (particleIndex >= 0 && particleIndex < particlePoolSize) {
        return inBuffer[particleIndex].getPosition();
    } else {
        //the particleIndex supplied was invalid!
        vector tempVector;
        return tempVector;
    }
}

unit softforce::getDistance(const int& particleIndex1, const int& particleIndex2) const {
    if (particleIndex1 >= 0 && particleIndex1 < particlePoolSize && particleIndex2 >= 0 && particleIndex2 < particlePoolSize) {
        return (getPosition(particleIndex1) - getPosition(particleIndex2)).getLength();
    } else {
        //one of the particleIndices supplied was invalid
        return 0;
    }
}

const particle softforce::getParticle(const int& particleIndex) const {
    return inBuffer[particleIndex];
}

int softforce::getParticlePoolSize() const {
    return particlePoolSize;
}


void softforce::applyForce(const int& particleIndex, vector force) {
    if (particleIndex >= 0 && particleIndex < particlePoolSize) {
        if (getParticle(particleIndex).getMass() != INFINITY) {
            outBuffer[particleIndex].setAcceleration(outBuffer[particleIndex].getAcceleration() + force / inBuffer[particleIndex].getMass());
        }
    }
}
