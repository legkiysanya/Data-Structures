#include "../header_files/bst.h"
#include "../header_files/nodes.h"
#include <fstream>
#include <iostream>

template <class type> void printNode(treeNode<type> *node) {
  std::cout << node->data << "\n";
}

template <class type> void deleteNode(treeNode<type> *node) { delete node; }

template <class type> Tree<type>::Tree() { root = nullptr; }

template <class type> Tree<type>::Tree(const Tree &obj) {
  root = copyNode(obj.root, root);
}

template <class type> Tree<type>::Tree(Tree &&obj) {
  root = obj.root;
  obj.root = nullptr;
}

template <class type>
treeNode<type> *Tree<type>::copyNode(treeNode<type> *masterNode,
                                     treeNode<type> *slaveNode) {
  if (masterNode == nullptr)
    return nullptr;
  slaveNode = new treeNode<type>(masterNode->data);
  slaveNode->left = copyNode(masterNode->left, slaveNode->left);
  slaveNode->right = copyNode(masterNode->right, slaveNode->right);
  return slaveNode;
}

template <class type> Tree<type>::~Tree() { makeNull(root); }

template <class type> void Tree<type>::add(type value) {
  root = add(value, root);
}

template <class type>
treeNode<type> *Tree<type>::add(type value, treeNode<type> *current) {
  if (current == nullptr) {
    current = new treeNode<type>(value);
  } else if (value < current->data) {
    current->left = add(value, current->left);
  } else if (value > current->data) {
    current->right = add(value, current->right);
  }
  return current;
}

template <class type> void Tree<type>::makeNull() { makeNull(root); }

template <class type> void Tree<type>::makeNull(treeNode<type> *current) {
  postorderTraversal(deleteNode, root);
  root = nullptr;
}

template <class type> void Tree<type>::printInorder() {
  inorderTraversal(printNode, root);
}

template <class type> void Tree<type>::printPostorder() {
  postorderTraversal(printNode, root);
}

// base inorder traversal function with two arguments
template <class type>
void Tree<type>::inorderTraversal(void (*func)(treeNode<type> *),
                                  treeNode<type> *current) {
  if (current == nullptr)
    return;
  inorderTraversal(func, current->left);
  func(current);
  inorderTraversal(func, current->right);
}

// base postorder traversal function with two arguments
template <class type>
void Tree<type>::postorderTraversal(void (*func)(treeNode<type> *),
                                    treeNode<type> *current) {
  if (current == nullptr)
    return;
  postorderTraversal(func, current->left);
  postorderTraversal(func, current->right);
  func(current);
}

template <class type> void Tree<type>::erase(type value) {
  root = erase(value, root);
}

template <class type>
treeNode<type> *Tree<type>::erase(type value, treeNode<type> *current) {
  treeNode<type> *left = nullptr, *right = nullptr;
  if (current != nullptr) {
    if (current->data == value) {
      left = current->left;
      right = current->right;
      delete current;
      current = right;
      if (left != nullptr)
        current->left = putToLeft(left, current->left);
    } else if (current->data > value) {
      current->left = erase(value, current->left);
    } else if (current->data < value) {
      current->right = erase(value, current->right);
    }
  }
  return current;
}

template <class type>
treeNode<type> *Tree<type>::putToLeft(treeNode<type> *left,
                                      treeNode<type> *current) {
  if (current == nullptr)
    current = left;
  else
    current = putToLeft(left, current->left);

  return current;
}

template <class type> void Tree<type>::display(std::ofstream &stream) {
  display("", stream, root, false);
}

template <class type>
void Tree<type>::display(const std::string &prefix, std::ofstream &stream,
                         const treeNode<type> *current, bool isLeft) {
  if (current == nullptr)
    return;
  stream << prefix;
  stream << (isLeft ? "├──" : "└──");
  stream << current->data << "\n";

  display(prefix + (isLeft ? "│   " : "    "), stream, current->left, true);
  display(prefix + (isLeft ? "│   " : "    "), stream, current->right, false);
}

