#ifndef STACK2_HPP
#define STACK2_HPP

#include <exception>
#include <iostream>
#include <string>

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
    int used;
  public:
    Stack() {
      array = new T[I];
      used = 0;
    }
    ~Stack() {
      delete[] array;
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
  if(used < I) {
    array[used++] = data;
  } else {
    throw StackException(
      StackException::ErrorCode::FULL,
      "Sorry, stack full."
    );
  }
}

#endif
