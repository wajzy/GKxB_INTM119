#include <iostream>
#include "Rectangle12.hpp"

double Rectangle::getArea() const {
  if(not areaCached) {
    std::cout << "[calculating area] ";
    area = mWidth * mHeight;
    areaCached = true;
  }
  return area;
}

double Rectangle::getPerimeter() const {
  if(not perimeterCached) {
    std::cout << "[calculating perimeter] ";
    perimeter = 2. * (mWidth + mHeight);
    perimeterCached = true;
  }
  return perimeter;
}