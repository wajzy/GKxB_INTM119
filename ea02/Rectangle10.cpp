#include <iostream>

class Rectangle {
    double mWidth;
    double mHeight;
  public:
    constexpr Rectangle(double width, double height) : 
      mWidth(width), mHeight(height) {}

    constexpr double getArea() const {
      return mWidth * mHeight;
    }

    constexpr double getPerimeter() const {
      return 2. * (mWidth + mHeight);
    };
};

int main() {
  const int width = 5.;
  constexpr Rectangle r1(width, 3.);
  std::cout << "Area: " << r1.getArea() << std::endl;
  std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
}
