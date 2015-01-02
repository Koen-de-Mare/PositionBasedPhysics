#include "simulator.h"

simulator::simulator() {

}

simulator::~simulator() {
    delete &fullIterationsNumber;
    delete &projectionIterationsNumber;
    delete &relaxationIterationsNumber;
}

worldstate simulator::simulate(worldstate world, float deltaTime) {

}

void simulator::setFullIterationsNumber(int newFullIterationsNumber) {
    fullIterationsNumber = newFullIterationsNumber;
}

void simulator::setProjectionIterationsNumber(int newProjectionIterationsNumber) {
    projectionIterationsNumber = newProjectionIterationsNumber;
}

void simulator::setRelaxationIterationsNumber(int newRelaxationIterationsNumber) {
    relaxationIterationsNumber = newRelaxationIterationsNumber;
}
