#ifndef COMPLEX2_H
#define COMPLEX2_H

#include <iostream>

class Complex {
    double re, im;
  public:
    Complex() {
      re = im = 0.;
    }
    Complex(double re, double im) {
      this->re = re;
      this->im = im;
    }
    double getRe() const {
      return re;
    }
    void setRe(double re) {
      this->re = re;
    }
    double getIm() const {
      return im;
    }
    void setIm(double im) {
      this->im = im;
    }
    void print() const {
      std::cout << re << '+' << im << 'i' << std::endl;
    }
    // Use reference to avoid copy of 'right'
    Complex operator+(const Complex& right) const {
      return Complex(re + right.re, im + right.im);
    }
    Complex operator*(const Complex& right) const {
      return Complex(re*right.re - im*right.im, im*right.re + re*right.im);
    }
};

#endif
