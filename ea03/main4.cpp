#include <iostream>
#include "Complex4.h"

int main() {
  Complex c(1., 1.);
  // Complex sum = c.operator+(Complex(2., 2.));
  Complex sum = c + Complex(2., 2.);
  std::cout << sum << std::endl; // 3+3i
  // Complex sum2 = c.operator+(100.);
  Complex sum2 = c + 100.;
  std::cout << sum2 << std::endl; // 101+1i
  // Complex sum3 = operator+(100., c);
  Complex sum3 = 100. + c;
  std::cout << sum3 << std::endl; // 101+1i
  Complex total = c * Complex(3., 4.);
  std::cout << total << std::endl; // -1+7i
}
