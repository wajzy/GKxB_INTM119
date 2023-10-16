#include <iostream>
#include "Complex2.h"

int main() {
  Complex c(1., 1.);
  // Complex sum = c.operator+(Complex(2., 2.));
  Complex sum = c + Complex(2., 2.);
  sum.print();
  // Complex sum2 = c + 100.;
  // error: no match for 'operator+' (operand types are 'Complex' and 'double')
  // note:  no known conversion for argument 1 from 'double' to 'const Complex&'
  Complex total = c * Complex(3., 4.);
  total.print();
}
