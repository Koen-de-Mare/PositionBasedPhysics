#include "softforce.h"

softforce::softforce() {

}

softforce::~softforce() {

}

inline unit softforce::getDistance(const particle* particle1, const particle* particle2) const {
    return (particle1->getPosition() - particle2->getPosition()).getLength();
}

inline void softforce::applyForce(const particle* particle1, const vector& force) {

}
