class A {
  public:
    int i;
};

class B : public A {
  public:
    int j;
};

class C : public A {
  public:
    int j;
};

// multiple inheritance
class D : public B, public C {
  public:
    int k;
};

int main(){
    D obj;
    obj.i = 42;
    return 0;
}
