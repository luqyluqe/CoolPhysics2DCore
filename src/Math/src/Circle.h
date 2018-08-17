#ifndef MATH_CIRCLE_H
#define MATH_CIRCLE_H

#include "MathDefines.h"
#include "Vector.h"

BEGIN_NAMESPACE_MATH

class Circle
{
public:
    //Constructor
    Circle(const Vector& center,double radius);
    
    //Accessor
    const Vector& center()const;
    double radius()const;
    
    //Property
    double area()const;
private:
    Vector _center;
    double _radius;
};

END_NAMESPACE_MATH

#endif
