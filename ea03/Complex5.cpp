#include "Complex5.h"

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << c.re << '+' << c.im << 'i';
  return os;
}

Complex operator+(const Complex& left, const Complex& right) {
    return Complex(left.re + right.re, left.im + right.im);
}
Complex operator+(const Complex& left, double re) {
  return Complex(left.re + re, left.im);
}
Complex operator+(double re, const Complex& right) {
  return Complex(re + right.re, right.im);
}

Complex operator*(const Complex& left, const Complex& right) {
  return Complex(left.re*right.re - left.im*right.im, left.im*right.re + left.re*right.im);
}
Complex operator*(const Complex& left, double re) {
  return Complex(left.re*re, left.im*re);
}
Complex operator*(double re, const Complex& right) {
  return Complex(re*right.re, re*right.im);
}
