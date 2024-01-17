#include <iostream>

template <class type>
struct node {
   type data;
   node *next;
   node(type _data = 0) {
      data = _data;
      next = nullptr;
   }
};

template <class type>
class queue {
   node<type> *head;
   node<type> *tail;
   unsigned int Size;
public:
   queue() { // constructor 
      head = tail = nullptr;
      Size = 0;
   }

   ~queue() {
      make_null();
   }

   queue(const queue &obj) { // copy constructor 
      head = new node<type>;
      tail = new node<type>;
      head = tail;

      node<type> *cur = obj.head;
      for(; cur; cur=cur->next)
         push(cur->data);
      Size = 0;
   }

   node<type> *operator[](int index) { 
      if (index >= Size || index < 0) {
         std::cout << "incorrect index value \n";
         exit(1);
      } 

      node<type> *cur = head;
      int i = 0;
      while (cur && i<Size && i!=index) {
         cur = cur->next;
         i++;
      }
      return cur;
   }

   void push(int n) {
      node<type> *temp;
      temp = new node<type>(n);

      if (head == nullptr) {
         head = tail = temp;   
      }
      else {
         tail->next = temp;
         tail = tail->next;
      }
      Size++;
   }

   void make_null() {
      while (head) {
         node<type> *tmp = head;
         head = head->next;
         delete tmp;
      }
      tail = nullptr;
      Size = 0;
   }
   
   void erase(type n) {
     node<type> *tmp;

     if (head->data == n) {
        tmp = head->next;
        delete head;
        head = tmp;
     } else {
        node<type> *cur = head;

        while (cur->next->data != n) {
           cur = cur->next;
           if (cur->next == nullptr) 
              exit(1);
        }

        tmp = cur->next->next;
        delete cur->next;
        cur->next = tmp;
     }
   }

   node<type> *front() {
      if (!empty()) 
         return head;
      else 
         return nullptr;
   }

   void pop() {
      if (head) {
         node<type> *tmp = head;
         head = head->next;

         if (!head) 
            tail = nullptr;
         delete tmp;
         Size--;
      }
   }

   void print() {
      if (head) {
         for (node<type> *cur = head; cur; cur=cur->next) 
            std::cout << cur->data << " ";
         std::cout << std::endl;
      } 
   }

   bool empty() { return head == tail && !head; }
   int size() { return Size; }
};

