#include <iostream>

int main() {
  std::cout << "Please enter a number: ";
  int number;
  if(std::cin >> number) {
    std::cout << "The entered number is: " << number << std::endl;
  } else {
    std::cout << "Something went wrong.\n";
  }
}