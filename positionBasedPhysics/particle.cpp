#include "particle.h"

particle::particle() {
    clear();
}

particle::~particle() {
    delete &position;
}

vector particle::getPosition() const {
    return position;
}

vector particle::getVelocity() const {
    return velocity;
}

vector particle::getAcceleration() const {
    return acceleration;
}

void particle::setPosition(const vector& newPosition) {
    position = newPosition;
}

void particle::setVelocity(const vector& newVelocity) {
    velocity = newVelocity;
}

void particle::setAcceleration(const vector& newAcceleration) {
    acceleration = newAcceleration;
}

void particle::clear() {
    position.clear();
    velocity.clear();
    acceleration.clear();
}

void particle::operator=(const particle& newValue) {
    position = newValue.getPosition();
    velocity = newValue.getVelocity();
    acceleration = newValue.getAcceleration();
}
