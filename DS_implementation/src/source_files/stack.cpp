#include "../header_files/stack.h"
#include "../header_files/nodes.h"

// constructor
template <class type> 
Stack<type>::Stack() { 
  head = nullptr;
}

// deconstructor
template <class type> 
Stack<type>::~Stack() { 
  while (head)
    pop();
}

// copy constructor
template <class type>
Stack<type>::Stack(const Stack &obj) { 
  head = nullptr;
  Stack<type> tmp;

  node<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    tmp.push(cur->data);

  cur = tmp.head;
  for (; cur; cur = cur->next)
    push(cur->data);
  tmp.makeNull();
}

template <class type>
Stack<type>::Stack(Stack &&obj) {
  head = obj.head;
  obj.head = nullptr;
}

// assignment operator
template <class type>
Stack<type> &Stack<type>::operator=(const Stack &obj) {
  makeNull();
  Stack<type> tmp;
  node<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    tmp.push(cur->data);

  cur = tmp.head;
  for (; cur; cur = cur->next)
    push(cur->data);
  tmp.makeNull();

  return *this;
}

// move assignment operator
template <class type>
Stack<type> &Stack<type>::operator=(Stack &&obj) {
  makeNull();
  head = obj.head;
  obj.head = nullptr;

  return *this;
}

template <class type>
type &Stack<type>::top() const {
  if (!head) {
    std::cout << "Empty stack\n";
    exit(1);
  } else
    return head->data;
}

template <class type>
type Stack<type>::pop() {
  if (!head)
    exit(1);
  type value = head->data;
  node<type> *tmp;

  tmp = head->next;
  delete head;
  head = tmp;
  return value;
}

template <class type>
void Stack<type>::push(type n) {
  node<type> *tmp;
  tmp = new node<type>(n);

  tmp->next = head;
  head = tmp;
}

template <class type>
void Stack<type>::makeNull() {
  while (head)
    pop();
}

template <class type>
bool Stack<type>::empty() const {
  return head == nullptr;
}

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

template Stack<int>::Stack(Stack &&obj);
template Stack<double>::Stack(Stack &&obj);
template Stack<std::string>::Stack(Stack &&obj);
template Stack<char>::Stack(Stack &&obj);

template Stack<int> &Stack<int>::operator=(const Stack &obj);
template Stack<double> &Stack<double>::operator=(const Stack &obj);
template Stack<std::string> &Stack<std::string>::operator=(const Stack &obj);
template Stack<char> &Stack<char>::operator=(const Stack &obj);

template Stack<int> &Stack<int>::operator=(Stack &&obj);
template Stack<double> &Stack<double>::operator=(Stack &&obj);
template Stack<std::string> &Stack<std::string>::operator=(Stack &&obj);
template Stack<char> &Stack<char>::operator=(Stack &&obj);

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

template void Stack<int>::makeNull();
template void Stack<double>::makeNull();
template void Stack<char>::makeNull();
template void Stack<std::string>::makeNull();

template bool Stack<int>::empty() const;
template bool Stack<double>::empty() const;
template bool Stack<char>::empty() const;
template bool Stack<std::string>::empty() const;

template std::ostream &operator<<(std::ostream &stream, const Stack<int> &obj);
template std::ostream &operator<<(std::ostream &stream,
                                  const Stack<double> &obj);
template std::ostream &operator<<(std::ostream &stream, const Stack<char> &obj);
template std::ostream &operator<<(std::ostream &stream,
                                  const Stack<std::string> &obj);
