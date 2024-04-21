#include "../header_files/sorted_list.h"

template <class type>
SortedList<type>::SortedList()
    : head(nullptr), tail(nullptr), sorted_head(nullptr), Size(0) {}

template <class type> SortedList<type>::~SortedList() { make_null(); }

template <class type>
SortedList<type>::SortedList(const SortedList &obj) { // copy constructor
  head = nullptr;
  sorted_head = nullptr;
  tail = head;

  snode<type> *cur = obj.head;
  for (; cur; cur = cur->next)
    push(cur->data);
  Size = 0;
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

template <class type> void SortedList<type>::make_null() {
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
}
template <class type>
void SortedList<type>::print_sorted(std::ofstream &stream) const {
  if (sorted_head) {
    for (snode<type> *cur = sorted_head; cur; cur = cur->sorted_next)
      stream << cur->data << " ";
  }
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

template void SortedList<int>::make_null();
template void SortedList<double>::make_null();
template void SortedList<char>::make_null();

template void SortedList<int>::print(std::ofstream &stream) const;
template void SortedList<double>::print(std::ofstream &stream) const;
template void SortedList<char>::print(std::ofstream &stream) const;

template void SortedList<int>::print_sorted(std::ofstream &stream) const;
template void SortedList<double>::print_sorted(std::ofstream &stream) const;
template void SortedList<char>::print_sorted(std::ofstream &stream) const;

template bool SortedList<int>::empty() const;
template bool SortedList<double>::empty() const;
template bool SortedList<char>::empty() const;

template int SortedList<int>::size() const;
template int SortedList<double>::size() const;
template int SortedList<char>::size() const;
