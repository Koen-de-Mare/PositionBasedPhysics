#ifndef POSITIONCONSTRAINT_H
#define POSITIONCONSTRAINT_H

#include "constraint.h"

class positionconstraint : public constraint {
    public:
        positionconstraint(const int& newParticle, const vector& newPosition);
        virtual ~positionconstraint();
        bool getUsingParticle(const int& index) const;
        void changeIndex(const int& oldIndex, const int& newIndex);
    protected:
        void virtualResolveConstraint();
    private:
        int particle;
        vector position;
};

#endif // POSITIONCONSTRAINT_H
