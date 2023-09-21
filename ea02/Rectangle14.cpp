#include "Rectangle14.h"

void Rectangle::setWidth(double width) {
  mWidth = width;
  invalidateCache();
}

void Rectangle::setHeight(double height) {
  mHeight = height;
  invalidateCache();
}

double Rectangle::getArea() const {
  if(not areaCached) {
    calcArea();
    areaCached = true;
  }
  return area;
}

double Rectangle::getPerimeter() const {
  if(not perimeterCached) {
    calcPerimeter();
    perimeterCached = true;
  }
  return perimeter;
};

void Rectangle::calcArea() const {
  area = mWidth * mHeight;
}

void Rectangle::calcPerimeter() const {
  perimeter = 2. * (mWidth + mHeight);
}
