#include "Rectangle09.hpp"
#include <iostream>

Rectangle::Rectangle(double width, double height) {
  count++;
  std::cout << "Rectangle #" << count << " created.\n";
  mWidth = std::max(0., width);
  mHeight = std::max(0., height);
}

Rectangle::~Rectangle() {
  std::cout << "Rectangle #" << count << " freed.\n";
  count--;
}

void Rectangle::print() const {
  std::cout << "Rectangle[dimensions: " << mWidth << " x " << mHeight << "]" << std::endl;
}

// initializing static variable must be in source, not in header!
int Rectangle::count = 0;

int Rectangle::getCount() {
  return count;
}
