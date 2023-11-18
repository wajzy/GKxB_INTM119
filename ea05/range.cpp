#include <iostream>

int main() {
  int array[] = {1, 2, 3};
  for(const auto& i : array) { // reference
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  
  for(auto i : array) { // value
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  
  for(auto i : {4, 5, 6}) { // braced-init-list
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  
  std::string text = "C++ is so cool!\n";
  // explicit iterator usage
  for(auto i=text.begin(); i!=text.end(); ++i) {
    std::cout << *i;
  }
  
  // implicit iterator usage, range-based for loop
  for(const auto& c : text) {
    std::cout << c;
  }
  
  // overloaded [] operator
  for(size_t i=0; i<text.length(); ++i) {
    std::cout << text[i];
  }
  
  // random access iterator
  auto it = text.begin();
  for(size_t i=0; i<text.length(); ++i) {
    std::cout << it[i];
  }
}
