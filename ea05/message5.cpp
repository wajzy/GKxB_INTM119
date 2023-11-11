#include <iostream>
#include <cstring>
#include <stdexcept>

template<class T>
class Iterator {
  protected:
    T* p;
  public:
    virtual bool operator!=(const Iterator&) const = 0;
    virtual Iterator& operator++() = 0; // prefix
    virtual T& operator*() const = 0;
};

class MessageIterator : public Iterator<char> {
  public:
    MessageIterator(char* s) {
      p = s;
    }
    
    bool operator!=(const Iterator<char>& it) const override {
      return p != static_cast<const MessageIterator&>(it).p;
    }
    
    MessageIterator& operator++() override {
      ++p;
      return *this;
    }
        
    char& operator*() const override {
      return *p;
    }
};

class Message {
  private:
    char* pStr;
    int len;
  public:
    Message() {
      pStr = new char('\0');
      len = 0;
    }

    Message(const char* s) {
      len = strlen(s);
      pStr = new char[len + 1];
      strcpy(pStr, s);
    }

    Message(const Message& m) : Message(m.pStr) {}

    ~Message() {
      delete[] pStr;
    }

    friend std::ostream& operator<<(std::ostream& os, const Message& m);

    Message& operator=(const Message& m) {
      if(&m == this) return *this;
      delete[] pStr;
      len = strlen(m.pStr);
      pStr = new char[len + 1];
      strcpy(pStr, m.pStr);
      return *this;
    }

    MessageIterator begin() {
      return MessageIterator(pStr);
    }

    MessageIterator end() {
      return MessageIterator(pStr + len);
    }
    
    int length() {
      return len;
    }
    
    char& operator[](int i) {
      if (i < 0 || i >= len) {
        throw std::out_of_range("Message::operator[]");
      }
      return pStr[i];
    }
};

std::ostream& operator<<(std::ostream& os, const Message& m) {
  os << m.pStr;
  return os;
}

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
    }
    ListIterator<T> begin() {
      return ListIterator<T>(front);
    }

    ListIterator<T> end() {
      return ListIterator<T>(nullptr);
    }
};

int main() {
  Message m = "Hello C++ world!";

  // using iterator
  for (auto i = m.begin(); i != m.end(); ++i) {
    std::cout << *i;
  }
  std::cout << std::endl;

  // range-based for loop, C++11
  for (const auto& c : m) {
    std::cout << c;
  }
  std::cout << std::endl;

  // operator[]
  try {
    for (auto i = 0; i <= m.length(); i++) {
      std::cout << m[i];
    }
  } catch(const std::out_of_range& e) {
    std::cerr << "\nException caught: " << e.what() << std::endl;
  }
  
  LinkedList<int> l;
  l.append(1); l.append(2); l.append(3);
  for (auto i = l.begin(); i != l.end(); ++i) {
    std::cout << *i << '\t';
  }
  std::cout << std::endl;
}

// postfix alak: virtual Iterator operator++(int) = 0; -> de absztrakt osztályt nem lehet példányosítani, így a visszatérési érték típusa nem lehet Iterator
// https://en.cppreference.com/w/cpp/language/override
// static_cast -> nincs ellenőrzés; dynamic_cast bad_cast kivételt dobhat
// range-based for loop: https://en.cppreference.com/w/cpp/language/range-for
// out_of_range: https://en.cppreference.com/w/cpp/error/out_of_range
// iterátorok hierarchiája, operátorok: https://cplusplus.com/reference/iterator/
