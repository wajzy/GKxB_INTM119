#include <iostream>
#include <vector>

template<class T>
void printForward(const std::vector<T>& v) {
  for(auto i=v.begin(); i!=v.end(); i++) {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> iv1 = {1, 2, 3, 4, 5}; // initializer list
  for(const auto& i : iv1) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  
  std::vector<int> iv2 {6, 7, 8, 9, 10}; // uniform initialization
  for(const auto& i : iv2) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  
  std::vector<int> iv3(5, 42); // constructor #1
  for(auto i = iv3.cbegin(); i!=iv3.cend(); ++i) {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;
  
  std::vector<int> iv4(5); // constructor #2
  for(size_t i=0; i<iv4.size(); i++) {
    std::cout << iv4[i] << ' ';
  }
  std::cout << std::endl;
  
  std::vector<int> iv5; // constructor #3
  iv5.push_back(11); iv5.push_back(12); iv5.push_back(13);
  for(size_t i=0; i<iv5.size(); i++) {
    std::cout << iv5.at(i) << ' ';
  }
  std::cout << std::endl;
  
  // 2x3 matrix of 1's
  std::vector<std::vector<int>> im1(2, std::vector<int>(3, 1));
  for(const auto& r : im1) {
    for(const auto& c : r) {
      std::cout << c << ' ';
    }
    std::cout << std::endl;
  }
  
  std::vector<int> iv6 = {1, 2, 3, 4, 5};
  std::cout << "Size of iv6: " << iv6.size() << std::endl;
  std::cout << "Capacity: " << iv6.capacity() << std::endl;
  std::cout << "Reserving memory... "; iv6.reserve(16); 
  std::cout << "Capacity: " << iv6.capacity() << std::endl;
  std::cout << "Is it empty? " << (iv6.empty() ? "Yes" : "No") << std::endl;
  std::cout << "Shrinking... "; iv6.resize(3); printForward(iv6);
  std::cout << "Growing... "; iv6.resize(6); printForward(iv6);
  std::cout << "Further growing... "; iv6.resize(9, -1); printForward(iv6);
  std::cout << "Shrinking... "; iv6.shrink_to_fit();
  std::cout << "Capacity: " << iv6.capacity() << std::endl;
  
  std::cout << "First element: " << iv6.front() << std::endl;
  std::cout << "Last element: " << iv6.back() << std::endl;
  std::cout << "Element at idx. 1: " << iv6[1] << std::endl;
  std::cout << "Element at idx. 2: " << iv6.at(2) << std::endl;
  std::cout << "Elements in reverse order (using pointers): ";
  for(const int* pi = iv6.data()+iv6.size()-1; pi>=iv6.data(); pi--) {
    std::cout << *pi << ' ';
  }
  std::cout << "\nElements in reverse order (using rev. it.): ";
  for(std::vector<int>::const_reverse_iterator i = iv6.crbegin(); 
      i!=iv6.crend(); i++) {
    std::cout << *i << ' ';
  }
  std::cout << std::endl;
  
  std::vector<int> iv7;
  std::cout << "Assigning... "; iv7.assign(3, 1); printForward(iv7);
  std::cout << "Pushing... "; iv7.push_back(2); printForward(iv7);
  std::cout << "Popping... "; iv7.pop_back(); printForward(iv7);
  std::cout << "Inserting... "; iv7.insert(iv7.end(), 2); printForward(iv7);
  std::cout << "Erasing... "; iv7.erase(iv7.end()-1); printForward(iv7);
  std::cout << "Swapping vectors...\n"; iv7.swap(iv6);
  std::cout << "\tiv7: "; printForward(iv7);
  std::cout << "\tiv6: "; printForward(iv6);
  return 0;
}
