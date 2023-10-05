#include <iostream>
#include <cmath>
#include "rectangle.h"
#include "filledrectangle.h"
#include "circle.h"
#include "filledcircle.h"

int main() {
  const Rectangle* pr = new Rectangle(4, 6);
  std::cout << "Rectangle, height: " << pr->getA() << ", width: " << pr->getB() << ".\n";
  pr->draw();
  delete pr;
  
  const FilledRectangle* pfr = new FilledRectangle(4, 6);
  std::cout << "FilledRectangle, height: " << pfr->getA() << ", width: " << pfr->getB() << ".\n";
  pfr->draw();
  delete pfr;
  
  const Circle* pc = new Circle(3);
  std::cout << "Circle, radius: " << pc->getR() << ".\n";
  pc->draw();
  delete pc;
  
  const FilledCircle* pfc = new FilledCircle(3);
  std::cout << "FilledCircle, radius: " << pfc->getR() << ".\n";
  pfc->draw();
  delete pfc;
}
