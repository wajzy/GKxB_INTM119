#include <iostream>
#include <deque>

template<class T>
void printForward(const std::deque<T>& dq) {
  for(auto i=dq.cbegin(); i!=dq.cend(); i++) {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::deque<int> dq;
  dq.push_back(4);
  dq.push_front(2);
  dq.push_back(8);
  dq.push_front(1);
  printForward(dq);
  
  dq.pop_front(); dq.pop_back();
  printForward(dq);
  return 0;
}
