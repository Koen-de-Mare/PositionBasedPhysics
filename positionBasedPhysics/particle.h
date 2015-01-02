#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector2d.h"
//#include "vector3d.h"

using vector = vector2D;

class particle {
    public:
        particle();
        virtual ~particle();
        vector getPosition();
        vector getVelocity();
        vector getAcceleration();
        void setPosition(vector newPosition);
        void setVelocity(vector newVelocity);
        void setAcceleration(vector newAcceleration);
        void clear();
    protected:
    private:
        vector position;
        vector velocity;
        vector acceleration;
};

#endif // PARTICLE_H
