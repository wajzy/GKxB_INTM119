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

    ~Message() {
      std::cout << "Freed [" << this << ", " << pStr << "]\n";
      delete[] pStr;
    }

    void print() {
      std::cout << pStr;
    }

    void setMessage(const char* s) {
      delete[] pStr;
      pStr = new char[strlen(s) + 1];
      strcpy(pStr, s);
    }
};

int main() {
  Message m1;
  m1.setMessage("Hello C++ world!\n");
  m1.print();

  Message* pm1 = new Message("Object on heap.");
  delete pm1;

  Message aMessages[] = {"alpha", "beta"};

  // using default constructor
  Message* pMessages = new Message[3];
  delete[] pMessages;
}