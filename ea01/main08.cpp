#include <iostream>
#include "Rectangle08.hpp"
int main() {
  Rectangle r1;
  r1.setWidth(5.);
  r1.setHeight(3.);
  std::cout << "Width: " << r1.getWidth() << std::endl;
  std::cout << "Height: " << r1.getHeight() << std::endl;
}
