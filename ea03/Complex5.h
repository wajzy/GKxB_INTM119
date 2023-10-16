#ifndef COMPLEX5_H
#define COMPLEX5_H

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
    friend std::ostream& operator<<(std::ostream& os, const Complex& cplx);

    friend Complex operator+(const Complex& left, const Complex& right);
    friend Complex operator+(const Complex& left, double re);
    friend Complex operator+(double re, const Complex& right);

    friend Complex operator*(const Complex& left, const Complex& right);
    friend Complex operator*(const Complex& left, double re);
    friend Complex operator*(double re, const Complex& right);
};

#endif
