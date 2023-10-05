#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>
#include "shape.h"

class Circle: public Shape {
  protected:
    const int r;
  public:
    Circle(int r): r(r) {}
    virtual void draw() const;
    int getR() const {
      return r;
    }
};

#endif
