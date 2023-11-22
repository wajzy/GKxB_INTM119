#include <iostream>
#include <string>
#include <cctype>

std::string& caesar(std::string& str, int shift) {
  for(auto it=str.begin(); it!=str.end(); it++) {
    if(isalpha(*it)) {
      char alpha = islower(*it) ? 'a' : 'A';
      *it = alpha + (*it-alpha+shift)%('z'-'a'+1);
    }
  }
  return str;
}

int main() {
  int i;
  std::cout << "Enter an integer: ";
  std::cin >> i;
  
  std::string str;
  std::cout << "Enter a line of text: ";
  // getline(std::cin, str); // 'new line' after number cannot be converted
                             // to 'int' and remains in input buffer
  getline(std::cin >> std::ws, str); // clears leading whitespaces
  std::cout << "You've entered: " << i << ", " << str << std::endl;
  
  std::cout << "Capacity of the string is " 
            << str.capacity() << " chars.\n";
  int len = str.length();
  std::cout << "Length of the string is: " << len << " chars.\n";
  const char fillChar = '!';
  str.resize(len+3, fillChar);
  std::cout << "Resized and filled with " << fillChar 
            << ": " << str << std::endl;
  str.resize(len);
  std::cout << "Undo resize: " << str << std::endl;
  std::cout << "Shrinking string... "; 
  str.shrink_to_fit();
  std::cout << "capacity is now " << str.capacity() << " chars.\n";
  
  // to allow usage of the 's' suffix
  using namespace std::string_literals;
  std::cout << "std::string literal length: " 
            << "std::string"s.length() << std::endl;
  // std::string literal("std::string", 11);
  
  std::cout << "Displaying the text char-by-char with constant iterator:\n";
  for(auto it=str.cbegin(); it!=str.cend(); ++it) {
    std::cout << *it;
  }
  std::cout << std::endl;
  std::cout << "Reverse direction:\n";
  for(auto it=str.crbegin(); it!=str.crend(); ++it) {
    std::cout << *it;
  }
  std::cout << std::endl;
  std::cout << "Ciphertext: " << caesar(str, 4) << std::endl;
  std::cout << "Plain text: " << caesar(str, 26-4) << std::endl;
  
  std::cout << "Indices of letter 'e':\n"; 
  for(auto i=str.find("e", 0); i!=std::string::npos; 
      i=str.find("e", i)) { // or try to use rfind()
    std::cout << i++ << ' ';
  }
  std::cout << std::endl;
  std::cout << "First half: " << str.substr(0, str.length()/2) 
            << std::endl;
  str.insert(0, "<"); str.insert(str.length(), ">");
  std::cout << "Inserting: " << str << std::endl;
  str.erase(0, 1); str.erase(str.length()-1);
  std::cout << "Erasing: " << str << std::endl;
}
