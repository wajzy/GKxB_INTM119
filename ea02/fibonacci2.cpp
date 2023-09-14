#include <iostream>

int fibonacci2(int n) {
  return (n <= 1) ? n : fibonacci2(n-1) + fibonacci2(n-2);
}

int main() {
  int i = fibonacci2(32);
  std::cout << i << std::endl;
}
