#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "shape.h"

class Rectangle : public Shape {
  protected:
    const int a, b;
  public:
    Rectangle(int a, int b): a(a), b(b) {}
    virtual void draw() const;
    int getA() const {
      return a;
    }
    int getB() const {
      return b;
    }
};

#endif
