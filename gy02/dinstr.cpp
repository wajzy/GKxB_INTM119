#include "dinstr.h"

DinStr::DinStr(){
  alloc = 8;
  pStr = new char[alloc];
  *pStr = '\0';
  length = 0;
}

void DinStr::print() const {
  std::cout << pStr;
}

DinStr& DinStr::copy(const char* src) {
  int sLength = strlen(src);
  int incAlloc = alloc;
  while(incAlloc < sLength + 1) {
    incAlloc *= 2;
  }
  if(incAlloc > alloc) {
    delete[] pStr;
    pStr = new char[incAlloc];
    alloc = incAlloc;
  }

  strcpy(pStr, src);
  length = sLength;

  return *this;
}

DinStr& DinStr::copy(const DinStr& src) {
  int incAlloc = alloc;
  while(incAlloc < src.length + 1) {
    incAlloc *= 2;
  }
  if(incAlloc > alloc) {
    delete[] pStr;
    pStr = new char[incAlloc];
    alloc = incAlloc;
  }

  strcpy(pStr, src.pStr);
  length = src.length;

  return *this;
}

DinStr& DinStr::cat(const char* src) {
  int incLength = length + strlen(src);
  int incAlloc = alloc;
  while(incAlloc < incLength + 1) {
    incAlloc *= 2;
  }
  if(incAlloc > alloc) {
    char* incStr = new char[incAlloc];
    strcpy(incStr, pStr);
    delete[] pStr;
    pStr = incStr;
    alloc = incAlloc;
  }

  strcat(pStr, src);
  length = incLength;

  return *this;
}

DinStr& DinStr::cat(const DinStr& src) {
  int incLength = length + src.length;
  int incAlloc = alloc;
  while(incAlloc < incLength + 1) {
    incAlloc *= 2;
  }
  if(incAlloc > alloc) {
    char* incStr = new char[incAlloc];
    strcpy(incStr, pStr);
    delete[] pStr;
    pStr = incStr;
    alloc = incAlloc;
  }

  strcat(pStr, src.pStr);
  length = incLength;

  return *this;
}

DinStr::~DinStr() {
  delete[] pStr;
}
