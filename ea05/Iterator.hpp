#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template<class T>
class Iterator {
  public:
    virtual bool operator!=(const Iterator<T>&) const = 0;
    virtual Iterator<T>& operator++() = 0; // prefix
    virtual T& operator*() const = 0;
    virtual ~Iterator() = default;
};

#endif
