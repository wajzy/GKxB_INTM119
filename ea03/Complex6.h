#ifndef COMPLEX6_H
#define COMPLEX6_H

#include <iostream>

class Complex {
    double re, im;
  public:
    // explicitely defaulted constructor
    Complex() = default;
    // conversion constructor
    Complex(double re, double im = 0.) {
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
    friend std::ostream& operator<<(std::ostream& os, const Complex& cplx);
    friend Complex operator+(const Complex& left, const Complex& right);
    friend Complex operator*(const Complex& left, const Complex& right);
};

#endif
