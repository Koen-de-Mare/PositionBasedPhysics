#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "worldstate.h"

#include <iostream>

class worldstate;

class constraint {
    public:
        constraint();
        virtual ~constraint();
        virtual void resolveConstraint() {
            std::cout << "resolving constraint" << std::endl;
        }
    protected:
    private:
        worldstate* myWorldState;
};

#endif // CONSTRAINT_H
