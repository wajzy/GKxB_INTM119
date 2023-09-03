#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <algorithm>

class Rectangle {
    double mWidth;
    double mHeight;
  public:
    Rectangle(double=0., double=0.);

    double getWidth() {
      return mWidth;
    }

    double getHeight() {
      // legal but useless
      return this->mHeight;
    }

    void setWidth(double width) {
      mWidth = std::max(0., width);
    }

    // unusual and dangerous naming
    void setHeight(double mHeight) {
      // 'this' points to the current object
      this->mHeight = std::max(0., mHeight);
    }

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
