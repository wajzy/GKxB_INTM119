class A {
  public:
    int i; // -> diamond problem in D
};

class B : public A {
  public:
    int j; // -> name collision in D
};

class C : public A {
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
    obj.i = 42; // diamond problem
    obj.j = 2;  // name collision
    return 0;
}
