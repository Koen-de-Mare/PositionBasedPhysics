#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector2d.h"
//#include "vector3d.h"

using vector = vector2D;

class particle {
    public:
        particle();
        virtual ~particle();
        vector getPosition() const;
        vector getVelocity() const;
        vector getAcceleration() const;
        void setPosition(vector newPosition);
        void setVelocity(vector newVelocity);
        void setAcceleration(vector newAcceleration);
        void clear();
        void operator = (const particle& newValue);
    protected:
    private:
        vector position;
        vector velocity;
        vector acceleration;
};

#endif // PARTICLE_H
