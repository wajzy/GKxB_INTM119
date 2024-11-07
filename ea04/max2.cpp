#include <iostream>

template<class T> T max(T a, T b) {
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
            
  // const int k = 3;
  // const double l = 4.5;
  // std::cout << "Of " << k << " and " << l << ", " 
  //           << max(k, l) << " is greater.\n";
  // error: no matching function for call to 
  // 'max(const int&, const double&)'
  // note: candidate: template<class T> T max(T, T)
  // note: template argument deduction/substitution failed:
  // note: deduced conflicting types for parameter 'T' ('int' and 'double')
}
