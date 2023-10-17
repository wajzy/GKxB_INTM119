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

    Message(const char* s) {
      pStr = new char[strlen(s) + 1];
      strcpy(pStr, s);
      std::cout << "Created [" << this << ", " << pStr << "]\n";
    }

    /* for old compilers
    Message(const Message& m) {
      pStr = new char[strlen(m.pStr) + 1];
      strcpy(pStr, m.pStr);
      std::cout << "Created [" << this << "]\n";
    } */

    // C++11+ / delegating constructors
    Message(const Message& m) : Message(m.pStr) {}

    ~Message() {
      std::cout << "Freed [" << this << ", " << pStr << "]\n";
      delete[] pStr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Message& m);

    // return reference instead of void to allow multiple assignments
    Message& operator=(const Message& m) {
      // do not copy to itself
      if(&m == this) return *this;
      setMessage(m.pStr);
      return *this;
    }

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
  m2 = m1;
  std::cout << m2 << std::endl;

  Message m3;
  m3 = m2 = m1;
  std::cout << m2 << std::endl;

  m1 = m1;
  std::cout << m1 << std::endl;

  Message m4 = m1; // calls copy constructor
  std::cout << m4 << std::endl;
  Message m5(m1); // calls copy constructor
  std::cout << m5 << std::endl;
  Message m6 = "Conversion ctor";
  Message m7("Conversion ctor");
}
