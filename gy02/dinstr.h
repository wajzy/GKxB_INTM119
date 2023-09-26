#ifndef DINSTR_H
#define DINSTR_H

#include <iostream>
#include <cstring>

class DinStr {
  char* pStr;
  int length;
  int alloc;
public:
  DinStr();
  void print() const;
  inline int getLength() const;
  int getAlloc() const {
    return alloc;
  }
  DinStr& copy(const char* src);
  DinStr& copy(const DinStr& src);
  DinStr& cat(const char* src);
  DinStr& cat(const DinStr& src);
  ~DinStr();
};

inline int DinStr::getLength() const {
  return length;
}

#endif
