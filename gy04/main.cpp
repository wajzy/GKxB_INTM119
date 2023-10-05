#include <iostream>
#include <cmath>
#include "rectangle.h"
#include "filledrectangle.h"
#include "circle.h"
#include "filledcircle.h"

int main() {
  const Shape* sArray[] = {
    new Rectangle(4, 6),
    new FilledRectangle(4, 6),
    new Circle(3),
    new FilledCircle(3)
  };
  for(auto ps=sArray; ps<sArray+sizeof(sArray)/sizeof(*sArray); ps++) {
    auto pc = dynamic_cast<const Circle*>(*ps);
    if(pc != nullptr) {
      std::cout << "Radius: " << pc->getR() << ".\n";
    }
    auto pr = dynamic_cast<const Rectangle*>(*ps);
    if(pr != nullptr) {
      std::cout << "Height: " << pr->getA() << ", width: " << pr->getB() << ".\n";
    }
    (*ps)->draw();
    delete *ps;
  }
}
