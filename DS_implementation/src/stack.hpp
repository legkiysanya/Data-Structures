#ifndef STACK_HPP
#define STACK_HPP

#include <iostream> 
#include "queue.hpp"


template <class type>
class stack {
private:
   node<type> *head;
public:
   stack() { // constructor 
      head = nullptr;
   }

   ~stack() { // deconstructor
      while (head) pop();
   }

   stack(const stack &obj) { // copy constructor 
      head = new node<type>;

      node<type> *cur = obj.head;
      for(; cur; cur=cur->next)
         push(cur->data);
   }
   
   type &top() { 
      if (!head) {
         std::cout << "Empty stack\n";
         exit(1);
      }
      else
         return head->data;
   } 


   void pop() {
      if (!head) return;  

      node<type> *tmp;

      tmp = head->next;
      delete head;
      head = tmp;
   }

   void push(type n) {
      node<type> *tmp;
      tmp = new node<type>(n);

      tmp->data = n;
      tmp->next = head;
      head = tmp;
   }

   void makenull() { 
      while (head) pop(); 
   }

   bool empty() { return head == nullptr; }
   template<class T>
   friend std::ostream &operator<<(std::ostream &stream, stack<T> obj);
};



template<class type>
std::ostream &operator<<(std::ostream &stream, stack<type> obj) {
   if (obj.head) {
      for (node<type> *cur = obj.head; cur; cur = cur->next) 
         stream << cur->data << " ";
   }
   return stream;
}

#endif
