#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>

class Triangle {
    mutable bool areaCached;
    mutable double area;
    mutable bool perimeterCached;
    mutable double perimeter;
    double mA, mB, mC;
  public:  
    Triangle(
      double a, double b, double c) {
      mA = a; mB = b; mC = c;
      invalidateCache();
    }

    void setA(double a);
    void setB(double b);
    void setC(double c);
    double getArea() const;
    double getPerimeter() const;
  private:
    // called from getArea(), 
    // must be const
    void calcArea() const;
    void calcPerimeter() const;
    
    void invalidateCache() {
      areaCached = perimeterCached 
        = false;
    }
};

#endif
