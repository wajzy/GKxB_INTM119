#include <iostream>
#include <map>

template<class K, class V>
void printForward(const std::map<K, V>& m) {
  for(auto i=m.cbegin(); i!=m.cend(); i++) {
    std::cout << i->first << '\t' << i->second << std::endl;
  }
}

int main() {
  std::map<std::string, int> students;
  students["Johnny"] = 3;
  students["Johnny"] = 5; // no duplicated keys
  students.insert(std::pair<std::string, int>("Jenny", 4));
  students.erase("Tommy"); // does nothing
  std::cout << "Stored pairs:\n"; printForward(students);
  std::cout << "Is Eva present? " 
            << (students.find("Eva")==students.end() ? "No" : "Yes");
  return 0;
}
