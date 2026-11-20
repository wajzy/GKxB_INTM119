#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include "Iterator.hpp"

template<typename T>
class LinkedList {
  private:
    struct ListItem {
      T value;
      ListItem* next;
    };

    ListItem* front;
    ListItem* tail;

  public:
    class iterator : public ::Iterator<T> {
        ListItem* p;
      public:
        iterator(ListItem* i) : p(i) {}

        bool operator!=(const ::Iterator<T>& it) const override {
          return p != static_cast<const iterator&>(it).p;
        }

        iterator& operator++() override {
          p = p->next;
          return *this;
        }

        T& operator*() const override {
          return p->value;
        }
    };

    LinkedList() : front(nullptr), tail(nullptr) {}

    LinkedList(const LinkedList&) = delete; // Rule of Three
    LinkedList& operator=(const LinkedList&) = delete;

    ~LinkedList() {
      for(ListItem* current = front; current != nullptr;) {
        ListItem* next = current->next;
        delete current;
        current = next;
      }
    }

    void push_back(const T& i) {
      ListItem* latest = new ListItem{ i, nullptr };
      if(tail == nullptr) {
        front = latest;
      } else {
        tail->next = latest;
      }
      tail = latest;
    }

    iterator begin() {
      return iterator(front);
    }

    iterator end() {
      return iterator(nullptr);
    }
};

#endif
