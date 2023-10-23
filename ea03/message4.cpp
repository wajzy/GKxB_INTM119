#include <iostream>
#include <cstring>

class Message {
  private:
    char* pStr;
  public:
    Message() {
      pStr = new char('\0');
      std::cout << "Created [" << this << "]\n";
    }

    Message(const char* s) { // conversion ctor
      pStr = new char[strlen(s) + 1];
      strcpy(pStr, s);
      std::cout << "Created [" << this << ", " << pStr << "]\n";
    }

    // C++11: deleted constructor
    Message(const Message& m) = delete;

    ~Message() {
      std::cout << "Freed [" << this << ", " << pStr << "]\n";
      delete[] pStr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Message& m);

    // deleted assignment operator
    Message& operator=(const Message& m) = delete;

    void setMessage(const char* s) {
      delete[] pStr;
      pStr = new char[strlen(s) + 1];
      strcpy(pStr, s);
    }
};

std::ostream& operator<<(std::ostream& os, const Message& m) {
  os << m.pStr;
  return os;
}

int main() {
  Message m1;
  m1.setMessage("Hello C++ world!");
  std::cout << m1 << std::endl;

  Message m2;
  // m2 = m1; error: use of deleted function 
  // 'Message& Message::operator=(const Message&)'

  // Message m4 = m1; error: use of deleted function
  // 'Message::Message(const Message&)'
  
  // Message m6 = "Conversion + copy ctor"; error: use of deleted function 
  // 'Message::Message(const Message&)'
  // after user-defined conversion: Message::Message(const char*)
  
  Message m7("Conversion ctor"); // OK
}
