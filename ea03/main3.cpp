#include <iostream>
#include "Complex3.h"

int main() {
  Complex c(1., 1.);
  // Complex sum = c.operator+(Complex(2., 2.));
  Complex sum = c + Complex(2., 2.);
  sum.print();
  // Complex sum2 = c.operator+(100.);
  Complex sum2 = c + 100.;
  sum2.print();
  // Complex sum3 = 100. + c;
  // error: no match for 'operator+' 
  // (operand types are 'double' and 'Complex')
  Complex total = c * Complex(3., 4.);
  total.print();
}
