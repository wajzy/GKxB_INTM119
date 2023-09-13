#include <iostream>
#include "Rectangle05.h"
int main() {
  // error: no matching constructor for initialization of 'Rectangle'
  // Rectangle r1;
  Rectangle r1(5., 3.);
  r1.print();
  std::cout << "Area: " << r1.getArea() << std::endl;
  std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
}
