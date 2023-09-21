#include <iostream>
#include "Rectangle14.h"
#include "Triangle14.h"

int main() {
  const int n = 3;
  Rectangle rArray[n] = { 
    Rectangle(1., 2.), Rectangle(2., 3.), Rectangle(3., 4.) 
  };
  for(int i=0; i<n; i++) {
    std::cout << "Rectangle #" << (i+1)
              << " Area: " << rArray[i].getArea()
              << " Perimeter: " << rArray[i].getPerimeter()
              << std::endl;
  }
  const Triangle tArray[n] = { 
    Triangle(3., 4., 5.), Triangle(5., 12., 13.), Triangle(7., 24., 25.) 
  };
  for(int i=0; i<n; i++) {
    std::cout << "Triangle #" << (i+1)
              << " Area: " << tArray[i].getArea()
              << " Perimeter: " << tArray[i].getPerimeter()
              << std::endl;
  }
  // const Shape sArray[n]; // ?!
}
