#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

#include <iostream>

using namespace std;


template<class type>
struct snode {
   type data;
   snode *next;
   snode *sorted_next;
   snode(type _data = 0) {
      data = _data;
      next = nullptr;
      sorted_next = nullptr;
   }
};

template<class type>
class sorted_list {
   snode<type> *head, *tail; // regular list
   snode<type> *sorted_head; // sorted list
   unsigned int Size;
public:
   sorted_list() {
      head = tail = nullptr;
      sorted_head = nullptr;
      Size = 0;
   }
   ~sorted_list() {
      make_null();
   }

   sorted_list(const sorted_list &obj) { // copy constructor 
      head = nullptr;
      sorted_head = nullptr;
      tail = head;

      snode<type> *cur = obj.head;
      for(; cur; cur=cur->next)
         push(cur->data);
      Size = 0;
   }


   inline void push(int n) {
      snode<type> *tmp;
      tmp = new snode<type>(n);

      if (head == tail && !head ){
         head = tail = tmp;
      } else {
         tail->next = tmp;
         tail = tmp;
      }

      if (!sorted_head || sorted_head->data > n) {
         tmp->sorted_next = sorted_head;
         sorted_head = tmp;
      } else {
         snode<type> *prev, *cur;
         cur = prev = sorted_head;
         while (cur && tmp->data > cur->data) {
            prev = cur;
            cur = cur->sorted_next;
         }
            prev->sorted_next = tmp;
            tmp->sorted_next = cur; 
      }
      Size++;
   }

   void erase(int n) {
      snode<type>*item;
      if (head->data == n) {
         item = head;
         head = head->next;
      } else {
         snode<type> *cur = head;
         while (cur->next && cur->next->data != n) 
            cur = cur->next;
         if (!cur->next) 
            return;
         item = cur->next;
         cur->next = item->next;
      }


      if (sorted_head->data == n) {
         sorted_head = sorted_head->sorted_next;
      } else {
         snode<type> *cur = sorted_head;
         while (cur->sorted_next && cur->sorted_next->data != n) 
            cur = cur->sorted_next;
         cur->sorted_next = cur->sorted_next->sorted_next;
      }
      delete item;
      Size--;
   }

   snode<type> *front() {
      if (!empty()) 
         return head;
      else 
         return nullptr;
   }
   snode<type> *sorted_front() {
      if (!empty()) 
         return sorted_head;
      else 
         return nullptr;
   }

   void make_null() {
      while (head) {
         snode<type> *tmp = head;
         head = head->next;
         delete tmp;
      }

      tail = sorted_head = nullptr;
      Size = 0;
   }

   void print(std::ofstream &stream) {
      if (head) {
         for (snode<type> *cur = head; cur; cur=cur->next) // красота!
            stream << cur->data << " ";
      }
   }

   void print_sorted(std::ofstream &stream) {
      if (sorted_head) {
         for (snode<type> *cur = sorted_head; cur; cur=cur->sorted_next) // красота!
            stream << cur->data << " ";
      } 
   }

   bool empty() { return head == tail && !head; }
   int size()   { return Size; }
};
#endif
