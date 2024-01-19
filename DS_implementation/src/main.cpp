#include <iostream>
#include <fstream>
#include "deque.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "sorted_list.hpp"

using namespace std;
// for copy constructor demonstration
//template<class type> 
//static void f(deque<type> ob) {
//   out << "there is copy of deq  ";
//   ob.print(); out << "end\n";
//}

int main() {
   // input and output files
   std::ifstream in("../data/items.txt");
   if (!in) 
      return 1;

   std::ofstream out("output.txt");
   if (!out) 
      return 1;

   queue<int> q;
   stack<char> s;
   deque<double> d;
   sorted_list<int> sl;

   while (in) {
      int i;
      in >> i;
      d.push_back(i);
      q.push(i);
      s.push(i);
      sl.push(i);
   }
   in.close();



   out << "\nDeque demonstrating\n";
   out << "the initial deque: ";
   out << d << "\n";
   d.pop_front();
   d.push_front(2); 
   d.push_front(1); 
   d.push_front(0); 
   out << "size of the deque: ";
   out << d.size() << "\n";
   d.pop_front();
   d.pop_back();
   out << "deque after deleting the front and the back elements: ";
   out << d << "\n";
   //out << "copy constructor demonstrating: \n";
   //f(d);
   //d.print();
   out << "size of the deque: ";
   out << d.size() << "\n";
   d.make_null();
   out << "deque after deleting all elements: ";
   out << d << "\n";
   out << "size of the empty deque: ";
   out << d.size() << "\n";






   out << "\n";
   out << "Queue demonstrating\n";
   out << "the initial queue: ";
   out << q << "\n";
   q.pop();
   for (int i=3; i != 9; ++i) 
      q.push(i);

   out << q << "\n";
   out << "size of the queue: ";
   out << q.size() << "\n";
   q.pop();
   q.pop();
   out << "queue after deleting two elements: ";
   out << q << "\n";
   out << "size of the queue: ";
   out << q.size() << "\n";
   q.make_null();
   out << "queue after deleting all elements: ";
   out << q << "\n";
   out << "size of the empty queue: ";
   out << q.size() << "\n";



   


   out << "\nStack demonstrating\n";
   out << "the initial stack: ";
   out << s << "\n";
   s.pop();
   for (int i=76; i != 83; ++i) 
      s.push((char) i);

   out << s << "\n";
   out << "a top of the stack: ";
   out << s.top() << "\n";
   s.pop();
   s.pop();
   out << "stack after deleting two elements: ";
   out << s << "\n";
   s.makenull();
   out << "stack after deleting all elements: ";
   out << s << "\n";
   out << boolalpha << "is the stack empty: " << s.empty() << "\n";
   





   out << "\nSorted list demonstrating: \n";
   out << "a regular list: ";
   sl.print(out);
   out << "\n";
   out << "a sorted list: ";
   sl.print_sorted(out);
   out << "\n" << "size of a sorted list: ";
   out << sl.size() << "\n";
   out << "a sorted list after deleting some elements: \n";
   sl.erase(58);   
   sl.erase(103);   
   sl.erase(99);   
   out << "a regular list: ";
   sl.print(out);
   out << "\n";
   out << "a sorted list: ";
   sl.print_sorted(out);
   sl.make_null();
   
   out.close();
} 
