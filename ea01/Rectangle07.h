#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <algorithm>

class Rectangle {
    double mWidth;
    double mHeight;
  public:
    // default parameters
    Rectangle(double=0., double=0.);

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
