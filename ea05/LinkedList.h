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
std::ostream& operator<<(std::ostream& os, const ListItem<T>& li) {
  os << li.value;
  return os;
}

template<class T>
class ListIterator : public Iterator<ListItem<T>> {
  public:
    ListIterator(ListItem<T>* i) {
      // use 'this' to force the compiler to look 
      // for the name 'p' in the base class
      this->p = i;
      // Iterator<ListItem<T>>::p = i; // also OK
    }
    
    bool operator!=(const Iterator<ListItem<T>>& it) const override {
      return this->p != static_cast<const ListIterator<T>&>(it).p;
    }
    
    ListIterator<T>& operator++() override {
      this->p = this->p->next;
      return *this;
    }
        
    ListItem<T>& operator*() const override {
      return *(this->p);
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
