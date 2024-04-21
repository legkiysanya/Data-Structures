#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "nodes.h"
#include <fstream>


template <class type> class SortedList {
  snode<type> *head, *tail; // regular list
  snode<type> *sorted_head; // sorted list
  unsigned int Size;

public:
  SortedList();

  ~SortedList();

  SortedList(const SortedList &obj); // copy constructor

  void push(type n);

  void erase(type n); 

  snode<type> *front() const;

  snode<type> *sorted_front() const;

  void make_null();

  void print(std::ofstream &stream) const;

  void print_sorted(std::ofstream &stream) const;

  bool empty() const;

  int size() const; 
};
#endif
