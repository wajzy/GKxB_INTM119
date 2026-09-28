#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
    mutable bool areaCached;
    mutable double area;
    mutable bool perimeterCached;
    mutable double perimeter;
    double mWidth;
    double mHeight;
  
  public:
    Rectangle(double width, double height) {
      setWidth(width);
      setHeight(height);
    }

    double getWidth() const {
      return mWidth;
    }

    void setWidth(double width) {
      mWidth = width;
      invalidateRect();
    }

    double getHeight() const {
      return mHeight;
    }

    void setHeight(double height) {
      mHeight = height;
      invalidateRect();
    }

    double getArea() const;

    double getPerimeter() const;

  private:
    void invalidateRect() const {
      areaCached = perimeterCached = false;
    }
};


#endif
