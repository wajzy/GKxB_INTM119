#include "Rectangle06.h"

Rectangle::Rectangle() {
  mWidth = mHeight = 0.;
}

Rectangle::Rectangle(double width, double height) {
  mWidth = width;
  mHeight = height;
}

void Rectangle::print() const {
  std::cout << "Rectangle[dimensions: " 
            << mWidth << " x " << mHeight << "]" 
            << std::endl;
}
