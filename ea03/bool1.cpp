#include <iostream>

int main() {
  std::cout << "Please enter a number: ";
  int number;
  std::cin >> number;
  if(std::cin.fail()) {
    std::cout << "Something went wrong.\n";
  } else {
    std::cout << "The entered number is: " << number << std::endl;
  }
}