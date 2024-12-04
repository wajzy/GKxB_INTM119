#include <iostream>
#include <set>

template<class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& s) {
  for(const auto& item : s) {
    os << item << ' ';
  }
  return os;
}

template<class T>
std::set<T> intersection(const std::set<T>& a, const std::set<T>& b) {
  std::set<T> result;
  for(auto item : a) {
    if(b.find(item) != b.end()) {
      result.insert(item);
    }
  }
  return result;
}

int main() {
  std::set<int> even = { 0, 2, 4, 6, 8, 10 };
  std::cout << "Even numbers: " << even << std::endl;
  
  std::set<int> three;
  for(auto i=0; i<11; i++) {
    three.insert(i);
  }
  for(auto it = three.begin(); it != three.end(); ) {
    if(*it % 3 != 0) {
      it = three.erase(it);
    } else {
      ++it;
    }
  }
  std::cout << "Numbers divisible by three: " << three << std::endl;
  
  std::cout << "Numbers divisable by six: " 
            << intersection(even, three) << std::endl;
}
