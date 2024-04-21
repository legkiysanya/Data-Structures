#include "header_files/deque.h"
#include "header_files/queue.h"
#include "header_files/sorted_list.h"
#include "header_files/stack.h"
#include "header_files/bst.h"

#include <fstream>

// for copy constructor demonstration
// template<class type>
// static void f(deque<type> ob) {
//   out << "there is copy of deq  ";
//   ob.print(); out << "end\n";
//}
int main() {

  //   cout << __TIME__ << "\n";
  //   // input and output files
  std::ifstream in("../data/items.txt");
  if (!in)
    return 1;

  std::ofstream out("output.txt");
  if (!out)
    return 1;

  Queue<int> q;
  Stack<char> s;
  Deque<double> d;
  SortedList<int> sl;
  Tree<int> t;

  while (in) {
    int i;
    in >> i;
    d.push_back(i);
    std::cout << i << ' ';
    q.push(i);
    s.push(i);
    sl.push(i);
    t.add(i);
  }
  in.close();

  t.display(out);
  t.printInorder();

  out << "\nDeque demonstrating\n";
  out << "the initial deque: ";
  out << d << "\n";
  out << "size of the deque: ";
  out << d.size() << "\n";
  d.pop_front();
  d.push_front(2);
  d.push_front(1);
  d.push_front(0);
  out << "deque after inserting several elements: ";
  out << d << "\n";
  out << "size of the deque: ";
  out << d.size() << "\n";
  d.pop_front();
  d.pop_back();
  out << "deque after deleting the front and the back elements: ";
  out << d << "\n";
  // out << "copy constructor demonstrating: \n";
  // f(d);
  // d.print();
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
  for (int i = 3; i != 9; ++i)
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
  for (int i = 76; i != 83; ++i)
    s.push((char)i);

  out << s << "\n";
  out << "a top of the stack: ";
  out << s.top() << "\n";
  s.pop();
  out << "stack after deleting two elements: ";
  out << s << "\n";
  s.makenull();
  out << "stack after deleting all elements: ";
  out << s << "\n";
  out << std::boolalpha << "is the stack empty: " << s.empty() << "\n";

  out << "\nSorted list demonstrating: \n";
  out << "a regular list: ";
  sl.print(out);
  out << "\n";
  out << "a sorted list: ";
  sl.print_sorted(out);
  out << "\n"
      << "size of a sorted list: ";
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
