#include <iostream>

class Rectangle {
  // private: 
  // this is the default access modifier in case of a 'class'
    double mWidth;
    double mHeight;
  public:
    // member function defined outside the class; 
    // prototype, no parameter name needed
    void init(double, double);

    // member function defined implicitely 'inline'
    double getArea() const {
      return mWidth * mHeight;
    }

    // explicit 'inline' member function -> see definition
    double getPerimeter() const;
    
    void print() const;
};

// type, scope resolution (::), member function name
void Rectangle::init(double width, double height) {
  mWidth = width;
  mHeight = height;
}

// making a function *inline* is only a request, not a command
inline double Rectangle::getPerimeter() const {
  return 2. * (mWidth + mHeight);
}

void Rectangle::print() const {
  std::cout << "Rectangle[dimensions: " 
            << mWidth << " x " << mHeight << "]" 
            << std::endl;
}

int main() {
  Rectangle r1;
  r1.init(5., 3.);
  r1.print();
  std::cout << "Area: " << r1.getArea() << std::endl;
  std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
}