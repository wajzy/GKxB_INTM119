#include <iostream>

class Rectangle {
  public:
    double mWidth; // bad idea
    const double mHeight;
  
    Rectangle(double width, double height) : mHeight(height) {
      mWidth = width;
    }

    double getArea() const {
      return mWidth * mHeight;
    }

    double getPerimeter() /* const */ {
      return 2. * (mWidth + mHeight);
    };
};

int main() {
  const Rectangle r1(5., 3.);
  // r1.mWidth = 55.; // assignment of member 'Rectangle::mWidth' in 
  std::cout << "Area: " << r1.getArea() << std::endl; // read-only object
  // std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
  // passing 'const Rectangle' as 'this' argument discards qualifiers
}
