#include "Rectangle08.hpp"
#include <iostream>

Rectangle::Rectangle(double width, double height) {
  mWidth = std::max(0., width);
  mHeight = std::max(0., height);
}

void Rectangle::print() const {
  std::cout << "Rectangle[dimensions: " 
            << mWidth << " x " << mHeight << "]" 
            << std::endl;
}
