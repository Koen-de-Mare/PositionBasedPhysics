#include "distanceconstraint.h"

distanceconstraint::distanceconstraint(const int& newParticle1, const int& newParticle2, const unit& newLength, const int& newType) {
    particle1 = newParticle1;
    particle2 = newParticle2;
    switch (newType) {
        case 1:
            myType = equality;
            break;
        case 2:
            myType = greater;
            break;
        case 3:
            myType = smaller;
            break;
        default:
            //something went wrong
            myType = equality;
    }
    length = newLength;
}


distanceconstraint::~distanceconstraint() {
    //dtor
}

void distanceconstraint::resolveConstraint(particle* const inBuffer, particle* outBuffer, int particlePoolSize) {
    vector relativePosition = inBuffer[particle2].getPosition() - inBuffer[particle1].getPosition();
    //vector pointing from particle1 to particle2

    switch (myType) {
        case greater:
            if (relativePosition.getLength() >= length) {
                return;
            }
            break;
        case smaller:
            if (relativePosition.getLength() <= length) {
                return;
            }
            break;
    }

    //set the distance between the two particles to distance
}
