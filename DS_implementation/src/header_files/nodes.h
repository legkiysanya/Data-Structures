#ifndef NODES_H
#define NODES_H

template <class type>
struct node {
   type data;
   node *next;
   node(type _data = 0) {
      data = _data;
      next = nullptr;
   }
};

template <class type>
struct denode { // denode -- double ended node
  type data;
  denode *prev, *next;
  denode(type _data = 0) {
    data = _data;
    prev = next = nullptr;
  }
};

template <class type>
struct snode { // snode -- sorted node
  type data;
  snode *next;
  snode *sorted_next;
  snode(type _data = 0) {
    data = _data;
    next = nullptr;
    sorted_next = nullptr;
  }
};

template <class type>
struct treeNode {
   treeNode *left, *right;
   type data;
   treeNode(type _data = 0) : left(nullptr), right(nullptr), data(_data) {};
};

#endif // !NODES_H
