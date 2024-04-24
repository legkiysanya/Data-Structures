#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "nodes.h"
#include <fstream>


template <class type> class SortedList {
  snode<type> *head, *tail; // regular list
  snode<type> *sorted_head; // sorted list
  unsigned int Size;

public:
  SortedList(); // consturctor

  ~SortedList(); // deconstructor

  SortedList(const SortedList &obj); // copy constructor

  SortedList(SortedList &&obj); // move constructor

  SortedList<type> &operator=(const SortedList &obj); // assignment operator

  SortedList<type> &operator=(SortedList &&obj); // move assignment operator

  void push(type n);

  void erase(type n); 

  snode<type> *front() const;

  snode<type> *sorted_front() const;

  void makeNull();

  void print(std::ofstream &stream) const;

  void printSorted(std::ofstream &stream) const;

  bool empty() const;

  int size() const; 
};
#endif
