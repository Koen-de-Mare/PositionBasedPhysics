#include "constraint.h"

constraint::constraint(worldstate* newMyWorldState) {
    myWorldState = newMyWorldState;
}

constraint::~constraint() {
    delete &myWorldState;
}
