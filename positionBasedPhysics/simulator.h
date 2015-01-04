#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "worldstate.h"

using timeUnit = float;

class simulator {
    public:
        simulator();
        virtual ~simulator();
        void simulate(worldstate* providedWorld, timeUnit deltaTime);
        void virtualSimulate(worldstate* providedWorld, timeUnit deltaTime);
        void setFullIterationsNumber(int newFullIterationsNumber);
        void setProjectionIterationsNumber(int newProjectionIterationsNumber);
        void setRelaxationIterationsNumber(int newRelaxationIterationsNumber);
    protected:
        worldstate* world;

        void project(timeUnit deltaTime);
        void Relax();
        void integrate(timeUnit deltaTime);

        particle* t0;
        particle* tP;
        particle* t1;
        particle* tBuffer;

        int particlePoolSize;
    private:
        int fullIterationsNumber = 1;
        int projectionIterationsNumber = 1;
        int relaxationIterationsNumber = 1;
};

#endif // SIMULATOR_H
