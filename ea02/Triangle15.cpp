#include "Triangle15.h"

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

void Triangle::calcArea() const {
  double s = (mA + mB + mC) / 2.;
  area = sqrt(s * (s - mA) * (s - mB) * (s - mC));
}

void Triangle::calcPerimeter() const {
  perimeter = mA + mB + mC;
}
