#ifndef FILLEDRECTANGLE_H
#define FILLEDRECTANGLE_H

#include <iostream>
#include "rectangle.h"

class FilledRectangle : public Rectangle {
  public:
    FilledRectangle(int a, int b): Rectangle(a, b) {}
    virtual void draw() const;
};

#endif
