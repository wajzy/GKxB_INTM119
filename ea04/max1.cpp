#include <iostream>

// Overloaded max functions
int max(int a, int b) {
  return a > b ? a : b;
}

double max(double a, double b) {
  return a > b ? a : b;
}

int main() {
  const int x = 1;
  const int y = 2;
  std::cout << x << " es " << y << " kozul " 
            << max(x, y) << " a nagyobb.\n";
            
  const double i = 1.5;
  const double j = 2.5;
  std::cout << i << " es " << j << " kozul " 
            << max(i, j) << " a nagyobb.\n";
}
