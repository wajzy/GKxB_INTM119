#include "Shape15.h"

double Shape::getArea() const {
  if(not areaCached) {
    calcArea();
    areaCached = true;
  }
  return area;
}

double Shape::getPerimeter() const {
  if(not perimeterCached) {
    calcPerimeter();
    perimeterCached = true;
  }
  return perimeter;
};
