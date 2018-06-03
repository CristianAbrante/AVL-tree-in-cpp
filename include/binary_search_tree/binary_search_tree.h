//
// Created by cristian on 30/04/17.
//

#ifndef PRACTICA_5_BINARY_SEARCH_TREE_H
#define PRACTICA_5_BINARY_SEARCH_TREE_H

#include "../binary_tree/binary_tree.h"

/**
 * @author Cristian Abrante Dorta
 * @date May 2017
 *
 * @class Class that represent a Binary Tree with ordered insertion
 *        and elimination.
 *
 * @tparam T type of data that the tree is going to store.
 */

template <class T>
class BinarySearchTree : public BinaryTree<T> {

 public:

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Default constructor of the class.
   */

  BinarySearchTree() {
    this->root_ = nullptr;
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Constructor.
   *
   * @param vector_of_values vector that contains the values witch we want
   *                         to inizialize the vector with.
   */

  BinarySearchTree(const std::vector<T> vector_of_values) {
    for (auto value : vector_of_values) {
      Insert(value);
    }
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Destructor of the class.
   */

  ~BinarySearchTree() {
    this->Clear(this->root_);
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that inserts a data in the tree.
   *
   * @details If the data we want to insert is already on the tree,
   *          false is returned.
   *
   * @param data_to_insert Data we want to be inserted in the tree.
   * @return true if data is inserted and false otherwise.
   */

  bool Insert(const T &data_to_insert);

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that inserts a sequence of data in the tree,
   *
   * @details If any data we want to insert is already on the tree,
   *          false is returned, and any value is inserted.
   *
   * @param vector_to_insert Sequence that we want to insert.
   * @return true if data is inserted and false otherwise.
   */

  bool Insert(const std::vector<T> &vector_to_insert);

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that erase the specific data of the tree.
   *
   * @details If the data we want to insert is not on the tree,
   *          false is returned.
   *
   * @param data_to_insert Data we want to be inserted in the tree.
   * @return true if data is erased and false otherwise.
   */

  bool Erase(const T &data_to_erase);

 private:

  void EraseNode(node_ptr<T> &node_to_erase);

  void FindSubstitute(node_ptr<T> &original_node, node_ptr<T> &substituted_node);

};

// PUBLIC METHODS

template <class T>
bool BinarySearchTree<T>::Insert(const T &data_to_insert) {

  node_ptr<T> &node_to_insert = this->SearchAtVertex(this->root_, data_to_insert);

  if (node_to_insert == nullptr) {
    node_to_insert = std::make_shared<BinaryTreeNode<T> >(data_to_insert);
    return kDataInserted;
  } else {
    return kDataNotInserted;
  }

}

template <class T>
bool BinarySearchTree<T>::Insert(const std::vector<T> &vector_to_insert) {

  int position = 0;
  TreeOperationResult insert_operation = kDataInserted;

  while (position < vector_to_insert.size() &&
      insert_operation == kDataInserted) {
    if (this->Search(vector_to_insert[position])) {
      insert_operation = kDataNotInserted;
    }
    position++;
  }

  if (insert_operation == kDataInserted) {

    for (auto value : vector_to_insert) {
      this->Insert(value);
    }

    return kDataInserted;

  } else {
    return kDataNotInserted;
  }


}

template <class T>
bool BinarySearchTree<T>::Erase(const T &data_to_erase) {

  node_ptr<T> &node_where_erase = this->SearchAtVertex(this->root_, data_to_erase);

  if (node_where_erase != nullptr) {

    EraseNode(node_where_erase);
    return kDataErased;

  } else {
    return kDataNotErased;
  }
}

// PRIVATE METHODS

template <class T>
void BinarySearchTree<T>::EraseNode(node_ptr<T> &node_to_erase) {

  node_ptr<T> temporal_node = node_to_erase;

  if (node_to_erase->left_node_ == nullptr) {
    node_to_erase = node_to_erase->right_node_;
  } else {

    if (node_to_erase->right_node_ == nullptr) {
      node_to_erase = node_to_erase->left_node_;
    } else {
      FindSubstitute(node_to_erase, node_to_erase->left_node_);
    }

  }

  temporal_node->right_node_ = nullptr;
  temporal_node->left_node_ = nullptr;

  this->Clear(temporal_node);

}

template <class T>
void BinarySearchTree<T>::FindSubstitute(node_ptr<T> &original_node,
                                         node_ptr<T> &substituted_node) {

  if (substituted_node->right_node_ != nullptr) {
    FindSubstitute(original_node, substituted_node->right_node_);
  } else {

    node_ptr<T> temporal_node = substituted_node->left_node_;

    substituted_node->left_node_ = original_node->left_node_;

    if (substituted_node->left_node_ == substituted_node) {
      substituted_node->left_node_ = temporal_node;
    }

    substituted_node->right_node_ = original_node->right_node_;

    original_node = substituted_node;
    substituted_node = temporal_node;
  }

}



#endif //PRACTICA_5_BINARY_SEARCH_TREE_H
