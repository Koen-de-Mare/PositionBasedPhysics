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
        virtual void resolveConstraint(particle* const inBuffer, particle* outBuffer, int particlePoolSize) =0;
        virtual bool getUsingParticle(const int& index) const =0;
        virtual void changeIndex(const int& oldIndex, const int& newIndex) =0;
    protected:
        //subclass sandbox:
        inline unit getDistance(const particle* particle1, const particle* particle2) const;
        inline void displace(const particle* particle1, const vector& displacement);
    private:
};

#endif // CONSTRAINT_H
