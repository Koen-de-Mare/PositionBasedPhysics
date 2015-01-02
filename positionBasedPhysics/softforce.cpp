#include "softforce.h"

softforce::softforce(worldstate* newMyWorldState) {
    myWorldState = newMyWorldState;
}

softforce::~softforce() {
    delete &myWorldState;
}
