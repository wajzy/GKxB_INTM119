#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <algorithm>

class Rectangle {
    double mWidth;
    double mHeight;
    // 'static' variable is shared among objects;
    // defined inside, initialized outside
    static int count;
  public:
    Rectangle(double=0., double=0.);

    double getWidth() {
      return mWidth;
    }

    double getHeight() {
      return this->mHeight;
    }

    void setWidth(double width) {
      mWidth = std::max(0., width);
    }

    void setHeight(double mHeight) {
      this->mHeight = std::max(0., mHeight);
    }

    double getArea() const {
      return mWidth * mHeight;
    }

    double getPerimeter() const;
    
    void print() const;

    static int getCount();

    ~Rectangle();
};

inline double Rectangle::getPerimeter() const {
  return 2. * (mWidth + mHeight);
}

#endif