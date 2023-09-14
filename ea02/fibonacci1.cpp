#include <iostream>

constexpr int fibonacci1(int n) {
  return (n <= 1) ? n : fibonacci1(n-1) + fibonacci1(n-2);
}

int main() {
  constexpr int i = fibonacci1(32);
  std::cout << i << std::endl;
}
