#include <iostream>

struct Rectangle {
  private:
    double mWidth; // m -> member, indicating private data
    double mHeight;
  public:
    // it is not necessary to refer to r
    void init(double width, double height) {
      mWidth = width;
      mHeight = height;
    }

    // member function's name does not contain the name of the 
    // type (Rect[angle]); it is obvious because of *encapsulation*
    // const -> the function cannot modify any data
    double getArea() const {
      // error: cannot assign to non-static data member within 
      // const member function 'getArea'
      // mWidth = 1.;
      return mWidth * mHeight;
    }
    
    double getPerimeter() const {
      return 2. * (mWidth + mHeight);
    }
    
    void print() const {
      std::cout << "Rectangle[dimensions: " 
                << mWidth << " x " << mHeight << "]" 
                << std::endl;
    }
};

int main() {
  Rectangle r1;
  r1.init(5., 3.); // calling *member functions*
  r1.print();
  // error: 'mWidth' is a private member of 'Rectangle'
  // r1.mWidth = 4.5; // data IS hidden
  std::cout << "Area: " << r1.getArea() << std::endl;
  std::cout << "Perimeter: " << r1.getPerimeter() << std::endl;
}