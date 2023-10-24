#include <iostream>
#include "Stack.h"

int main() {
  Stack<int, 3> si;
  si.push(1); si.push(2); si.push(3);
  si.push(4); // stack full
  while(not si.isEmpty()) {
    std::cout << si.pop() << std::endl;
  }
  
  Stack<const char*, 10> scp;
  scp.push("World!\n"); scp.push("Hello ");
  std::cout << scp.pop();
  std::cout << scp.pop();
  std::cout << scp.pop(); // stack empty
}
