#ifndef FILLEDCIRCLE_H
#define FILLEDCIRCLE_H

#include <iostream>
#include <cmath>
#include "circle.h"

class FilledCircle : public Circle {
  public:
    FilledCircle(int r): Circle(r) {}
    virtual void draw() const;
};

#endif
