#ifndef SOFTFORCE_H
#define SOFTFORCE_H

#include <math.h>

#include "particle.h"
#include "vector2d.h"
//#include "vector3d.h"

using unit = double;
using vector = vector2D;

class softforce {
    public:
        softforce();
        virtual ~softforce();
        virtual void applyForce() =0;
        virtual bool getUsingParticle(const int& index) const =0;
    protected:
        //subclass sandbox:
        inline unit getDistance(const int& index1, const int& index2);
        inline void applyForce(const int& index, const vector& force);
    private:
};

#endif // SOFTFORCE_H
