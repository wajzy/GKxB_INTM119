#include <iostream>

int main() {
  // pointer to constant variable
  const int ci = 1; // must be initialized
  int i = 2;
  const int* pci; // the pointer is NOT constant
  pci = &ci;
  // *pci = 3; // assignment of read-only location '* pci'
  pci = &i;
  // *pci = 3; // read-only access to 'i'
  
  // pointer to variable
  int* pi = &i; // ok
  // pi = &ci; // invalid conversion from 'const int*' to 'int*'
  
  // constant pointer to variable
  int* const cpi = &i; // must be initialized
  *cpi = 3; // OK
  int i2 = 4;
  // cpi = &i2; // assignment of read-only variable 'cpi'
  
  // constant pointer to constant variable
  const int* const cpci = &ci;
  // *cpci = 4; // error
  // cpci = &ci; // error
}
