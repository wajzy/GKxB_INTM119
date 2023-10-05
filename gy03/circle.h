#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

class Circle {
    const int r;
  public:
    Circle(int r): r(r) {}
    void draw() const;
    int getR() const {
      return r;
    }
};

#endif
