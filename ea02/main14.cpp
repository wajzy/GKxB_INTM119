#include <iostream>
#include <iterator>
#include "Rectangle14.hpp"
#include "Triangle14.hpp"

int main() {
  Rectangle rArray[] = { 
    Rectangle(1., 2.), Rectangle(2., 3.), Rectangle(3., 4.) 
  };
  for(size_t i = 0; i < std::size(rArray); ++i) {
    std::cout << "Rectangle #" << (i+1)
              << " Area: " << rArray[i].getArea()
              << " Perimeter: " << rArray[i].getPerimeter()
              << std::endl;
  }
  const Triangle tArray[] = { 
    Triangle(3., 4., 5.), Triangle(5., 12., 13.), Triangle(7., 24., 25.) 
  };
  for(size_t i = 0; i < std::size(tArray); ++i) {
    std::cout << "Triangle #" << (i+1)
              << " Area: " << tArray[i].getArea()
              << " Perimeter: " << tArray[i].getPerimeter()
              << std::endl;
  }
  // const Shape sArray[] = { ... }; // ?!
}
