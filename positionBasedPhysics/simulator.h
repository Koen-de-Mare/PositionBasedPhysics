#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "worldstate.h"

class simulator {
    public:
        simulator();
        virtual ~simulator();
        worldstate simulate(worldstate world, float deltaTime);
        void setFullIterationsNumber(int newFullIterationsNumber);
        void setProjectionIterationsNumber(int newProjectionIterationsNumber);
        void setRelaxationIterationsNumber(int newRelaxationIterationsNumber);
    protected:
    private:
        int fullIterationsNumber = 1;
        int projectionIterationsNumber = 1;
        int relaxationIterationsNumber = 1;
};

#endif // SIMULATOR_H
