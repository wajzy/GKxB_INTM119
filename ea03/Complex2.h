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
    // Use reference to avoid copy of 'right'
    Complex operator+(const Complex& right) {
      return Complex(re + right.re, im + right.im);
    }
    Complex operator*(const Complex& right) {
      return Complex(re*right.re - im*right.im, im*right.re + re*right.im);
    }
};

#endif
