#include "rectangle.h"

void Rectangle::draw() const {
  for(int r=0; r<a; r++) {
    for(int c=0; c<b; c++) {
      std::cout << (r==0 or r==a-1 or c==0 or c==b-1 ? '*' : ' ');
    }
    std::cout << std::endl;
  }
}
