#ifndef PARTICLEPOOL_H
#define PARTICLEPOOL_H

#include "particles/particle.h"
#include "vector/vector2d.h"
#include "vector/vector3d.h"

using vector = vector2D;

class particlePool {
    public:
        particlePool(const int& initialParticlePoolSize = 0);
        virtual ~particlePool();

        const particle getParticle(const int& index) const;
        const vector getPosition(const int& index) const;
        const vector getVelocity(const int& index) const;
        const vector getAcceleration(const int& index) const;

        void setParticle(const int& index, const particle& newParticle);
        void setPosition(const int& index, const vector& newPosition);
        void setVelocity(const int& index, const vector& newVelocity);
        void setAcceleration(const int& index, const vector& newAcceleration);

        void clearAcceleration();

        int addParticle(const particle& newParticle);
        void removeParticle(const int& index);

        int getParticlePoolSize() const;

        void initialize(const int& newParticlePoolSize);
        void clear();

        particlePool operator = (const particlePool& newValue);
    protected:
    private:
        bool* myParticlePoolFlag = nullptr;
        particle* myParticlePool = nullptr;
        int particlePoolSize = 0;
};

#endif // PARTICLEPOOL_H
