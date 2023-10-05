#ifndef FILLEDRECTANGLE_H
#define FILLEDRECTANGLE_H

#include <iostream>

class FilledRectangle {
    const int a, b;
  public:
    FilledRectangle(int a, int b): a(a), b(b) {}
    void draw() const;
    int getA() const {
      return a;
    }
    int getB() const {
      return b;
    }
};

#endif
