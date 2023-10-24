#include <iostream>

template<class T> T max(T a, T b) {
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
            
  //const int k = 3;
  //const double l = 4.5;
  //std::cout << k << " es " << l << " kozul " 
  //          << max(k, l) << " a nagyobb.\n";
  // error: no matching function for call to 
  // 'max(const int&, const double&)'
  // note: candidate: template<class T> T max(T, T)
  // note: template argument deduction/substitution failed:
  // note: deduced conflicting types for parameter 'T' ('int' and 'double')
}
