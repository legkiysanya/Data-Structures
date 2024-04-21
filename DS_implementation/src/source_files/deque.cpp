#include "../header_files/deque.h"
#include <iostream>

template <class type>
Deque<type>::Deque() : Size(0), head(nullptr), tail(nullptr) {} // constructor

template <class type> Deque<type>::~Deque() { // deconstructor
  make_null();
}

template <class type> Deque<type>::Deque(const Deque &obj) { // copy constructor
  head = new double_ended_node<type>;
  tail = new double_ended_node<type>;
  head = tail;

  double_ended_node<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    push_back(cur->data);
  Size = 0;
}

template <class type>
double_ended_node<type> *Deque<type>::operator[](int index) const {
  if (index >= Size || index < 0) {
    std::cout << "incorrect index value \n";
    exit(1);
  }

  double_ended_node<type> *cur = head;
  int i = 0;
  while (cur && i < Size && i != index) {
    cur = cur->next;
    i++;
  }
  return cur;
}

template <class type> void Deque<type>::push_back(type n) {
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

template <class type> void Deque<type>::push_front(type n) {
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

template <class type> void Deque<type>::pop_front() {
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

template <class type> void Deque<type>::pop_back() {
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

template <class type> void Deque<type>::make_null() {
  while (head) {
    double_ended_node<type> *tmp = head;
    head = head->next;
    delete tmp;
  }
  tail = nullptr;
  Size = 0;
}

template <class type> void Deque<type>::print() const {
  if (head) {
    for (double_ended_node<type> *cur = head; cur; cur = cur->next)
      std::cout << cur->data << " ";
    std::cout << std::endl;
  }
}

template <class type> double_ended_node<type> *Deque<type>::front() const {
  return head;
}
template <class type> double_ended_node<type> *Deque<type>::rear() const {
  return tail;
}
template <class type> int Deque<type>::size() const { return Size; }

template <class type>
std::ostream &operator<<(std::ostream &stream, const Deque<type> &obj) {
  if (obj.head) {
    for (double_ended_node<type> *cur = obj.head; cur; cur = cur->next) {
      stream << cur->data << " ";
    }
  }
  return stream;
}



template Deque<int>::Deque();
template Deque<std::string>::Deque();
template Deque<double>::Deque();
template Deque<char>::Deque();

template Deque<int>::~Deque();
template Deque<std::string>::~Deque();
template Deque<double>::~Deque();
template Deque<char>::~Deque();

template Deque<int>::Deque(const Deque &obj);
template Deque<double>::Deque(const Deque &obj);
template Deque<std::string>::Deque(const Deque &obj);
template Deque<char>::Deque(const Deque &obj);

template double_ended_node<int> *Deque<int>::operator[](int index) const;
template double_ended_node<double> *Deque<double>::operator[](int index) const;
template double_ended_node<std::string> *Deque<std::string>::operator[](int index) const;
template double_ended_node<char> *Deque<char>::operator[](int index) const;

template void Deque<int>::push_back(int n);
template void Deque<double>::push_back(double n);
template void Deque<std::string>::push_back(std::string n);
template void Deque<char>::push_back(char n);

template void Deque<int>::push_front(int n);
template void Deque<double>::push_front(double n);
template void Deque<std::string>::push_front(std::string n);
template void Deque<char>::push_front(char n);

template void Deque<int>::pop_front();
template void Deque<double>::pop_front();
template void Deque<std::string>::pop_front();
template void Deque<char>::pop_front();

template void Deque<int>::pop_back();
template void Deque<double>::pop_back();
template void Deque<std::string>::pop_back();
template void Deque<char>::pop_back();

template void Deque<int>::make_null();
template void Deque<double>::make_null();
template void Deque<std::string>::make_null();
template void Deque<char>::make_null();

template void Deque<int>::print() const;
template void Deque<double>::print() const;
template void Deque<std::string>::print() const;
template void Deque<char>::print() const;

template double_ended_node<int> *Deque<int>::front() const;
template double_ended_node<double> *Deque<double>::front() const;
template double_ended_node<std::string> *Deque<std::string>::front() const;
template double_ended_node<char> *Deque<char>::front() const;

template double_ended_node<int> *Deque<int>::rear() const;
template double_ended_node<double> *Deque<double>::rear() const;
template double_ended_node<std::string> *Deque<std::string>::rear() const;
template double_ended_node<char> *Deque<char>::rear() const;

template int Deque<int>::size() const;
template int Deque<double>::size() const;
template int Deque<std::string>::size() const;
template int Deque<char>::size() const;

template std::ostream &operator<<(std::ostream &stream, const Deque<int> &obj);
template std::ostream &operator<<(std::ostream &stream, const Deque<double> &obj);
template std::ostream &operator<<(std::ostream &stream, const Deque<std::string> &obj);
template std::ostream &operator<<(std::ostream &stream, const Deque<char> &obj);
