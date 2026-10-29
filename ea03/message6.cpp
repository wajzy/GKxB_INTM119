#include <iostream>
#include <cstring>

class Message {
  private:
    char* pStr;
  public:
    Message() {
      pStr = new char[1]{'\0'};
    }

    Message(const char* s) {
      pStr = new char[strlen(s) + 1];
      strcpy(pStr, s);
    }

    Message(const Message& m) : Message(m.pStr) {}

    ~Message() {
      delete[] pStr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Message& m);

    explicit operator bool() const {
        return pStr != nullptr && pStr[0] != '\0';
    }

    Message& operator=(const Message& m) {
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
  return os << m.pStr;
}

int main() {
  Message m1 = "Important message.";
  if(m1) {
    std::cout << "The 1st message is: " << m1 << '\n';
  } else {
    std::cout << "No 1st message.\n";
  }

  Message m2;
  if(m2) {
    std::cout << "The 2nd message is: " << m2 << '\n';
  } else {
    std::cout << "No 2nd message.\n";
  }

  // error: no match for 'operator+' (operand types are 'Message' and 'Message')
  // int meaningless = m1 + m2;
  // std::cout << "meaningless = " << meaningless << '\n';
}
