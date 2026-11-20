#ifndef MESSAGE7_HPP
#define MESSAGE7_HPP
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "Iterator.hpp"

class Message {
  private:
    char* pStr;
    int len; // The length of str is also stored

  public:
    // The class name is intentionally written 
    // with a lowercase initial letter.
    class iterator : public ::Iterator<char> {
        char* p;
      public:
        iterator(char* s) {
          p = s;
        }

        bool operator!=(const ::Iterator<char>& it) const override {
          return p != static_cast<const iterator&>(it).p;
        }

        iterator& operator++() override {
          ++p;
          return *this;
        }

        char& operator*() const override {
          return *p;
        }
    };

    Message() { // default ctor
      pStr = new char[1]{'\0'};
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

    iterator begin() {
      return iterator(pStr);
    }

    iterator end() {
      return iterator(pStr + len);
    }
};

#endif
