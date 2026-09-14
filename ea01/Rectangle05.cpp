#include "Rectangle05.h"
#include <iostream>

Rectangle::Rectangle(double width, double height) {
  mWidth = width;
  mHeight = height;
}

void Rectangle::print() const {
  std::cout << "Rectangle[dimensions: " 
            << mWidth << " x " << mHeight << "]" 
            << std::endl;
}
