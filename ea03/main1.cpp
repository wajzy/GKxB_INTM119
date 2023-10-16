#include <iostream>
#include "Complex1.h"

int main() {
  Complex c(1., 1.);
  Complex sum = c.add(Complex(2., 2.));
  sum.print(); // 3+3i
  Complex total = c.mult(Complex(3., 4.));
  total.print(); // -1+7i
}
