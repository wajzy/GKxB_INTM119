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
  std::cout << "Of " << x << " and " << y << ", " 
            << max(x, y) << " is greater.\n";
            
  const double i = 1.5;
  const double j = 2.5;
  std::cout << "Of " << i << " and " << j << ", " 
            << max(i, j) << " is greater.\n";
}
