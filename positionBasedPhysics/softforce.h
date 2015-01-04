#ifndef SOFTFORCE_H
#define SOFTFORCE_H

#include <math.h>

#include "particle.h"
#include "vector2d.h"
//#include "vector3d.h"

using timeUnit = float;
using unit = double;
using vector = vector2D;

class softforce {
    public:
        softforce();
        virtual ~softforce();
        virtual void applySoftforce(particle* inBuffer, particle* outBuffer, int particlePoolSize, timeUnit deltaTime) =0;
        virtual bool getUsingParticle(const int& index) const =0;
    protected:
        //subclass sandbox:
        inline unit getDistance(const particle* particle1, const particle* particle2) const;
        inline void applyForce(const particle* particle1, const vector& force);
    private:
};

#endif // SOFTFORCE_H
