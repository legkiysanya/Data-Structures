#include "header_files/bst.h"
#include "header_files/deque.h"
#include "header_files/queue.h"
#include "header_files/sorted_list.h"
#include "header_files/stack.h"

#include <fstream>
#include <utility>

int main() {
  // input and output files
  std::ifstream in("../data/items.txt");
  if (!in)
    return 1;

  std::ofstream out("output.txt");
  if (!out)
    return 1;

  Tree<int> t;
  Deque<double> d;
  Queue<int> q;
  Stack<char> s;
  SortedList<int> sl;

  int i = 0;
  in >> i;
  while (in) {
    d.push_back(i);
    q.push(i);
    s.push(i);
    sl.push(i);
    t.add(i);
    in >> i;
  }
  in.close();

  Tree<int> tCopied = t;
  out << "Binary search tree demonstration: \n";
  out << "The initial bst: \n";
  t.display(out);

  out << "Tree after deleting root node: \n";
  t.erase(58);
  t.display(out);
  
  out << "Tree after deleting middle node: \n";
  t.erase(78);
  t.display(out);

  out << "Copied tree (copy constructor) after inserting several nodes: \n";
  tCopied.add(34);
  tCopied.add(0);
  tCopied.add(50);
  tCopied.display(out);

  out << "\"Moved\" tree (move assignment operator) \n";
  Tree<int> tMoved;
  tMoved = std::move(tCopied);
  tMoved.display(out); 
  tMoved.makeNull();
  tMoved.display(out); 
  tCopied.display(out); 




  out << "\nDeque demonstration\n";
  out << "The initial deque: \n";
  out << d << "\n";

  out << "Size of the deque: \n";
  out << d.size() << "\n";

  out << "Deque after inserting several elements: \n";
  d.push_front(2);
  d.push_front(1);
  d.push_front(0);
  out << d << "\n";

  out << "Deque after deleting the front and the back elements: \n";
  d.pop_front();
  d.pop_back();
  out << d << "\n";

  out << "Copied deque (assignment operator): \n";
  Deque<double> dCopied;
  dCopied = d;
  out << dCopied << "\n";

  out << "\"Moved\" deque (move consturctor): \n";
  Deque<double> dMoved = std::move(d);
  out << dMoved << "\n";

  d.makeNull();




  out << "\n";
  out << "Queue demonstration\n";
  out << "The initial queue: \n";
  out << q << "\n";

  out << "Queue after pushing some elements (copy constructor): \n";
  for (int i = 3; i != 9; ++i)
    q.push(i);
  out << q << "\n";

  out << "Copied queue (copy constructor): \n";
  Queue<int> qCopied = q;
  out << qCopied << "\n";

  out << "\"Moved\" queue (move assignment operator): \n";
  Queue<int> qMoved;
  qMoved = std::move(q);
  out << qMoved << "\n";

  out << "Moved queue after deleting two elements: \n";
  qMoved.pop();
  qMoved.pop();
  out << qMoved << "\n";

  out << "Copied queue after deleting all elements: \n";
  qCopied.makeNull();
  out << qCopied << "\n";

  out << "Size of the empty copied queue: \n";
  out << qCopied.size() << "\n";




  out << "\nStack demonstration\n";
  out << "The initial stack: \n";
  out << s << "\n";

  out << "Stack after pushing some items: \n";
  for (int i = 76; i != 83; ++i)
    s.push((char)i);
  out << s << "\n";

  out << "Copied stack (assignment opretator): \n";
  Stack<char> sCopied;
  sCopied = s;
  out << sCopied << "\n";

  out << "\"Moved\" stack (move constructor): \n";
  Stack<char> s2 = std::move(sCopied);
  out << s2 << "\n";

  out << "A top of the stack: \n";
  out << s.top() << "\n";

  out << "Stack after deleting two elements: \n";
  s.pop();
  s.pop();
  out << s << "\n";

  out << "Stack after deleting all elements: \n";
  s.makeNull();
  out << s << "\n";

  out << std::boolalpha << "Is a stack empty: " << s.empty() << "\n";




  out << "\nSorted list demonstration: \n";
  out << "The innitial regular list: \n";
  sl.print(out);
  out << "The innitial sorted list: \n";
  sl.printSorted(out);

  out << "Copied sorted list (copy constructor): \n";
  SortedList<int> slCopied = sl;
  out << "A regular list: \n";
  slCopied.print(out);
  out << "A sorted list: \n";
  slCopied.printSorted(out);

  out << "\"Moved\" sorted list (move assignment operator): \n";
  SortedList<int> slMoved;
  slMoved = std::move(slCopied);
  out << "A regular list: \n";
  slMoved.print(out);
  out << "A sorted list: \n";
  slMoved.printSorted(out);

  out << "Size of a sorted list: \n";
  out << sl.size() << "\n";

  out << "A sorted list after deleting some elements: \n";
  sl.erase(58);
  sl.erase(103);
  sl.erase(99);
  out << "A regular list: \n";
  sl.print(out);
  out << "A sorted list: \n";
  sl.printSorted(out);

  out << std::boolalpha << "Is a sorted list empty: " << sl.empty() << "\n";
  sl.makeNull();
  out << std::boolalpha << "Is a sorted list empty after makeNull procedure: " << sl.empty() << "\n";
  
  out.close();
}
