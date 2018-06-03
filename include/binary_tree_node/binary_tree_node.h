//
// Created by cristian on 30/04/17.
//

#ifndef PRACTICA_5_BINARY_TREE_NODE_H
#define PRACTICA_5_BINARY_TREE_NODE_H

//TODO:Try to fix herarchy in the nodes.

#include <memory>
#include <ostream>

template <class T>
class BinaryTreeNode {

 public:

  BinaryTreeNode(T data_) : data_(data_) {

    balance_factor_ = 0;

    left_node_ = nullptr;
    right_node_ = nullptr;
  }

  T data(void) const {
    return data_;
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief method that return the value of the
   *        balance factor of the AVL node.
   *
   * @return -1 if right vertex is deeper than left vertex,
   *          0 if right vertex as deeper as left vertex,
   *          1 if right vertex is less deeper than left vertex.
   */

  int balance_factor(void) const {
    return balance_factor_;
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that sets the value of the balance factor
   *        of the node.
   *
   *
   *
   * @param balance_factor value that only can be -1, 0 or 1.
   */

  void set_balance_factor(int balance_factor) {

    if (balance_factor == -1 ||
        balance_factor == 0  ||
        balance_factor == 1) {
      balance_factor_ = balance_factor;
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const BinaryTreeNode &node) {
    os << "[" << node.data_ << "]";
    return os;
  }

  std::shared_ptr<BinaryTreeNode<T> > left_node_;

  std::shared_ptr<BinaryTreeNode<T> > right_node_;

 private:

  T data_;

  int balance_factor_;

};

#endif //PRACTICA_5_BINARY_TREE_NODE_H
