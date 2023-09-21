#include <iostream>
#include <typeinfo> // typeid() uses RTTI
#include "Shape15.h"
#include "Rectangle15.h"
#include "Triangle15.h"

int main() {
  const int n = 4;
  // cannot create array of abstract objects
  Shape* sArray1[n] = { 
    // new calls constructor
    new Rectangle(1., 2.), new Rectangle(2., 3.),
    new Triangle(3., 4., 5.), new Triangle(5., 12., 13.)
  };
  for(int i=0; i<n; i++) {
    // name mangling
    std::cout << typeid(*sArray1[i]).name() << " #" << (i+1)
              << " Area: " << sArray1[i]->getArea()
              << " Perimeter: " << sArray1[i]->getPerimeter()
              << std::endl;
  }
  std::cout << (std::is_abstract<Shape>() 
      ? "Shape is abstract." 
      : "Shape is NOT abstract.") 
    << std::endl;
  std::cout << (std::is_abstract<Rectangle>() 
      ? "Rectangle is abstract." 
      : "Rectangle is NOT abstract.") 
    << std::endl;
}
