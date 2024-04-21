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
struct double_ended_node {
  type data;
  double_ended_node *prev, *next;
  double_ended_node(type _data = 0) {
    data = _data;
    prev = next = nullptr;
  }
};

template <class type>
struct snode {
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
