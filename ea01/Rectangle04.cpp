#include "Rectangle04.hpp"
#include <iostream>

void Rectangle::init(double width, double height) {
  mWidth = width;
  mHeight = height;
}

void Rectangle::print() const {
  std::cout << "Rectangle[dimensions: " 
            << mWidth << " x " << mHeight << "]" 
            << std::endl;
}
