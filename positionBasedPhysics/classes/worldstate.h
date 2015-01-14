#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include <iostream>

#include "particle.h"
#include "softforces/softforce.h"
#include "constraints/constraint.h"

#define particlePoolSize_ 20
#define softforcePoolSize_ 20
#define constraintPoolSize_ 20

class particle;
class softforce;
class constraint;

class worldstate {
    public:
        worldstate();
        virtual ~worldstate();

        particle getParticle(const int& index);
        softforce* getSoftforce(const int& index);
        constraint* getConstraint(const int& index);

        void setParticle(const int& index, const particle& newParticle);

        int addParticle(const particle& newParticle);
        int addSoftforce(softforce* const newSoftforce);
        int addConstraint(constraint* const newConstraint);

        void removeParticle(const int& index);
        void removeSoftforce(const int& index);
        void removeConstraint(const int& index);

        particle* getParticlePool();

        int getParticlePoolSize() const;
        int getSoftforcePoolSize() const;
        int getConstraintPoolSize() const;

        bool isParticleActive(const int& index) const;

        void operator = (const worldstate& newValue);
    protected:
    private:
        const int particlePoolSize = particlePoolSize_;
        const int softforcePoolSize = softforcePoolSize_;
        const int constraintPoolSize = constraintPoolSize_;

        bool particlePoolFlag [particlePoolSize_];
        particle particlePool [particlePoolSize_];
        softforce* softforcePool [softforcePoolSize_];
        constraint* constraintPool [constraintPoolSize_];
};

#endif // WORLDSTATE_H
