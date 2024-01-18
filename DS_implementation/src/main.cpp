#include <iostream>
#include "deque.hpp"
#include "queue.hpp"
#include "stack.hpp"

using namespace std;

//template<class type>
//static void f(deque<type> ob) {
//   cout << "there is copy of deq  ";
//   ob.print(); cout << "end\n";
//}

int main() {
   cout.setf(ios::boolalpha);

   std::cout << "\nDeque demonstrating\n";
   deque<double> d;
   d.pop_front();
   for (int i=3; i != 9; ++i) 
      d.push_back(i * 1.1938);

   d.push_front(2); 
   d.push_front(1); 
   d.push_front(0); 
   cout << "the initial deque: ";
   cout << d << "\n";

   cout << "size of the deque: ";
   std::cout << d.size() << "\n";
   cout << d << "\n";

   d.pop_front();
   d.pop_back();
   cout << "deque after deleting the front and the back elements: ";
   cout << d << "\n";

   //cout << "copy constructor demonstrating: \n";
   //f(d);
   //d.print();
   
   cout << "size of the deque: ";
   std::cout << d.size() << "\n";

   d.make_null();
   cout << "deque after deleting all elements: ";
   cout << d << "\n";

   cout << "size of the empty deque: ";
   std::cout << d.size() << "\n";






   std::cout << "\n";
   std::cout << "Queue demonstrating\n";

   queue<int> q;
   q.pop();
   for (int i=3; i != 9; ++i) 
      q.push(i);

   q.push(2); 
   q.push(1); 
   q.push(0); 
   cout << "the initial queue: ";
   cout << q << "\n";

   cout << "size of the queue: ";
   std::cout << q.size() << "\n";

   q.pop();
   q.pop();
   cout << "queue after deleting two elements: ";
   cout << q << "\n";

   cout << "size of the queue: ";
   std::cout << q.size() << "\n";

   q.make_null();
   cout << "queue after deleting all elements: ";
   cout << q << "\n";

   cout << "size of the empty queue: ";
   std::cout << q.size() << "\n";



   


   std::cout << "\n";
   std::cout << "Stack demonstrating\n";

   stack<char> s;
   s.pop();
   for (int i=76; i != 83; ++i) 
      s.push((char) i);

   cout << "the initial stack: ";
   cout << s << "\n";

   std::cout << "a top of the stack: ";
   std::cout << s.top() << "\n";

   s.pop();
   s.pop();
   std::cout << "stack after deleting two elements: ";
   cout << s << "\n";

   s.makenull();
   cout << "stack after deleting all elements: ";
   cout << s << "\n";

   std::cout << "is the stack empty: " << s.empty() << "\n";
} 
