#include <iostream>

template<typename T1, typename T2> 
T1 max(T1 a, T2 b) {
  return a > b ? a : b;
}

int main() {
  const int i = 3;
  const double d = 4.5;
  std::cout << "Of " << i << " and " << d << ", " 
            << max(i, d) << " is greater.\n";
  std::cout << "Of " << d << " and " << i << ", " 
            << max(d, i) << " is greater.\n";
}
