#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>

template<class type> 
struct double_ended_node {
   type data;
   double_ended_node *prev, *next;
   double_ended_node(type _data = 0) {
      data = _data;
      prev = next = nullptr;
   }
};

template<class type>
class deque {
   double_ended_node<type> *head, *tail;
   unsigned int Size;
public:
   deque() { // constructor
      head = tail = nullptr;
      Size = 0;
   }

   ~deque() { // deconstructor
      make_null();
   }

   deque(const deque &obj) { // copy constructor 
      head = new double_ended_node<type>;
      tail = new double_ended_node<type>;
      head = tail;

      double_ended_node<type> *cur = obj.head;
      for(; cur; cur=cur->next)
         push_back(cur->data);
      Size = 0;
   }

   double_ended_node<type> *operator[](int index) {
      if (index >= Size || index < 0) {
         std::cout << "incorrect index value \n";
         exit(1);
      } 

      double_ended_node<type> *cur = head;
      int i = 0;
      while (cur && i<Size && i!=index) {
         cur = cur->next;
         i++;
      }
      return cur;
   }

   void push_back(type n) {
      double_ended_node<type> *cur;
      cur = new double_ended_node<type>(n);

      if (head == tail && !head)
         head = tail = cur;
      else {
         cur->prev = tail;
         tail->next = cur;
         tail = cur;
      }
      Size++;
   }

   void push_front(type n) {
      double_ended_node<type> *cur;
      cur = new double_ended_node<type>(n);

      if (head == tail && !head) 
         head = tail = cur;
      else {
         cur->next = head;
         head->prev = cur;
         head = cur;
      }
      Size++;
   }

   void pop_front() {
      if (head) {
         double_ended_node<type> *tmp = head;
         head = head->next;

         if (!head) 
            tail = nullptr;
         else 
            head->prev = nullptr;
         delete tmp;
         Size--;
      }
   }

   void pop_back() {
      if (tail) {
         double_ended_node<type> *tmp = tail;
         tail = tail->prev;

         if (!tail)
            head = nullptr;
         else 
            tail->next = nullptr;

         delete tmp;
         Size--;
      }
   }

   void make_null() {
      while (head) {
         double_ended_node<type> *tmp = head;
         head = head->next;
         delete tmp;
      }
      tail = nullptr;
      Size = 0;
   }

   void print() {
      if (head) {
         for (double_ended_node<type> *cur = head; cur; cur=cur->next) 
            std::cout << cur->data << " ";
         std::cout << std::endl;
      } 
   }

   double_ended_node<type> *front() { return head; }
   double_ended_node<type> *rear()  { return tail; }
   int size() { return Size; }
};

#endif
