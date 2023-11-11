#ifndef ITERATOR_H
#define ITERATOR_H

template<class T>
class Iterator {
  protected:
    T* p;
  public:
    virtual bool operator!=(const Iterator&) const = 0;
    virtual Iterator& operator++() = 0; // prefix
    virtual T& operator*() const = 0;
};

#endif
