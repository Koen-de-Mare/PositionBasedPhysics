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

    vector totalDisplacement = relativePosition;
    totalDisplacement.normalize();
    totalDisplacement = totalDisplacement * (length - relativePosition.getLength());
    //vector of the total displacement of vector2 relative to vector1

    vector displacement = totalDisplacement / (1 + inBuffer[particle1].getMass() / inBuffer[particle2].getMass());
    displacement = displacement * -1;       //because this vector points opposite to totaldisplacement
    outBuffer[particle1].setPosition(outBuffer[particle1].getPosition() + displacement);

    displacement = totalDisplacement / (1 + inBuffer[particle2].getMass() / inBuffer[particle1].getMass());
    outBuffer[particle2].setPosition(outBuffer[particle2].getPosition() + displacement);
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
