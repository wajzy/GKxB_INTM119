#ifndef COMPLEX4_H
#define COMPLEX4_H

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
    friend std::ostream& operator<<(std::ostream& os, const Complex& cplx);

    Complex operator+(const Complex& right) const {
      return Complex(re + right.re, im + right.im);
    }
    Complex operator+(double re) const {
      return Complex(this->re + re, im);
    }
    friend Complex operator+(double re, const Complex& right);

    Complex operator*(const Complex& right) const {
      return Complex(re*right.re - im*right.im, im*right.re + re*right.im);
    }
    Complex operator*(double re) const {
      return Complex(this->re*re, this->im*re);
    }
    friend Complex operator*(double re, const Complex& right);
};

#endif
