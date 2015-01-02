#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include "particle.h"
#include "softforce.h"
#include "constraint.h"

#define particlePoolSize_ 20
#define softForcePoolSize_ 20
#define constraintPoolSize_ 20

class particle;
class softforce;
class constraint;

class worldstate {
    public:
        const worldstate* ME = this;
        worldstate();
        virtual ~worldstate();
        particle* getParticle(int index);
        softforce* getSoftForce(int index);
        constraint* getConstraint(int index);
        void removeParticle(int index);
        void removeSoftForce(int index);
        void removeConstraint(int index);
        particle* getParticlePool();
        int getParticlePoolSize();
    protected:
    private:
        const int particlePoolSize = particlePoolSize_;
        const int softForcePoolSize = softForcePoolSize_;
        const int constraintPoolSize = constraintPoolSize_;
        bool particlePoolFlag [particlePoolSize_];
        particle particlePool [particlePoolSize_];
        softforce* softForcePool [softForcePoolSize_];
        constraint* constraintPool [constraintPoolSize_];
};

#endif // WORLDSTATE_H
