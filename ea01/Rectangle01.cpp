#include <iostream>

struct Rectangle { // type of data related to a concept
  double width;
  double height;
};

void initRect(Rectangle &r, double w, double h) {
  r.width = w;
  r.height = h;
}

// weak connection between data and actions
double getRectArea(const Rectangle& r) {
  return r.width * r.height;
}

double getRectPerimeter(const Rectangle& r) {
  return 2. * (r.width + r.height);
}

void printRect(const Rectangle& r) {
  std::cout << "Rectangle[dimensions: " 
            << r.width << " x " << r.height << "]" 
            << std::endl;
}

int main() {
  Rectangle r1;
  printRect(r1); // r1 is not initialized
  initRect(r1, 5., 3.);
  printRect(r1);
  r1.width = 4.5; // data is not hidden
  printRect(r1);
  std::cout << "Area: " << getRectArea(r1) << std::endl;
  std::cout << "Perimeter: " << getRectPerimeter(r1) << std::endl;
}
