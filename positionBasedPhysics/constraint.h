#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "worldstate.h"

#include <iostream>

class worldstate;

class constraint {
    public:
        constraint(worldstate* newMyWorldState);
        virtual ~constraint();
        virtual void resolveConstraint() =0;
        virtual bool getUsingParticle(int index) =0;
    protected:
    private:
        worldstate* myWorldState;
};

#endif // CONSTRAINT_H
