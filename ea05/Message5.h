#ifndef MESSAGE_H
#define MESSAGE_H
#include <cstring>
#include <stdexcept>
#include "Iterator.h"

class MessageIterator : public Iterator<char> {
    char* p;
  public:
    MessageIterator(char* s) {
      p = s;
    }
    
    bool operator!=(const Iterator<char>& it) const override {
      return p != static_cast<const MessageIterator&>(it).p;
    }
    
    MessageIterator& operator++() override {
      ++p;
      return *this;
    }
        
    char& operator*() const override {
      return *p;
    }
};

class Message {
  private:
    char* pStr;
    int len; // The length of str is also stored
  public:
    Message() { // default ctor
      pStr = new char('\0');
      len = 0;
    }

    Message(const char* s) { // conversion ctor
      len = strlen(s);
      pStr = new char[len + 1];
      strcpy(pStr, s);
    }

    Message(const Message& m) : Message(m.pStr) {} // copy ctor

    ~Message() { // dtor
      delete[] pStr;
    }

    Message& operator=(const Message& m); // assignment op.

    friend std::ostream& operator<<(std::ostream& os, const Message& m);
    
    char& operator[](int i) {
      if (i < 0 || i >= len) {
        throw std::out_of_range("Message::operator[]");
      }
      return pStr[i];
    }

    int length() const {
      return len;
    }

    MessageIterator begin() const {
      return MessageIterator(pStr);
    }

    MessageIterator end() const {
      return MessageIterator(pStr + len);
    }
};

#endif
