#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
    double mWidth;
    double mHeight;
  public:
    Rectangle(); // default constructor
    Rectangle(double, double);

    double getArea() const {
      return mWidth * mHeight;
    }

    double getPerimeter() const;
    
    void print() const;
};

inline double Rectangle::getPerimeter() const {
  return 2. * (mWidth + mHeight);
}

#endif