template void Tree<int>::display(std::ofstream &stream);
template void Tree<double>::display(std::ofstream &stream);
template void Tree<char>::display(std::ofstream &stream);

template void Tree<int>::display(const std::string &prefix,
                                 std::ofstream &stream,
                                 const treeNode<int> *current, bool isLeft);
template void Tree<double>::display(const std::string &prefix,
                                    std::ofstream &stream,
                                    const treeNode<double> *current,
                                    bool isLeft);
template void Tree<char>::display(const std::string &prefix,
                                  std::ofstream &stream,
                                  const treeNode<char> *current, bool isLeft);

template Tree<int>::Tree();
template Tree<double>::Tree();
template Tree<char>::Tree();

template Tree<int>::Tree(const Tree &obj);
template Tree<double>::Tree(const Tree &obj);
template Tree<char>::Tree(const Tree &obj);

template Tree<int>::Tree(Tree &&obj);
template Tree<double>::Tree(Tree &&obj);
template Tree<char>::Tree(Tree &&obj);

template treeNode<int> *Tree<int>::copyNode(treeNode<int> *masterNode,
                                             treeNode<int> *slaveNode);
template treeNode<double> *Tree<double>::copyNode(treeNode<double> *masterNode,
                                             treeNode<double> *slaveNode);
template treeNode<char> *Tree<char>::copyNode(treeNode<char> *masterNode,
                                             treeNode<char> *slaveNode);
template Tree<int>::~Tree();
template Tree<double>::~Tree();
template Tree<char>::~Tree();

template void Tree<int>::add(int value);
template void Tree<double>::add(double value);
template void Tree<char>::add(char value);

template treeNode<int> *Tree<int>::add(int value, treeNode<int> *current);
template treeNode<double> *Tree<double>::add(double value,
                                             treeNode<double> *current);
template treeNode<char> *Tree<char>::add(char value, treeNode<char> *current);

template void Tree<int>::makeNull();
template void Tree<double>::makeNull();
template void Tree<char>::makeNull();

template void Tree<int>::makeNull(treeNode<int> *current);
template void Tree<double>::makeNull(treeNode<double> *current);
template void Tree<char>::makeNull(treeNode<char> *current);

template void Tree<int>::printInorder();
template void Tree<double>::printInorder();
template void Tree<char>::printInorder();

template void Tree<int>::printPostorder();
template void Tree<double>::printPostorder();
template void Tree<char>::printPostorder();

template void Tree<int>::inorderTraversal(void (*func)(treeNode<int> *),
                                          treeNode<int> *current);
template void Tree<double>::inorderTraversal(void (*func)(treeNode<double> *),
                                             treeNode<double> *current);
template void Tree<char>::inorderTraversal(void (*func)(treeNode<char> *),
                                           treeNode<char> *current);

template void Tree<int>::postorderTraversal(void (*func)(treeNode<int> *),
                                            treeNode<int> *current);
template void Tree<double>::postorderTraversal(void (*func)(treeNode<double> *),
                                               treeNode<double> *current);
template void Tree<char>::postorderTraversal(void (*func)(treeNode<char> *),
                                             treeNode<char> *current);

template void Tree<int>::erase(int value);
template void Tree<double>::erase(double value);
template void Tree<char>::erase(char value);

template treeNode<int> *Tree<int>::erase(int value, treeNode<int> *current);
template treeNode<double> *Tree<double>::erase(double value,
                                               treeNode<double> *current);
template treeNode<char> *Tree<char>::erase(char value, treeNode<char> *current);

template treeNode<int> *Tree<int>::putToLeft(treeNode<int> *left,
                                             treeNode<int> *current);
template treeNode<double> *Tree<double>::putToLeft(treeNode<double> *left,
                                                   treeNode<double> *current);
template treeNode<char> *Tree<char>::putToLeft(treeNode<char> *left,
                                               treeNode<char> *current);
