#ifndef STACK_H
#define STACK_H

#include <iostream>

template<class T, int I> class Stack {
    T* array;
    const int size;
    int used;
  public:
    Stack() : size(I) {
      array = new T[I];
      used = 0;
    }
    void push(T data);
    T pop() {
      if(used > 0) {
        return array[--used];
      } else {
        std::cerr << "Oops, the stack is empty.\n";
        return array[0]; // something must be returned
      }
    }
    bool isEmpty() {
      return used == 0;
    }
};

template<class T, int I> void Stack<T, I>::push(T data) {
  if(used < size) {
    array[used++] = data;
  } else {
    std::cerr << "Stack full :(\n";
  }
}

#endif
