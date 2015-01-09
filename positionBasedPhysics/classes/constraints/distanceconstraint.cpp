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

void distanceconstraint::virtualResolveConstraint() {
    // port this to the new constraint.h implementation

    vector relativePosition = getPosition(particle1) - getPosition(particle2);
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

    vector totalDisplacement = relativePosition;
    totalDisplacement.normalize();
    totalDisplacement = totalDisplacement * (length - relativePosition.getLength());
    //vector of the total displacement of vector2 relative to vector1

    displace(particle1, totalDisplacement * -1 / (1 + getParticle(particle1).getMass() / getParticle(particle2).getMass()));

    displace(particle2, totalDisplacement / (1 + getParticle(particle2).getMass() / getParticle(particle1).getMass()));
}

bool distanceconstraint::getUsingParticle(const int& index) const {
    if (particle1 == index) {
        return true;
    }
    if (particle2 == index) {
        return true;
    }
    return false;
}

void distanceconstraint::changeIndex(const int& oldIndex, const int& newIndex) {
    if (particle1 == oldIndex) {
        particle1 = newIndex;
    }
    if (particle2 == oldIndex) {
        particle2 == newIndex;
    }
}
