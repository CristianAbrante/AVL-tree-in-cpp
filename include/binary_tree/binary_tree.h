//
// Created by cristian on 30/04/17.
//

#ifndef PRACTICA_5_BINARY_TREE_H
#define PRACTICA_5_BINARY_TREE_H

#include "../binary_tree_node/binary_tree_node.h"

#include <algorithm>
#include <memory>
#include <ostream>
#include <queue>
#include <utility>

template <typename T>
using node_ptr = std::shared_ptr<BinaryTreeNode<T>>;

template <class T>
using pair_ptr_size = std::pair<std::shared_ptr<BinaryTreeNode<T>>, size_t >;

enum TreeOperationResult {
  kDataFound = true,
  kDataNotFound = false,
  kDataInserted = true,
  kDataNotInserted = false,
  kDataErased = true,
  kDataNotErased = false,
};

enum StateOfTree {
  kEmpty = true,
  kNotEmpty = false,
  kBalanced = true,
  kNotBalanced = false,
  kComplete = true,
  kNotComplete = false,
};

/**
 * @author Cristian Abrante Dorta
 * @date May 2017
 *
 * @class Virtual Class that represent a Binary Tree with
 *        its main functions.
 *
 * @tparam T type of data that the tree is going to store.
 */

template <class T>
class BinaryTree {

 public:

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Default constructor of the class.
   */

