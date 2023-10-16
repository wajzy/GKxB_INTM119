#include "Complex4.h"

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << c.re << '+' << c.im << 'i';
  return os;
}

Complex operator+(double re, const Complex& right) {
  return Complex(re + right.re, right.im);
}

Complex operator*(double re, const Complex& right) {
  return Complex(re*right.re, re*right.im);
}
