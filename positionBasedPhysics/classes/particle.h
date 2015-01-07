#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector/vector2d.h"
//#include "vector/vector3d.h"

using vector = vector2D;

class particle {
    public:
        particle(float newMass = 1);
        virtual ~particle();
        vector getPosition() const;
        vector getVelocity() const;
        vector getAcceleration() const;
        float getMass() const;
        void setPosition(const vector& newPosition);
        void setVelocity(const vector& newVelocity);
        void setAcceleration(const vector& newAcceleration);
        void clear();
        void operator = (const particle& newValue);
    protected:
    private:
        vector position;
        vector velocity;
        vector acceleration;
        float mass;
};

#endif // PARTICLE_H
