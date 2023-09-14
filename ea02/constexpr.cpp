#include <iostream>

constexpr double PI = 3.14159;
constexpr double deg2rad(double degree) {
  return degree * PI / 180.;
}

int main() {
  constexpr double rightAngle = deg2rad(90.);
  std::cout << rightAngle << std::endl;
  int deg180 = 180;
  // the value of 'deg180' is not usable in a constant expression
  // constexpr double rad180 = deg2rad(deg180);
  double rad180 = deg2rad(deg180); // OK
  std::cout << rad180 << std::endl;
  return 0;
}
