#ifndef QUEUE_H
#define QUEUE_H

#include "nodes.h"
#include <ostream>

template <class type>
class Queue {
   node<type> *head;
   node<type> *tail;
   unsigned int Size;
public:
   Queue();

   ~Queue();

   Queue(const Queue &obj);

   node<type> *operator[](int index);

   void push(type n);

   void make_null();
   
   void erase(type n);

   node<type> *front() const;

   void pop();

   bool empty() const;

   int size() const;

   template<class T>
   friend std::ostream &operator<<(std::ostream &stream, const Queue<T>& obj);
};

#endif
