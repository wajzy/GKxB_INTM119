#include <iostream>

#define SQUARE(x) ((x)*(x))
#define ADD(x,y) ((x)+(y))

inline int add(int x, int y) {
    return x + y;
}

int main(void) {
  std::cout << "3^2=" << SQUARE(3) << std::endl;
  std::cout << "(3+1)^2=" << SQUARE(3+1) << std::endl;
  std::cout << "1+2=" << ADD(1, 2) << std::endl;       // ((1)+(2))=3
  std::cout << "4*(1+2)=" << 4*ADD(1, 2) << std::endl; // 4*((1)+(2))=12
  std::cout << "4*(1+2)=" << 4*add(1, 2) << std::endl; // 4*(1+2)=12
  return 0;
}
