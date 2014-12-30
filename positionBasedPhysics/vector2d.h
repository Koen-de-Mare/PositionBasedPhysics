#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <cmath>

using unit = double;

class vector2D {
    public:
        vector2D(unit newX = 0, unit newY = 0);
        ~vector2D();
        unit getLength() const;
        unit getX() const;
        unit getY() const;
        void normalize();
        void setX(const unit&);
        void setY(const unit&);
        void set(const unit&, const unit&);
        vector2D operator+ (const vector2D&);
        vector2D operator - (const vector2D&);
        vector2D operator * (const unit&);
        vector2D operator / (const unit&);
        void operator = (const vector2D&);
    protected:
    private:
        unit x;
        unit y;
};

#endif // VECTOR2D_H
