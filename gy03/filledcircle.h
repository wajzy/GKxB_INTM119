#ifndef FILLEDCIRCLE_H
#define FILLEDCIRCLE_H

#include <iostream>
#include <cmath>

class FilledCircle {
    const int r;
  public:
    FilledCircle(int r): r(r) {}
    void draw() const;
    int getR() const {
      return r;
    }
};

#endif
