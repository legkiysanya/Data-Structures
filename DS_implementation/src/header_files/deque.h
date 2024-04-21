#ifndef DEQUE_H
#define DEQUE_H

#include "nodes.h"
#include <ostream>

// template <class T> class Deque;
// template <class T>
// std::ostream &operator<<(std::ostream &stream, const Deque<T> &obj);

template <class type> class Deque {
  double_ended_node<type> *head, *tail;
  unsigned int Size;

public:
  Deque();

  ~Deque();

  Deque(const Deque &obj);

  double_ended_node<type> *operator[](int index) const;

  void push_back(type n);

  void push_front(type n);

  void pop_front();

  void pop_back();

  void make_null();

  void print() const;

  double_ended_node<type> *front() const;

  double_ended_node<type> *rear() const;

  int size() const;

  // friend std::ostream &operator<< (std::ostream &stream, Deque<type> &obj);
  template <class T>
  friend std::ostream &operator<<(std::ostream &stream, const Deque<T> &obj);
};
#endif
