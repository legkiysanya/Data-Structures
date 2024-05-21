#include "../header_files/sorted_list.h"

// constructor
template <class type>
SortedList<type>::SortedList()
    : head(nullptr), tail(nullptr), sorted_head(nullptr), Size(0) {}

// deconstructor
template <class type> SortedList<type>::~SortedList() { makeNull(); }

// copy constructor
template <class type>
SortedList<type>::SortedList(const SortedList &obj)
    : head(nullptr), tail(nullptr), sorted_head(nullptr),
      Size(obj.Size) { 
  snode<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    push(cur->data);
}

// move constructor
template <class type>
SortedList<type>::SortedList(SortedList &&obj)
    : head(obj.head), tail(obj.tail), sorted_head(obj.sorted_head),
      Size(obj.Size) {
  obj.head = obj.sorted_head = obj.tail = nullptr;
  obj.Size = 0;
}

// assignment operator
template <class type>
SortedList<type> &SortedList<type>::operator=(const SortedList &obj) {
  makeNull();
  head = nullptr;
  sorted_head = nullptr;
  tail = head;

  snode<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    push(cur->data);
  Size = obj.Size;

  return *this;
}

// move assignment operator
template <class type>
SortedList<type> &SortedList<type>::operator=(SortedList &&obj) {
  makeNull();
  head = obj.head;
  sorted_head = obj.sorted_head;
  tail = obj.tail;
  Size = obj.Size;
  obj.head = obj.sorted_head = obj.tail = nullptr;
  obj.Size = 0;

  return *this;
}

template <class type> void SortedList<type>::push(type n) {
  snode<type> *tmp;
  tmp = new snode<type>(n);

  if (head == tail && !head) {
    head = tail = tmp;
  } else {
    tail->next = tmp;
    tail = tmp;
  }

  if (!sorted_head || sorted_head->data > n) {
    tmp->sorted_next = sorted_head;
    sorted_head = tmp;
  } else {
    snode<type> *prev, *cur;
    cur = prev = sorted_head;
    while (cur && tmp->data > cur->data) {
      prev = cur;
      cur = cur->sorted_next;
    }
    prev->sorted_next = tmp;
    tmp->sorted_next = cur;
  }
  Size++;
}

template <class type> void SortedList<type>::erase(type n) {
  if (!head)
    return;
  snode<type> *item;
  if (head->data == n) {
    item = head;
    head = head->next;
  } else {
    snode<type> *cur = head;
    while (cur->next && cur->next->data != n)
      cur = cur->next;
    if (!cur->next)
      return;
    item = cur->next;
    cur->next = item->next;
  }

  if (sorted_head->data == n) {
    sorted_head = sorted_head->sorted_next;
  } else {
    snode<type> *cur = sorted_head;
    while (cur->sorted_next && cur->sorted_next->data != n)
      cur = cur->sorted_next;
    cur->sorted_next = cur->sorted_next->sorted_next;
  }
  delete item;
  Size--;
}

template <class type> snode<type> *SortedList<type>::front() const {
  if (!empty())
    return head;
  else
    return nullptr;
}

template <class type> snode<type> *SortedList<type>::sorted_front() const {
  if (!empty())
    return sorted_head;
  else
    return nullptr;
}

template <class type> void SortedList<type>::makeNull() {
  while (head) {
    snode<type> *tmp = head;
    head = head->next;
    delete tmp;
  }

  tail = sorted_head = nullptr;
  Size = 0;
}

template <class type>
void SortedList<type>::print(std::ofstream &stream) const {
  if (head) {
    for (snode<type> *cur = head; cur; cur = cur->next)
      stream << cur->data << " ";
  }
  stream << "\n";
}

template <class type>
void SortedList<type>::printSorted(std::ofstream &stream) const {
  if (sorted_head) {
    for (snode<type> *cur = sorted_head; cur; cur = cur->sorted_next)
      stream << cur->data << " ";
  }
  stream << "\n";
}

template <class type> bool SortedList<type>::empty() const {
  return head == tail && !head;
}

template <class type> int SortedList<type>::size() const { return Size; }

template SortedList<int>::SortedList();
template SortedList<double>::SortedList();
template SortedList<char>::SortedList();

template SortedList<int>::~SortedList();
template SortedList<double>::~SortedList();
template SortedList<char>::~SortedList();

template SortedList<int>::SortedList(const SortedList &obj);
template SortedList<double>::SortedList(const SortedList &obj);
template SortedList<char>::SortedList(const SortedList &obj);

template SortedList<int>::SortedList(SortedList &&obj);
template SortedList<double>::SortedList(SortedList &&obj);
template SortedList<char>::SortedList(SortedList &&obj);

template SortedList<int> &SortedList<int>::operator=(const SortedList &obj);
template SortedList<double> &
SortedList<double>::operator=(const SortedList &obj);
template SortedList<char> &SortedList<char>::operator=(const SortedList &obj);

template SortedList<int> &SortedList<int>::operator=(SortedList &&obj);
template SortedList<double> &SortedList<double>::operator=(SortedList &&obj);
template SortedList<char> &SortedList<char>::operator=(SortedList &&obj);

template void SortedList<int>::push(int n);
template void SortedList<double>::push(double n);
template void SortedList<char>::push(char n);

template void SortedList<int>::erase(int n);
template void SortedList<double>::erase(double n);
template void SortedList<char>::erase(char n);

template snode<int> *SortedList<int>::front() const;
template snode<double> *SortedList<double>::front() const;
template snode<char> *SortedList<char>::front() const;

template snode<int> *SortedList<int>::sorted_front() const;
template snode<double> *SortedList<double>::sorted_front() const;
template snode<char> *SortedList<char>::sorted_front() const;

template void SortedList<int>::makeNull();
template void SortedList<double>::makeNull();
template void SortedList<char>::makeNull();

template void SortedList<int>::print(std::ofstream &stream) const;
template void SortedList<double>::print(std::ofstream &stream) const;
template void SortedList<char>::print(std::ofstream &stream) const;

template void SortedList<int>::printSorted(std::ofstream &stream) const;
template void SortedList<double>::printSorted(std::ofstream &stream) const;
template void SortedList<char>::printSorted(std::ofstream &stream) const;

template bool SortedList<int>::empty() const;
template bool SortedList<double>::empty() const;
template bool SortedList<char>::empty() const;

template int SortedList<int>::size() const;
template int SortedList<double>::size() const;
template int SortedList<char>::size() const;
