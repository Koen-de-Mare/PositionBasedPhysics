#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <math.h>

#include "particle.h"
#include "vector2d.h"
//#include "vector3d.h"

using unit = double;
using vector = vector2D;

class constraint {
    public:
        constraint();
        virtual ~constraint();
        virtual void resolveConstraint() =0;
        virtual bool getUsingParticle(const int& index) const =0;
    protected:
        //subclass sandbox:
        inline unit getDistance(const particle& particle1, const particle& particle2) const;
    private:
};

#endif // CONSTRAINT_H
