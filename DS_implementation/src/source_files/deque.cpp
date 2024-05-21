#include "../header_files/deque.h"
#include <iostream>

// constructor
template <class type>
Deque<type>::Deque() : head(nullptr), tail(nullptr), Size(0) {}

// deconstructor
template <class type> Deque<type>::~Deque() { makeNull(); }

// copy constructor
template <class type>
Deque<type>::Deque(const Deque &obj)
    : head(nullptr), tail(nullptr), Size(obj.Size) {
  denode<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    push_back(cur->data);
}

// move constructor
template <class type>
Deque<type>::Deque(Deque &&obj)
    : head(obj.head), tail(obj.tail), Size(obj.Size) {
  obj.head = nullptr;
  obj.tail = nullptr;
  obj.Size = 0;
}

// assignment operator
template <class type> Deque<type> &Deque<type>::operator=(const Deque &obj) {
  makeNull();
  denode<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    push_back(cur->data);
  Size = obj.Size;

  return *this;
}

// move assignment operator
template <class type> Deque<type> &Deque<type>::operator=(Deque &&obj) {
  makeNull();
  head = obj.head;
  tail = obj.tail;
  obj.head = obj.tail = nullptr;
  Size = obj.Size;
  obj.Size = 0;

  return *this;
}

template <class type> denode<type> *Deque<type>::operator[](int index) const {
  if (index >= Size || index < 0) {
    std::cout << "incorrect index value \n";
    exit(1);
  }

  denode<type> *cur = head;
  int i = 0;
  while (cur && i < Size && i != index) {
    cur = cur->next;
    i++;
  }
  return cur;
}

template <class type> void Deque<type>::push_back(type n) {
  denode<type> *cur;
  cur = new denode<type>(n);

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
  denode<type> *cur;
  cur = new denode<type>(n);

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
    denode<type> *tmp = head;
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
    denode<type> *tmp = tail;
    tail = tail->prev;

    if (!tail)
      head = nullptr;
    else
      tail->next = nullptr;

    delete tmp;
    Size--;
  }
}

template <class type> void Deque<type>::makeNull() {
  while (head) {
    denode<type> *tmp = head;
    head = head->next;
    delete tmp;
  }
  tail = nullptr;
  Size = 0;
}

template <class type> void Deque<type>::print() const {
  if (head) {
    for (denode<type> *cur = head; cur; cur = cur->next)
      std::cout << cur->data << " ";
    std::cout << std::endl;
  }
}

template <class type> denode<type> *Deque<type>::front() const { return head; }

template <class type> denode<type> *Deque<type>::rear() const { return tail; }

template <class type> int Deque<type>::size() const { return Size; }

template <class type>
std::ostream &operator<<(std::ostream &stream, const Deque<type> &obj) {
  if (obj.head) {
    for (denode<type> *cur = obj.head; cur; cur = cur->next) {
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

template Deque<int>::Deque(Deque &&obj);
template Deque<double>::Deque(Deque &&obj);
template Deque<std::string>::Deque(Deque &&obj);
template Deque<char>::Deque(Deque &&obj);

template Deque<int> &Deque<int>::operator=(const Deque &obj);
template Deque<double> &Deque<double>::operator=(const Deque &obj);
template Deque<std::string> &Deque<std::string>::operator=(const Deque &obj);
template Deque<char> &Deque<char>::operator=(const Deque &obj);

template Deque<int> &Deque<int>::operator=(Deque &&obj);
template Deque<double> &Deque<double>::operator=(Deque &&obj);
template Deque<std::string> &Deque<std::string>::operator=(Deque &&obj);
template Deque<char> &Deque<char>::operator=(Deque &&obj);

template denode<int> *Deque<int>::operator[](int index) const;
template denode<double> *Deque<double>::operator[](int index) const;
template denode<std::string> *Deque<std::string>::operator[](int index) const;
template denode<char> *Deque<char>::operator[](int index) const;

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

template void Deque<int>::makeNull();
template void Deque<double>::makeNull();
template void Deque<std::string>::makeNull();
template void Deque<char>::makeNull();

template void Deque<int>::print() const;
template void Deque<double>::print() const;
template void Deque<std::string>::print() const;
template void Deque<char>::print() const;

template denode<int> *Deque<int>::front() const;
template denode<double> *Deque<double>::front() const;
template denode<std::string> *Deque<std::string>::front() const;
template denode<char> *Deque<char>::front() const;

template denode<int> *Deque<int>::rear() const;
template denode<double> *Deque<double>::rear() const;
template denode<std::string> *Deque<std::string>::rear() const;
template denode<char> *Deque<char>::rear() const;

template int Deque<int>::size() const;
template int Deque<double>::size() const;
template int Deque<std::string>::size() const;
template int Deque<char>::size() const;

template std::ostream &operator<<(std::ostream &stream, const Deque<int> &obj);
template std::ostream &operator<<(std::ostream &stream,
                                  const Deque<double> &obj);
template std::ostream &operator<<(std::ostream &stream,
                                  const Deque<std::string> &obj);
template std::ostream &operator<<(std::ostream &stream, const Deque<char> &obj);
