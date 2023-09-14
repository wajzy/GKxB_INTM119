#include <iostream>

void pfn(int* pi) {
  *pi *= 2;
}

void rfn(int& ri) {
  ri *= 2;
}

void pcfn(const int* pi) {
  // *pi *= 2; // assignment of read-only location '* pi'
}

void rcfn(const int& ri) {
  // ri *= 2; // assignment of read-only reference 'ri'
}

int* fnp() {
  static int si = 10;
  return &si;
}

const int* fncp() {
  static int si = 20;
  return &si;
}

int& fnr() {
  static int si = 30;
  return si;
}

const int& fncr() {
  static int si = 40;
  return si;
}

int main() {
  int i = 1;
  pfn(&i);
  rfn(i);
  std::cout << i << std::endl;
  const int ci = 5;
  // rfn(ci); // binding reference of type 'int&' to 'const int' discards...
  rcfn(ci); rcfn(5); pcfn(&i); pcfn(&ci); // ok
  *fnp() = 11;
  // *fncp() = 21; // assignment of read-only location '* fncp()'
  fnr() = 31;
  // fncr() = 41; // assignment of read-only location 'fncr()'
}

