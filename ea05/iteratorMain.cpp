#include <iostream>
#include "Message5.h"
#include "LinkedList.h"

int main() {
  Message m = "Hello C++ world!";

  // using iterator
  for (auto i = m.begin(); i != m.end(); ++i) {
    std::cout << *i;
  }
  std::cout << std::endl;

  // range-based for loop, C++11
  for (const auto& c : m) {
    std::cout << c;
  }
  std::cout << std::endl;

  // operator[]
  try {
    for (auto i = 0; i <= m.length(); i++) {
      std::cout << m[i];
    }
  } catch(const std::out_of_range& e) {
    std::cerr << "\nException caught: " << e.what() << std::endl;
  }
  
  LinkedList<int> l;
  l.append(1); l.append(2); l.append(3);
  for (auto i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << '\t';
  }
  std::cout << std::endl;
}

// postfix alak: virtual Iterator operator++(int) = 0; -> de absztrakt osztályt nem lehet példányosítani, így a visszatérési érték típusa nem lehet Iterator
// https://en.cppreference.com/w/cpp/language/override
// static_cast -> nincs ellenőrzés; dynamic_cast bad_cast kivételt dobhat
// range-based for loop: https://en.cppreference.com/w/cpp/language/range-for
// out_of_range: https://en.cppreference.com/w/cpp/error/out_of_range
// iterátorok hierarchiája, operátorok: https://cplusplus.com/reference/iterator/
