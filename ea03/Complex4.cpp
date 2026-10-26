#include "Complex4.hpp"

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  return os << c.re << '+' << c.im << 'i';
}

Complex operator+(double re, const Complex& right) {
  return Complex(re + right.re, right.im);
}

Complex operator*(double re, const Complex& right) {
  return Complex(re*right.re, re*right.im);
}
