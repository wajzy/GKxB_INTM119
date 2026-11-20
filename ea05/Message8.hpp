#ifndef MESSAGE8_HPP
#define MESSAGE8_HPP
#include <cstring>
#include <iostream>
#include <stdexcept>
#include "Iterator.hpp"

class Message {
  private:
    char* pStr;
    int len;

  public:
    class const_iterator;

    class iterator : public ::Iterator<char> {
        char* p;
        friend class const_iterator;
      public:
        iterator(char* s) : p(s) {}

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

    class const_iterator : public ::Iterator<const char> {
        const char* p;
      public:
        const_iterator(const char* s) : p(s) {}

        const_iterator(const iterator& it) : p(it.p) {}

        bool operator!=(const ::Iterator<const char>& it) const override {
          return p != static_cast<const const_iterator&>(it).p;
        }

        const_iterator& operator++() override {
          ++p;
          return *this;
        }

        const char& operator*() const override {
          return *p;
        }
    };

    Message() {
      pStr = new char[1]{'\0'};
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

    Message& operator=(const Message& m);

    friend std::ostream& operator<<(std::ostream& os, const Message& m);

    char& operator[](int i) {
      if (i < 0 || i >= len) {
        throw std::out_of_range("Message::operator[]");
      }
      return pStr[i];
    }

    const char& operator[](int i) const {
      if (i < 0 || i >= len) {
        throw std::out_of_range("Message::operator[] const");
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

    const_iterator begin() const {
      return const_iterator(pStr);
    }

    const_iterator end() const {
      return const_iterator(pStr + len);
    }

    const_iterator cbegin() const {
      return const_iterator(pStr);
    }

    const_iterator cend() const {
      return const_iterator(pStr + len);
    }
};

#endif
