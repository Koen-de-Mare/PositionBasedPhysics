#ifndef DISTANCECONSTRAINT_H
#define DISTANCECONSTRAINT_H

#include "constraint.h"

class distanceconstraint : public constraint {
    public:
        distanceconstraint(const int& newParticle1, const int& newParticle2, const unit& newLength, const int& newType);
        virtual ~distanceconstraint();
        bool getUsingParticle(const int& index) const;
        void changeIndex(const int& oldIndex, const int& newIndex);
    protected:
        void virtualResolveConstraint();
    private:
        enum distanceConstraintType {
            equality,
            greater,
            smaller
        } myType;
        unit length;
        int particle1;
        int particle2;
};

#endif // DISTANCECONSTRAINT_H
