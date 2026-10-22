#include <iostream>

class A {
  public:
    int i; // -> diamond problem in D
};

class B : virtual public A {
  public:
    int j; // -> name collision in D
};

class C : virtual public A {
  public:
    int j; // -> name collision in D
};

// multiple inheritance
class D : public B, public C {
  public:
    int k;
};

int main() {
    D obj;
    obj.i = 42;   // diamond problem solved by 'virtual' inheritance
    obj.B::j = 2; // name collision solved by scope resolution operator
    obj.C::j = 3;

    // 'i' is indeed a single shared memory area from A:
    std::cout << "obj.i    = " << obj.i    << " (at: " << &obj.i    << ")\n";
    std::cout << "obj.B::i = " << obj.B::i << " (at: " << &obj.B::i << ")\n";
    std::cout << "obj.C::i = " << obj.C::i << " (at: " << &obj.C::i << ")\n";

    // 'j's, however, remained independent (B::j and C::j):
    std::cout << "obj.B::j = " << obj.B::j << " (at: " << &obj.B::j << ")\n";
    std::cout << "obj.C::j = " << obj.C::j << " (at: " << &obj.C::j << ")\n";
    return 0;
}
