#include "constraint.h"

constraint::constraint() {

}

constraint::~constraint() {

}

unit constraint::getDistance(const particle& particle1, const particle& particle2) const {
    return (particle1.getPosition() - particle2.getPosition()).getLength();
}
