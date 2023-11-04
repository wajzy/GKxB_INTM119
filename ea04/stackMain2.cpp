#include <iostream>
#include "Stack2.h"

int main() {
  Stack<int, 3> si;
  try {
    si.push(1); si.push(2); si.push(3);
    si.push(4);
  } catch(const StackException& se) {
    std::cerr << "Error code: " << se.getCode() 
              << ", " << se.what() 
              << std::endl;
  }
  while(not si.isEmpty()) {
    std::cout << si.pop() << std::endl;
  }
  
  Stack<const char*, 10> scp;
  scp.push("World!\n"); scp.push("Hello ");
  try {
    std::cout << scp.pop();
    std::cout << scp.pop();
    std::cout << scp.pop();
  } catch(const StackException& se) {
    std::cerr << "Error code: " << se.getCode() 
              << ", " << se.what() 
              << std::endl;
  }
}
