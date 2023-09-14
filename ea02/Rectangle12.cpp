#include <iostream>

class Rectangle {
    mutable bool areaCached;
    mutable double area;
    mutable bool perimeterCached;
    mutable double perimeter;
  public:
    const double mWidth;
    const double mHeight;
  
    Rectangle(double width, double height) : mWidth(width), mHeight(height) {
      areaCached = perimeterCached = false;
    }

    double getArea() const {
      if(not areaCached) {
        area = mWidth * mHeight;
        areaCached = true;
      }
      return area;
    }

    double getPerimeter() const {
      if(not perimeterCached) {
        perimeter = 2. * (mWidth + mHeight);
        perimeterCached = true;
      }
      return perimeter;
    };
};

int main() {
  const Rectangle r1(5., 3.);
  std::cout << "Area: " << r1.getArea() << std::endl;
  std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
}
