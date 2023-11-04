#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <exception>

class StackException : public std::exception {
  public:
    enum ErrorCode { UNDEFINED, EMPTY, FULL };
  private:
    ErrorCode code;
    std::string message;
  public:
    StackException() : code(ErrorCode::UNDEFINED), message("") {}
    StackException(ErrorCode code, const std::string& message) :
      code(code), message(message) {}
    ErrorCode getCode() const {
      return code;
    }
    // we have to promise not to throw exceptions in what()
    virtual const char* what() const noexcept {
      return message.c_str();
    }
};

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
        throw StackException(
          StackException::ErrorCode::EMPTY,
          "Oops, the stack is empty."
        );
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
    throw StackException(
      StackException::ErrorCode::FULL,
      "Sorry, stack full."
    );
  }
}

#endif
