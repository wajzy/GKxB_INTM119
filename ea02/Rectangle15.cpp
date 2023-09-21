#include "Rectangle15.h"

void Rectangle::setWidth(double width) {
  mWidth = width;
  invalidateCache();
}

void Rectangle::setHeight(double height) {
  mHeight = height;
  invalidateCache();
}

void Rectangle::calcArea() const {
  area = mWidth * mHeight;
}

void Rectangle::calcPerimeter() const {
  perimeter = 2. * (mWidth + mHeight);
}
