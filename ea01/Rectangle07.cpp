#include "Rectangle07.hpp"
#include <iostream>
#include <algorithm>

Rectangle::Rectangle(double width, double height) {
  // negative values are not allowed
  mWidth = std::max(0., width);
  mHeight = std::max(0., height);
}

void Rectangle::print() const {
  std::cout << "Rectangle[dimensions: " 
            << mWidth << " x " << mHeight << "]" 
            << std::endl;
}
