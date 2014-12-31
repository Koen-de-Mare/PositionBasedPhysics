#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include "particle.h"

#define particlePoolSize_ 20
#define softForcePoolSize_ 20;
#define constraintPoolSize_ 20;

class worldstate {
    public:
        worldstate();
        virtual ~worldstate();
    protected:
    private:
        const int particlePoolSize = particlePoolSize_;
        const int softForcePoolSize = softForcePoolSize_;
        const int constraintPoolSize = softForcePoolSize_;
        particle particlePool [particlePoolSize_];
        //softForce softForcePool [softForcePoolSize_];
        //constraint constraintPool [constraintPoolSize_];
};

#endif // WORLDSTATE_H
