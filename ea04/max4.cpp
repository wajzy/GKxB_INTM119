#include <iostream>

template<class T1, class T2> T1 max(T1 a, T2 b) {
  return a > b ? a : b;
}

double max(int a, double b) {
  return a > b ? a : b;
}

int main() {
  const int i = 3;
  const double d = 4.5;
  std::cout << i << " es " << d << " kozul " 
            << max(i, d) << " a nagyobb.\n";
  std::cout << d << " es " << i << " kozul " 
            << max(d, i) << " a nagyobb.\n";
}
