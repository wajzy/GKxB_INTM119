#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape15.h"

// inheritance; base class -> subclass / derived class
class Rectangle : public Shape {
    double mWidth;
    double mHeight;
  public:
    // implicit call of base class's default constructor
    Rectangle(double width, double height) {
      mWidth = width;
      mHeight = height;
    }
    
    void setWidth(double width);
    void setHeight(double height);
  protected:
    virtual void calcArea() const;
    virtual void calcPerimeter() const;
};

#endif
