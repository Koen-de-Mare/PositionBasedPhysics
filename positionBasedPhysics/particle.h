#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector2d.h"

using vector = vector2D;

class particle {
    public:
        particle();
        virtual ~particle();
        vector getPosition();
        void setPosition(vector newPosition);
    protected:
    private:
        vector position;
};

#endif // PARTICLE_H
