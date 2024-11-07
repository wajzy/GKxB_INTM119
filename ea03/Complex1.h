#ifndef COMPLEX1_H
#define COMPLEX1_H

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
    Complex add(Complex right) const {
      return Complex(re + right.re, im + right.im);
    }
    Complex mult(Complex right) const {
      return Complex(re*right.re - im*right.im, im*right.re + re*right.im);
    }
};

#endif
