//
// Created by Cristian Abrante Dorta on 8/5/17.
//

#ifndef PRACTICA_6_AVL_TREE_NODE_H
#define PRACTICA_6_AVL_TREE_NODE_H

#include "../binary_tree_node/binary_tree_node.h"


template <class T>
class AVLTreeNode : public BinaryTreeNode<T> {

 public:

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Constructor.
   *
   * @param data_ data that the node is going to store.
   */

  AVLTreeNode(T data_) : BinaryTreeNode<T>(data_) {
    balance_factor_ = 0;
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

  std::shared_ptr<AVLTreeNode<T>> left_node_;

  std::shared_ptr<AVLTreeNode<T>> right_node_;

 private:

  int balance_factor_;

};


#endif //PRACTICA_6_AVL_TREE_NODE_H
