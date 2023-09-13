#include <iostream>
#include "Rectangle04.h"
int main() {
  Rectangle r1;
  r1.init(5., 3.);
  r1.print();
  std::cout << "Area: " << r1.getArea() << std::endl;
  std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
}
