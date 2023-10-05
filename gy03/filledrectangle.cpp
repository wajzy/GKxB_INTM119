#include "filledrectangle.h"

void FilledRectangle::draw() const {
  for(int r=0; r<a; r++) {
    for(int c=0; c<b; c++) {
      std::cout << '*';
    }
    std::cout << std::endl;
  }
}
