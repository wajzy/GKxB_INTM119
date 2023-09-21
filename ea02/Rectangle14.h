#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    mutable bool areaCached;
    mutable double area;
    mutable bool perimeterCached;
    mutable double perimeter;
    double mWidth;
    double mHeight;
  public:  
    Rectangle(double width, double height) {
      mWidth = width;
      mHeight = height;
      invalidateCache();
    }
    
    void setWidth(double width);
    void setHeight(double height);
    double getArea() const;
    double getPerimeter() const;
  private:
    // called from getArea(), must be const
    void calcArea() const;
    void calcPerimeter() const;
    
    void invalidateCache() {
      areaCached = perimeterCached = false;
    }
};

#endif
