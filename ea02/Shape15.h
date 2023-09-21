#ifndef SHAPE_H
#define SHAPE_H

class Shape {
  protected: // private --> protected
    mutable bool areaCached;
    mutable double area;
    mutable bool perimeterCached;
    mutable double perimeter;
  public:  
    Shape() {
      invalidateCache();
    }
    
    double getArea() const;
    double getPerimeter() const;
  protected: // private --> protected
    // pure virtual
    virtual void calcArea() const = 0;
    virtual void calcPerimeter() const = 0;
    void invalidateCache() {
      areaCached = perimeterCached = false;
    }
};

#endif
