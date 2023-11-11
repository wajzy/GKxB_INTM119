#include "Message5.h"

Message& Message::operator=(const Message& m) {
  if(&m == this) return *this;
  delete[] pStr;
  len = strlen(m.pStr);
  pStr = new char[len + 1];
  strcpy(pStr, m.pStr);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Message& m) {
  os << m.pStr;
  return os;
}
