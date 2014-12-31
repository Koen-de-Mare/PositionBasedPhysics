#include "particle.h"

particle::particle() {
    //position = new vector();
}

particle::~particle() {
    delete &position;
}

vector particle::getPosition() {
    return position;
}

void particle::setPosition(vector newPosition) {
    position = newPosition;
}
