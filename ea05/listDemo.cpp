#include <iostream>
#include <list>

template<class T>
void printForward(const std::list<T>& l) {
  for(auto i=l.cbegin(); i!=l.cend(); i++) {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::list<int> l = { 2, 3, 4 };
  l.push_front(1); l.push_back(5);
  for(auto& i : l) {
    i *= i;
  }
  l.insert(l.end(), 6*6);
  std::list<int>::iterator it = l.end(); advance(it, -l.size());
  l.insert(it, 0);
  std::cout << "Square numbers: "; printForward(l);
  l.reverse();
  std::cout << "In reverse order: "; printForward(l);
  l.sort();
  std::cout << "After sorting: "; printForward(l);
  std::list<int> l2 { -3, -2, -2, -2, -1 }; l.merge(l2);
  std::cout << "After merging: "; printForward(l);
  std::cout << "Is l2 empty? " << (l2.empty() ? "Yes" : "No");
  l.unique(); 
  std::cout << "\nRemoved duplicates: "; printForward(l);
  return 0;
}
