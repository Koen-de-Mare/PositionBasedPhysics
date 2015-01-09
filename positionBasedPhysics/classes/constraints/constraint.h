#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <math.h>

#include "particle.h"
#include "vector/vector2d.h"
//#include "vector/vector3d.h"

using unit = double;
using vector = vector2D;

class constraint {
    public:
        constraint();
        virtual ~constraint();
        void resolveConstraint(particle* const newInBuffer, particle* newOutBuffer, const int& newParticlePoolSize);
        virtual bool getUsingParticle(const int& index) const =0;
        virtual void changeIndex(const int& oldIndex, const int& newIndex) =0;
    protected:
        virtual void virtualResolveConstraint() =0;
    //subclass sandbox:
        vector getPosition(const int& particleIndex) const;
        unit getDistance(const int& particleIndex1, const int& particleIndex2) const;
        const particle getParticle(const int& particleIndex) const;

        void displace(const int& particleIndex, const vector& displacement);
        void setPosition(const int& particleIndex, const vector& newPosition);
    private:
        particle* inBuffer = nullptr;
        particle* outBuffer = nullptr;
        int particlePoolSize = 1;
};

#endif // CONSTRAINT_H
