#ifndef DEQUE_H
#define DEQUE_H

#include "nodes.h"
#include <ostream>

template <class type> class Deque {
  denode<type> *head, *tail;
  unsigned int Size;

public:
  Deque(); // constructor

  ~Deque(); // destructor

  Deque(const Deque &obj); // copy constructor

  Deque(Deque &&obj); // move constructor

  Deque<type> & operator=(const Deque &obj); // assignment operator 

  Deque<type> & operator=(Deque &&obj); // move assignment operator

  denode<type> *operator[](int index) const;

  void push_back(type n);

  void push_front(type n);

  void pop_front();

  void pop_back();

  void makeNull();

  void print() const;

  denode<type> *front() const;

  denode<type> *rear() const;

  int size() const;

  template <class T>
  friend std::ostream &operator<<(std::ostream &stream, const Deque<T> &obj);
};
#endif
