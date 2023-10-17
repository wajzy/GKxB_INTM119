#include "Complex6.h"

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << c.re << '+' << c.im << 'i';
  return os;
}

Complex operator+(const Complex& left, const Complex& right) {
    return Complex(left.re + right.re, left.im + right.im);
}

Complex operator*(const Complex& left, const Complex& right) {
  return Complex(left.re*right.re - left.im*right.im, left.im*right.re + left.re*right.im);
}
