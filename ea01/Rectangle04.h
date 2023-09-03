#ifndef RECTANGLE_H
#define RECTANGLE_H
// https://en.cppreference.com/w/cpp/preprocessor/impl#.23pragma_once
// #pragma once

#include <iostream>

class Rectangle {
    double mWidth;
    double mHeight;
  public:
    void init(double, double);

    double getArea() const {
      return mWidth * mHeight;
    }

    double getPerimeter() const;
    
    void print() const;
};

// inline functions are not included in the object file
// compiled from 'Rectangle.cpp'
inline double Rectangle::getPerimeter() const {
  return 2. * (mWidth + mHeight);
}

#endif
