#include <iostream>
#include <cctype>
#include "Message8.hpp"
#include "LinkedList2.hpp"

void printMessage(const Message& cm) {
  for (char c : cm) {
    std::cout << c;
  }
  std::cout << '\n';
}

template<typename T>
void printList(const LinkedList<T>& cl) {
  for (const auto& item : cl) {
    std::cout << item << ' ';
  }
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
  std::cout << "Spaces --> underscores (range-based loop): " << msg << '\n';
  std::cout << "printMessage works: ";
  // It works thanks to overloaded begin()/end() const
  printMessage(msg);

  std::cout << "Explicit usage of cbegin()/cend(): ";
  for (Message::const_iterator it = msg.cbegin(); it != msg.cend(); ++it) {
    // *it = 'x'; // error: assignment of read-only location
    std::cout << *it;
  }
  std::cout << '\n';

  Message::iterator it = msg.begin();
  Message::const_iterator constIt = it;
  std::cout << "1st char accessed via const iterator: " << *constIt << "\n\n";

  LinkedList<int> numbers;
  numbers.push_back(10);
  numbers.push_back(20);
  numbers.push_back(30);

  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    *it *= 2;
  }
  std::cout << "Doubled values (iterator-based loop): ";
  printList(numbers);

  std::cout << "Explicit usage of cbegin()/cend(): ";
  for (auto it = numbers.cbegin(); it != numbers.cend(); ++it) {
    // *it = 999; // error: assignment of read-only location
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  return 0;
}
