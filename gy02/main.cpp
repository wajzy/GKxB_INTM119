#include <iostream>
#include "dinstr.h"

int main() {
  DinStr s1, s2, s3;

  s1.print();
  std::cout << "Length of s1 is: " << s1.getLength() << " / " << s1.getAlloc() << std::endl;
  s1.copy("Hello\n");
  s1.print();
  std::cout << "Length of s1 is: " << s1.getLength() << " / " << s1.getAlloc() << std::endl;
  s1.cat("World!\n");
  s1.print();
  std::cout << "Length of s1 is: " << s1.getLength() << " / " << s1.getAlloc() << std::endl;
  /*
  s1.copy("Welcome to ");
  s2.copy(s1);
  s2.cat("the world of ");
  s3.copy("C++ programming!\n");
  s2.cat(s3);
  s2.print();
  std::cout << "Length of s2 is: " << s2.getLength() << " / " << s2.getAlloc() << std::endl;
  */
  s2
    .copy(s1.copy("Welcome to "))
    .cat("the world of ")
    .cat(s3.copy("C++ programming!\n"))
    .print();
  std::cout << "Length of s2 is: " << s2.getLength() << " / " << s2.getAlloc() << std::endl;
}
