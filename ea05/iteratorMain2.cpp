#include <iostream>
#include <cctype>
#include "Message7.hpp"
#include "LinkedList.hpp"

// Message::begin() and end() functions are not const
// passing 'const Message' as 'this' argument discards qualifiers
void printConstMessage(const Message& /*cm*/) {
  /*
  for (char c : cm) {
    std::cout << c;
  }
  */
  std::cout << '\n';
}

template<typename T>
void printConstList(const LinkedList<T>& /*cl*/) {
  /*
  for (const auto& item : cl) {
    std::cout << item << " ";
  }
  */
  std::cout << '\n';
}

int main() {
  Message msg = "test message to be modified";
  std::cout << "Original text: " << msg << '\n';
  for (auto it = msg.begin(); it != msg.end(); ++it) {
    *it = std::toupper(*it);
  }
  std::cout << "Lowercase --> uppercase (iterator-based loop): " << msg << '\n';
  for (char& c : msg) {
    if (c == ' ') c = '_';
  }
  std::cout << "Spaces --> underscores (range-based loop): " << msg << "\n\n";

  LinkedList<int> numbers;
  numbers.push_back(10);
  numbers.push_back(20);
  numbers.push_back(30);
  std::cout << "Items of the original list: ";
  for (int n : numbers) {
    std::cout << n << ' ';
  }
  std::cout << '\n';
  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    *it *= 2;
  }
  std::cout << "Doubled values (iterator-based loop): ";
  for (int n : numbers) {
    std::cout << n << ' ';
  }
  std::cout << "\n\n";

  const Message constMsg = "constant message";
  printConstMessage(constMsg);

  const LinkedList<int>& constNumRef = numbers;
  printConstList(constNumRef);

  return 0;
}
