#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "Iterator.h"

template<class T>
struct ListItem {
  T value;
  ListItem<T>* next;
};

template<class T>
class ListIterator : public Iterator<T> {
    ListItem<T>* p;
  public:
    ListIterator(ListItem<T>* i) : p(i) {}
    
    bool operator!=(const Iterator<T>& it) const override {
      return p != static_cast<const ListIterator<T>&>(it).p;
    }
    
    ListIterator<T>& operator++() override {
      p = p->next;
      return *this;
    }
        
    T& operator*() const override {
      return p->value;
    }
};

template<class T>
class LinkedList {
  private:
    ListItem<T>* front;
    ListItem<T>* tail;
  public:
    LinkedList() {
      front = tail = nullptr;
    }
    
    ~LinkedList() {
      for(ListItem<T>* current = front; current != nullptr;) {
        ListItem<T>* next = current->next;
        delete current;
        current = next;
      }
    }
    
    void append(const T& i) {
      ListItem<T>* latest = new ListItem<T>;
      *latest = { i, nullptr };
      if(tail == nullptr) {
        front = latest;
      } else {
        tail->next = latest;
      }
      tail = latest;
    };
    
    ListIterator<T> begin() {
      return ListIterator<T>(front);
    }

    ListIterator<T> end() {
      return ListIterator<T>(nullptr);
    }
};

#endif
