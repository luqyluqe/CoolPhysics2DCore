#ifndef MATH_RECTANGLE_H
#define MATH_RECTANGLE_H

#include "MathDefines.h"
#include "Vector.h"
#include "Circle.h"

BEGIN_NAMESPACE_MATH

class Rectangle
{
public:
    //Constructor
    Rectangle(double x,double y,double width,double height);
    //Accessor
    double x()const;
    double y()const;
    double width()const;
    double height()const;
    
    //Judgement
    bool contain(const Vector& point)const;
    bool overlap(const Circle& circle)const;
    
    //Arithmetic
    double overlapArea(const Circle& cirle)const;
    
private:
    double _x;
    double _y;
    double _width;
    double _height;
};

END_NAMESPACE_MATH

#endif

