#ifndef SOFTFORCE_H
#define SOFTFORCE_H

#include <math.h>

#include <iostream>

#include "particle.h"
#include "vector/vector2d.h"
//#include "vector/vector3d.h"

using unit = double;
using vector = vector2D;

class softforce {
    public:
        softforce();
        virtual ~softforce();
        virtual void applySoftforce(particle* const newInBuffer, particle* newOutBuffer, const int& newParticlePoolSize);
        virtual bool getUsingParticle(const int& index) const =0;
        virtual void changeIndex(const int& oldIndex, const int& newIndex) =0;
    protected:
        virtual void virtualApplySoftforce() =0;
        //subclass sandbox:
        vector getPosition(const int& particleIndex) const;
        unit getDistance(const int& particleIndex1, const int& particleIndex2) const;
        const particle getParticle(const int& particleIndex) const;

        int getParticlePoolSize() const;

        void applyForce(const int& particleIndex, vector force);
    private:
        particle* inBuffer = nullptr;
        particle* outBuffer = nullptr;
        int particlePoolSize = 0;
};

#endif // SOFTFORCE_H
