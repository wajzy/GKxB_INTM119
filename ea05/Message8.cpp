#include "Message8.hpp"

Message& Message::operator=(const Message& m) {
  if (&m == this) return *this;
  delete[] pStr;
  pStr = new char[strlen(m.pStr) + 1];
  strcpy(pStr, m.pStr);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Message& m) {
  return os << m.pStr;
}
