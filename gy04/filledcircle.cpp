#include "filledcircle.h"

void FilledCircle::draw() const {
  for(int r=-this->r; r<=this->r; r++) {
    for(int c=-this->r; c<=this->r; c++) {
      std::cout << (abs(c) <= round(sqrt(this->r*this->r - r*r)) ? '*' : ' ');
    }
    std::cout << std::endl;
  }
}
