#include <iostream>

int i = 1; // global 'i'

namespace A {
  int i = 2; // global 'i' in namespace 'A'
}

int main() {
  int i = 3; // local 'i'
  // access global variable
  std::cout << "global i=" << ::i << std::endl; 
  // access global variable of namespace 'A'
  std::cout << "A/global i=" << A::i << std::endl;
  std::cout << "local i=" << i << std::endl;
}