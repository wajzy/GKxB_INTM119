#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

class Rectangle {
    const int a, b;
  public:
    Rectangle(int a, int b): a(a), b(b) {}
    void draw() const;
    int getA() const {
      return a;
    }
    int getB() const {
      return b;
    }
};

#endif
