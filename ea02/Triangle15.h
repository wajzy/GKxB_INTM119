#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape15.h"
#include <cmath>

// inheritance; default is private
class Triangle : public Shape {
    double mA, mB, mC;
  public:
    // explicit call of base class's default constructor
    Triangle(double a, double b, double c) : Shape() {
      mA = a; mB = b; mC = c;
    }
    
    void setA(double a);
    void setB(double b);
    void setC(double c);
  protected:
    virtual void calcArea() const;
    virtual void calcPerimeter() const;
};

#endif
