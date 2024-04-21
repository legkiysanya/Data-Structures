#include "../header_files/stack.h"
#include "../header_files/nodes.h"

template <class type> Stack<type>::Stack() { // constructor
  head = nullptr;
}

template <class type> Stack<type>::~Stack() { // deconstructor
  while (head)
    pop();
}

template <class type> Stack<type>::Stack(const Stack &obj) { // copy constructor
  head = new node<type>;

  node<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    push(cur->data);
}

template <class type>
type &Stack<type>::top() const {
  if (!head) {
    std::cout << "Empty stack\n";
    exit(1);
  } else
    return head->data;
}

template <class type> type Stack<type>::pop() {
  if (!head)
    exit(1);
  type value = head->data;
  node<type> *tmp;

  tmp = head->next;
  delete head;
  head = tmp;
  return value;
}

template <class type> void Stack<type>::push(type n) {
  node<type> *tmp;
  tmp = new node<type>(n);

  tmp->data = n;
  tmp->next = head;
  head = tmp;
}

template <class type> void Stack<type>::makenull() {
  while (head)
    pop();
}

template <class type> bool Stack<type>::empty() const { return head == nullptr; }

template <class T>
std::ostream &operator<<(std::ostream &stream, const Stack<T> &obj) {
  if (obj.head) {
    for (node<T> *cur = obj.head; cur; cur = cur->next)
      stream << cur->data << " ";
  }
  return stream;
}

template Stack<int>::Stack();         
template Stack<double>::Stack();      
template Stack<char>::Stack();        
template Stack<std::string>::Stack(); 

template Stack<int>::~Stack();       
template Stack<double>::~Stack();       
template Stack<char>::~Stack();       
template Stack<std::string>::~Stack();       

template Stack<int>::Stack(const Stack &obj); 
template Stack<double>::Stack(const Stack &obj);
template Stack<char>::Stack(const Stack &obj); 
template Stack<std::string>::Stack(const Stack &obj); 

template int &Stack<int>::top() const;
template double &Stack<double>::top() const;
template char &Stack<char>::top() const;
template std::string &Stack<std::string>::top() const;

template int Stack<int>::pop();
template double Stack<double>::pop();
template char Stack<char>::pop();
template std::string Stack<std::string>::pop();

template void Stack<int>::push(int n);
template void Stack<double>::push(double n);
template void Stack<char>::push(char n);
template void Stack<std::string>::push(std::string n);

template void Stack<int>::makenull();
template void Stack<double>::makenull();
template void Stack<char>::makenull();
template void Stack<std::string>::makenull();

template bool Stack<int>::empty() const;
template bool Stack<double>::empty() const;
template bool Stack<char>::empty() const;
template bool Stack<std::string>::empty() const;

template std::ostream &operator<<(std::ostream &stream, const Stack<int> &obj);
template std::ostream &operator<<(std::ostream &stream, const Stack<double> &obj);
template std::ostream &operator<<(std::ostream &stream, const Stack<char> &obj);
template std::ostream &operator<<(std::ostream &stream, const Stack<std::string> &obj);
