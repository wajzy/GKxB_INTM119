#include <iostream>
#include <cmath>

class Point {
  public:
    const double x;
    const double y;
    
    Point(double x, double y) : x(x), y(y) {} 
};

class Rectangle {
    Point ul;
    Point br;
  
  public:
    Rectangle(Point ul, Point br) : ul(ul), br(br) {}

    double getArea() const {
      return abs(ul.x - br.x) * abs(ul.y - br.y);
    }

    double getPerimeter() const {
      return 2. * (abs(ul.x - br.x) + abs(ul.y - br.y));
    };
};

int main() {
  Rectangle r1(Point(0, 3), Point(5, 0));
  std::cout << "Area: " << r1.getArea() << std::endl;
  std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
}