  BinaryTree() {
    root_ = nullptr;
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Destructor of the class.
   */

  virtual ~BinaryTree() {
    Clear(root_);
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that determinate if the tree is empty,
   *        without any nodes.
   *
   * @return true if tree is empty and false otherwise.
   */

  bool IsEmpty(void) const {
    return root_ == nullptr ? kEmpty : kNotEmpty;
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that determinate if tree is balanced.
   *        This means that the difference of depth of the
   *        2 subtrees of every vertex is not greater than 1.
   *
   * @return true if tree is balanced, false otherwise.
   */

  bool IsBalanced(void) const {
    return VertexIsBalanced(root_);
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that determinate if Tree is complete.
   *        This means that the difference between the number
   *        of nodes of the subtrees of every vertex is not greater
   *        than 1.
   *
   * @return true if tree is complete, and false otherwise.
   */

  bool IsComplete(void) const {
    return VertexIsComplete(root_);
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that determinate the maximun depth of the tree.
   *
   * @return The depth of the tree.
   */

  size_t Depth(void) const {
    return VertexDepth(root_);
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that determinates the number of nodes of the tree.
   *
   * @return NUmber of nodes of the tree;
   */

  size_t NumberOfNodes(void) const {
    return root_ == nullptr ? 0 : NumberOfNodesOfTheVertex(root_);
  }

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Method that search an specific value in the tree.
   *
   * @param data_to_search Value we want to search.
   * @return true if Data is in the tree and false otherwise.
   */

  bool Search(const T &data_to_search) const {
    return SearchAtVertex(root_, data_to_search) != nullptr ?
           kDataFound : kDataNotFound;
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

  virtual bool Insert(const T &data_to_insert) = 0;

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

  virtual bool Insert(const std::vector<T> &vector_to_insert) = 0;

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

  virtual bool Erase(const T &data_to_erase) = 0;

  /**
   * @author Cristian Abrante Dorta
   * @date May 2017
   *
   * @brief Stream output iterator
   *
   * @param os
   * @param tree
   * @return
   */

  friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree) {

    std::queue<pair_ptr_size<T>> level_queue;
    size_t current_level = 0;

    level_queue.push(pair_ptr_size<T> (tree.root_, 0));
    os << "\tNivel " << current_level << " : ";

    while (!level_queue.empty()) {

      auto   extracted_node  = std::get<0>(level_queue.front());
      size_t extracted_level = std::get<1>(level_queue.front());
      level_queue.pop();

      if (extracted_level > current_level) {
        current_level = extracted_level;
        os << std::endl << "\tNivel " << current_level << " : ";
      }

      if (extracted_node != nullptr) {
        os << *extracted_node << " ";

        level_queue.push(pair_ptr_size<T> (extracted_node->left_node_, current_level + 1));
        level_queue.push(pair_ptr_size<T> (extracted_node->right_node_, current_level + 1));

      } else {
        os << " X ";
      }

    }

    return os;
  }

 protected:

  void Clear(node_ptr<T> &node_to_erase);

  const node_ptr<T> & SearchAtVertex(const node_ptr<T> &node_to_examine,
                                     const T &data_to_search) const;

  node_ptr<T> & SearchAtVertex(node_ptr<T> &node_to_examine,
                               const T &data_to_search) const;

  node_ptr<T> root_;

 private:

  bool VertexIsBalanced(const node_ptr<T> &node_to_examine) const;

  bool VertexIsComplete(const node_ptr<T> &node_to_examine) const;

  size_t VertexDepth(const node_ptr<T> &node_to_examine) const;

  size_t NumberOfNodesOfTheVertex(const node_ptr<T> &node_to_examine) const;

};

// PROTECTED METHODS

template <class T>
void BinaryTree<T>::Clear(node_ptr<T> &node_to_erase) {

  if (node_to_erase != nullptr) {

    Clear(node_to_erase->left_node_);
    Clear(node_to_erase->right_node_);

    if (node_to_erase.unique() == true) {
      node_to_erase.reset();
      node_to_erase = nullptr;
    }
  }

}

template <class T>
const node_ptr<T> & BinaryTree<T>::SearchAtVertex(const node_ptr<T> &node_to_examine,
                                                  const T &data_to_search) const {

  if (node_to_examine == nullptr)
    return node_to_examine;

  if (node_to_examine->data() == data_to_search) {
    return node_to_examine;
  }

  if (data_to_search < node_to_examine->data()) {
    return SearchAtVertex(node_to_examine->left_node_, data_to_search);
  }

  return SearchAtVertex(node_to_examine->right_node_, data_to_search);

}

template <class T>
node_ptr<T> &BinaryTree<T>::SearchAtVertex(node_ptr<T> &node_to_examine,
                                           const T &data_to_search) const {

  if (node_to_examine == nullptr)
    return node_to_examine;

  if (node_to_examine->data() == data_to_search) {
    return node_to_examine;
  }

  if (data_to_search < node_to_examine->data()) {
    return SearchAtVertex(node_to_examine->left_node_, data_to_search);
  }

  return SearchAtVertex(node_to_examine->right_node_, data_to_search);

}

// PRIVATE METHODS

template <class T>
bool BinaryTree<T>::VertexIsBalanced(const node_ptr<T> &node_to_examine) const {

  if (node_to_examine == nullptr)
    return kBalanced;

  int balanced_factor = VertexDepth(node_to_examine->left_node_) -
                        VertexDepth(node_to_examine->right_node_);

  if (balanced_factor >= -1 && balanced_factor <= 1)
    if (VertexIsBalanced(node_to_examine->right_node_) == kBalanced &&
        VertexIsBalanced(node_to_examine->left_node_) == kBalanced)
          return kBalanced;

  return kNotBalanced;
}

template <class T>
bool BinaryTree<T>::VertexIsComplete(const node_ptr<T> &node_to_examine) const {

  if (node_to_examine == nullptr)
    return kComplete;

  int complete_factor = NumberOfNodesOfTheVertex(node_to_examine->left_node_) -
                        NumberOfNodesOfTheVertex(node_to_examine->right_node_);

  if (complete_factor>= -1 && complete_factor <= 1)
    if (VertexIsComplete(node_to_examine->right_node_) == kComplete &&
        VertexIsComplete(node_to_examine->left_node_) == kComplete)
          return kComplete;

  return kNotComplete;

}

template <class T>
size_t BinaryTree<T>::VertexDepth(const node_ptr<T> &node_to_examine) const {

  if (node_to_examine == nullptr)
    return 0;

  size_t right_node_depth = VertexDepth(node_to_examine->right_node_);
  size_t left_node_depth = VertexDepth(node_to_examine->left_node_);

  return std::max(right_node_depth, left_node_depth) + 1;

}

template <class T>
size_t BinaryTree<T>::NumberOfNodesOfTheVertex(const node_ptr<T> &node_to_examine) const {

  if (node_to_examine == nullptr)
    return 0;

  return NumberOfNodesOfTheVertex(node_to_examine->right_node_) +
         NumberOfNodesOfTheVertex(node_to_examine->left_node_) + 1;

}


#endif //PRACTICA_5_BINARY_TREE_H