#include "Triangle14.h"

void Triangle::setA(double a) {
  mA = a;
  invalidateCache();
}

void Triangle::setB(double b) {
  mB = b;
  invalidateCache();
}

void Triangle::setC(double c) {
  mC = c;
  invalidateCache();
}

double Triangle::getArea() const {
  if(not areaCached) {
    calcArea();
    areaCached = true;
  }
  return area;
}

double Triangle::getPerimeter() const {
  if(not perimeterCached) {
    calcPerimeter();
    perimeterCached = true;
  }
  return perimeter;
};

void Triangle::calcArea() const {
  double s = (mA + mB + mC) / 2.;
  area = sqrt(s * (s - mA) * (s - mB) * (s - mC));
}

void Triangle::calcPerimeter() const {
  perimeter = mA + mB + mC;
}
