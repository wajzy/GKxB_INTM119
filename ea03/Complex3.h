#ifndef COMPLEX3_H
#define COMPLEX3_H

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

    Complex operator+(const Complex& right) const {
      return Complex(re + right.re, im + right.im);
    }
    Complex operator+(double re) const {
      return Complex(this->re + re, im);
    }

    Complex operator*(const Complex& right) const {
      return Complex(re*right.re - im*right.im, im*right.re + re*right.im);
    }
    Complex operator*(double re) const {
      return Complex(this->re*re, this->im*re);
    }
};

#endif
