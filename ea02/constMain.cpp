#include <iostream>
#include "constHeader.h"
#define MEANING_M 42 // no type, cumbersome debugging

void array(int);

int main() {
  const int MEANING = 42;
  int meaningCopy = MEANING; // read
  // MEANING++; // error
  // MEANING = -42; // error
  // size expressed with constant expression
  int oldArray1[MEANING_M * sizeof(double)]; // OK
  int oldArray2[MEANING * sizeof(double)]; // OK
  array(21);
  // std::cout << i << std::endl; // error
  std::cout << ci << std::endl; // OK
  std::cout << si << std::endl; // OK
}

void array(int size) {
  // C99+ / C++14+ -> variable size is OK, allocated on stack
  int newArray[size * sizeof(double)];
}
