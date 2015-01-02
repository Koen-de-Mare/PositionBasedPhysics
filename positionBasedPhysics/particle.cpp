#include "particle.h"

particle::particle() {
    clear();
}

particle::~particle() {
    delete &position;
}

vector particle::getPosition() {
    return position;
}

vector particle::getVelocity(){
    return velocity;
}

vector particle::getAcceleration() {
    return acceleration;
}

void particle::setPosition(vector newPosition) {
    position = newPosition;
}

void particle::setVelocity(vector newVelocity) {
    velocity = newVelocity;
}

void particle::setAcceleration(vector newAcceleration) {
    acceleration = newAcceleration;
}

void particle::clear() {
    position.clear();
    velocity.clear();
    acceleration.clear();
}
