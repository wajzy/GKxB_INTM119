#include "Complex6.hpp"

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  return os << c.re << '+' << c.im << 'i';
}

Complex operator+(const Complex& left, const Complex& right) {
    return Complex(left.re + right.re, left.im + right.im);
}

Complex operator*(const Complex& left, const Complex& right) {
  return Complex(left.re*right.re - left.im*right.im, left.im*right.re + left.re*right.im);
}
