#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <algorithm>

class Rectangle {
    double mWidth;
    double mHeight;
    // 'static' variable is shared among objects;
    // defined inside, initialized outside
    static int count;
  public:
    Rectangle(double=0., double=0.);

    double getWidth() const {
      return mWidth;
    }

    double getHeight() const {
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

    static int getCount(); // `const` cannot be applied wo `this`

    ~Rectangle();
};

inline double Rectangle::getPerimeter() const {
  return 2. * (mWidth + mHeight);
}

#endif