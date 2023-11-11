#ifndef MESSAGE_H
#define MESSAGE_H
#include <cstring>
#include <stdexcept>
#include "Iterator.h"

class MessageIterator : public Iterator<char> {
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
    int len;
  public:
    Message() {
      pStr = new char('\0');
      len = 0;
    }

    Message(const char* s) {
      len = strlen(s);
      pStr = new char[len + 1];
      strcpy(pStr, s);
    }

    Message(const Message& m) : Message(m.pStr) {}

    ~Message() {
      delete[] pStr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Message& m);

    Message& operator=(const Message& m);

    MessageIterator begin() {
      return MessageIterator(pStr);
    }

    MessageIterator end() {
      return MessageIterator(pStr + len);
    }
    
    int length() {
      return len;
    }
    
    char& operator[](int i) {
      if (i < 0 || i >= len) {
        throw std::out_of_range("Message::operator[]");
      }
      return pStr[i];
    }
};

#endif
