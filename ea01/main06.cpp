#include <iostream>
#include "Rectangle06.h"
int main() {
  Rectangle r1(5., 3.);
  r1.print();
  std::cout << "Area: " << r1.getArea() << std::endl;
  std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;

  Rectangle r2(-3.5, 10.); r2.print();
}
