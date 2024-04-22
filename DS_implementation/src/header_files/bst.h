#include "nodes.h"
#include <iostream>

template <class type> class Tree {
  treeNode<type> *root;

public:
  Tree();

  ~Tree();

  Tree(const Tree &obj);

  Tree(Tree &&obj);

  treeNode<type> *copyNode(treeNode<type> *masterNode,
                           treeNode<type> *slaveNode);

  void add(type value);

  treeNode<type> *add(type value, treeNode<type> *current);

  void makeNull();

  void makeNull(treeNode<type> *current);

  void printInorder();

  void printPostorder();

  void inorderTraversal(void (*func)(treeNode<type> *),
                        treeNode<type> *current);
  void postorderTraversal(void (*func)(treeNode<type> *),
                          treeNode<type> *current);

  void erase(type value);

  treeNode<type> *erase(type value, treeNode<type> *current);

  treeNode<type> *putToLeft(treeNode<type> *left, treeNode<type> *current);

  void display(std::ofstream &stream);

  void display(const std::string &prefix, std::ofstream &stream,
               const treeNode<type> *current, bool isLeft);
};
