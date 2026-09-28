#include <iostream>
#include "Rectangle12.hpp"

int main() {
  const Rectangle r1(5., 3.);
  std::cout << "Area (1st attempt): " << r1.getArea() << std::endl;
  std::cout << "Area (2nd attempt): " << r1.getArea() << std::endl;

  Rectangle r2(1., 2.);
  std::cout << "Perimeter (1st attempt): " << r2.getPerimeter() << std::endl;
  std::cout << "Perimeter (2nd attempt): " << r2.getPerimeter() << std::endl;
  r2.setWidth(3.);
  std::cout << "Perimeter (3rd attempt): " << r2.getPerimeter() << std::endl;
}
