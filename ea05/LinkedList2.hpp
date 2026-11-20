#ifndef LINKED_LIST2_HPP
#define LINKED_LIST2_HPP
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
    class const_iterator;

    class iterator : public ::Iterator<T> {
        ListItem* p;
        friend class const_iterator;
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

    class const_iterator : public ::Iterator<const T> {
        const ListItem* p;
      public:
        const_iterator(const ListItem* i) : p(i) {}

        const_iterator(const typename LinkedList::iterator& it) : p(it.p) {}

        bool operator!=(const ::Iterator<const T>& it) const override {
          return p != static_cast<const const_iterator&>(it).p;
        }

        const_iterator& operator++() override {
          p = p->next;
          return *this;
        }

        const T& operator*() const override {
          return p->value;
        }
    };

    LinkedList() : front(nullptr), tail(nullptr) {}

    LinkedList(const LinkedList&) = delete; // Rule of Three
    LinkedList& operator=(const LinkedList&) = delete;

    ~LinkedList() {
      for (ListItem* current = front; current != nullptr;) {
        ListItem* next = current->next;
        delete current;
        current = next;
      }
    }

    void push_back(const T& i) {
      ListItem* latest = new ListItem{ i, nullptr };
      if (tail == nullptr) {
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

    const_iterator begin() const {
      return const_iterator(front);
    }

    const_iterator end() const {
      return const_iterator(nullptr);
    }

    const_iterator cbegin() const {
      return const_iterator(front);
    }

    const_iterator cend() const {
      return const_iterator(nullptr);
    }
};

#endif
