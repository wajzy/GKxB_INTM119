#include <iostream>

void fn() {
  try {
    std::cout << "Do you want to throw an exception of type int? ";
    std::string answer;
    std::cin >> answer;
    if(answer == "y") throw 1;
    throw 1.2;
  } catch(double) {
    std::cout << "Caught a double.\n";
  }
}

int main() {
  try {
    fn();
    try {
      std::cout << "Do you want to throw an exception of type char? ";
      std::string answer;
      std::cin >> answer;
      if(answer == "y") throw 'a';
      throw "message";
    } catch(char) {
      std::cout << "Caught a char.\n";
    }
  } catch(int) {
    std::cout << "Caught an int.\n";
  } catch(const char*) {
    std::cout << "Caught a pointer to char.\n";
  }
}
