#include <iostream>

int main() {
  // reference to constant variable
  const int ci = 1;
  int i = 2;
  const int& rci = ci; // references must be initialized
  // rci = 3; // assignment of read-only reference 'rci'
  const int& rci2 = i; // read-only acces to 'i'
  // rci2 = 3; // assignment of read-only reference 'rci2'
  const int& rci3 = 3; // OK
  
  // constant reference to a variable - all references are constant by nature
  // int& const cri = i; // 'const' qualifiers cannot be applied to 'int&'
  
  // reference to a const variable
  // int& ri = ci; // binding reference of type 'int&' to 'const int' discards qualifiers
}
