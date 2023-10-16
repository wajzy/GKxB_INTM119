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
    double getRe() {
      return re;
    }
    void setRe(double re) {
      this->re = re;
    }
    double getIm() {
      return im;
    }
    void setIm(double im) {
      this->im = im;
    }
    void print() {
      std::cout << re << '+' << im << 'i' << std::endl;
    }
    Complex add(Complex right) {
      return Complex(re + right.re, im + right.im);
    }
    Complex mult(Complex right) {
      return Complex(re*right.re - im*right.im, im*right.re + re*right.im);
    }
};

#endif
