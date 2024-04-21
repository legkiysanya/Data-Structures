#include "../header_files/queue.h"
#include <iostream>

template <class type>
Queue<type>::Queue() : Size(0), head(nullptr), tail(nullptr) {} // constructor

template <class type> Queue<type>::~Queue() { make_null(); } // deconstructor

template <class type> Queue<type>::Queue(const Queue &obj) { // copy constructor
  head = new node<type>;
  tail = new node<type>;
  head = tail;

  node<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    push(cur->data);
  Size = 0;
}

template <class type> node<type> *Queue<type>::operator[](int index) {
  if (index >= Size || index < 0) {
    std::cout << "incorrect index value \n";
    exit(1);
  }

  node<type> *cur = head;
  int i = 0;
  while (cur && i < Size && i != index) {
    cur = cur->next;
    i++;
  }
  return cur;
}

template <class type> void Queue<type>::push(type n) {
  node<type> *temp;
  temp = new node<type>(n);

  if (head == nullptr) {
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = tail->next;
  }
  Size++;
}

template <class type> void Queue<type>::make_null() {
  while (head) {
    node<type> *tmp = head;
    head = head->next;
    delete tmp;
  }
  tail = nullptr;
  Size = 0;
}

template <class type> void Queue<type>::erase(type n) {
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

template <class type> node<type> *Queue<type>::front() const {
  if (!empty())
    return head;
  else
    return nullptr;
}

template <class type> void Queue<type>::pop() {
  if (head) {
    node<type> *tmp = head;
    head = head->next;

    if (!head)
      tail = nullptr;
    delete tmp;
    Size--;
  }
}

template <class type> bool Queue<type>::empty() const {
  return head == tail && !head;
}

template <class type> int Queue<type>::size() const { return Size; }

template <class type>
std::ostream &operator<<(std::ostream &stream, const Queue<type> &obj) {
  if (obj.head) {
    for (node<type> *cur = obj.head; cur; cur = cur->next)
      stream << cur->data << " ";
  }
  return stream;
}

template Queue<int>::Queue();
template Queue<double>::Queue();
template Queue<std::string>::Queue();
template Queue<char>::Queue();

template Queue<int>::~Queue();
template Queue<double>::~Queue();
template Queue<std::string>::~Queue();
template Queue<char>::~Queue();

template Queue<int>::Queue(const Queue &obj);
template Queue<double>::Queue(const Queue &obj);
template Queue<std::string>::Queue(const Queue &obj);
template Queue<char>::Queue(const Queue &obj);

template node<int> *Queue<int>::operator[](int index);
template node<double> *Queue<double>::operator[](int index);
template node<std::string> *Queue<std::string>::operator[](int index);
template node<char> *Queue<char>::operator[](int index);

template void Queue<int>::push(int n);
template void Queue<double>::push(double n);
template void Queue<std::string>::push(std::string n);
template void Queue<char>::push(char n);

template void Queue<int>::make_null();
template void Queue<double>::make_null();
template void Queue<std::string>::make_null();
template void Queue<char>::make_null();

template void Queue<int>::erase(int n);
template void Queue<double>::erase(double n);
template void Queue<std::string>::erase(std::string n);
template void Queue<char>::erase(char n);

template node<int> *Queue<int>::front() const;
template node<double> *Queue<double>::front() const;
template node<std::string> *Queue<std::string>::front() const;
template node<char> *Queue<char>::front() const;

template void Queue<int>::pop();
template void Queue<double>::pop();
template void Queue<std::string>::pop();
template void Queue<char>::pop();

template bool Queue<int>::empty() const;
template bool Queue<double>::empty() const;
template bool Queue<std::string>::empty() const;
template bool Queue<char>::empty() const;

template int Queue<int>::size() const;
template int Queue<double>::size() const;
template int Queue<std::string>::size() const;
template int Queue<char>::size() const;

template std::ostream &operator<<(std::ostream &stream, const Queue<int> &obj);
template std::ostream &operator<<(std::ostream &stream, const Queue<double> &obj);
template std::ostream &operator<<(std::ostream &stream, const Queue<std::string> &obj);
template std::ostream &operator<<(std::ostream &stream, const Queue<char> &obj);
