#ifndef QUEUE_H
#define QUEUE_H

#include "nodes.h"
#include <ostream>

template <class type> class Queue {
  node<type> *head;
  node<type> *tail;
  unsigned int Size;

public:
  Queue(); // constructor

  ~Queue(); // deconstructor

  Queue(const Queue &obj); // copy constructor

  Queue(Queue &&obj); // move constructor

  Queue<type> &operator=(const Queue &obj); // assignment operator

  Queue<type> &operator=(Queue &&obj); // move assignment operator

  node<type> *operator[](int index) const;

  void push(type n);

  void makeNull();

  void erase(type n);

  node<type> *front() const;

  void pop();

  bool empty() const;

  int size() const;

  template <class T>
  friend std::ostream &operator<<(std::ostream &stream, const Queue<T> &obj);
};

#endif
