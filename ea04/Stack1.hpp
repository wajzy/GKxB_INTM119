#ifndef STACK1_HPP
#define STACK1_HPP

#include <iostream>

template<typename T, int I> class Stack {
    T array[I];
    int used;
  public:
    Stack() : used(0) {}
    void push(T data);
    T pop() {
      if(used > 0) {
        return array[--used];
      } else {
        std::cerr << "Oops, the stack is empty.\n";
        return array[0]; // something must be returned
      }
    }
    bool isEmpty() const {
      return used == 0;
    }
};

// It MUST be in the header!
template<typename T, int I> void Stack<T, I>::push(T data) {
  if(used < I) {
    array[used++] = data;
  } else {
    std::cerr << "Stack full :(\n";
  }
}

#endif
