//
// Created by Cristian Abrante Dorta on 8/5/17.
//

#ifndef PRACTICA_6_AVL_TREE_H
#define PRACTICA_6_AVL_TREE_H

#include "../binary_tree/binary_tree.h"
#include "../binary_tree_node/binary_tree_node.h"

enum TypeOfDescent {
  kRightDescent,
  kLeftDescent,
};

template <class T>
class AvlTree : public BinaryTree<T> {

 public:

  AvlTree();

  AvlTree(const std::vector<T> &vector_of_values);

  ~AvlTree();

  bool Insert(const T &data_to_insert);

  bool Insert(const std::vector<T> &vector_to_insert);

  bool Erase(const T &data_to_erase);

 private:

  void InsertAndBalance(node_ptr<T> &node_to_insert,
                        const T &data_to_insert,
                        bool &tree_is_growing);

  void EraseAndBalance(node_ptr<T> &node_to_erase,
                       const T &data_to_erase,
                       bool &tree_is_decreasing);

  void EraseNode(node_ptr<T> &node_to_erase, bool &tree_is_decreasing);

  void FindSubstitute(node_ptr<T> &original_node,
                      node_ptr<T> &substituted_node,
                      bool &tree_is_decreasing);

  void BalanceTheVertexAfterInsert(node_ptr<T> &node_to_balance,
                                   TypeOfDescent type_descent,
                                   bool &tree_is_growing);

  void BalanceTheVertexAfterErase(node_ptr<T> &node_to_balance,
                                  TypeOfDescent type_descent,
                                  bool &tree_is_decreasing);

  // ROTATIONS.

  void LeftLeftRotation(node_ptr<T> &node_to_rotate);

  void LeftRightRotation(node_ptr<T> &node_to_rotate);

  void RightLeftRotation(node_ptr<T> &node_to_rotate);

  void RightRightRotation(node_ptr<T> &node_to_rotate);

};

// PUBLIC METHODS

template <class T>
AvlTree<T>::AvlTree() {
  this->root_ = nullptr;
}

template <class T>
AvlTree<T>::~AvlTree() {
  this->Clear(this->root_);
}

template <class T>
AvlTree<T>::AvlTree(const std::vector<T> &vector_of_values) {
  for (auto value : vector_of_values) {
    Insert(value);
  }
}

template <class T>
bool AvlTree<T>::Insert(const T &data_to_insert) {

  //if (this->Search(data_to_insert)) {
    //return kDataNotInserted;
  //} else {
    bool tree_is_growing = false;
    InsertAndBalance(this->root_, data_to_insert, tree_is_growing);

    return kDataInserted;

  //}
}

template <class T>
bool AvlTree<T>::Insert(const std::vector<T> &vector_to_insert) {

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
bool AvlTree<T>::Erase(const T &data_to_erase) {

  if (this->Search(data_to_erase)) {

    bool tree_is_decreasing = false;

    EraseAndBalance(this->root_, data_to_erase, tree_is_decreasing);
    return kDataErased;

  } else {
    return kDataNotErased;
  }

}

// PRIVATE METHODS.

template <class T>
void AvlTree<T>::InsertAndBalance(node_ptr<T> &node_to_insert,
                                  const T &data_to_insert,
                                  bool &tree_is_growing) {

  if (node_to_insert == nullptr) {

    // Create a new node containing the data.
    node_to_insert  = std::make_shared<BinaryTreeNode<T>>(data_to_insert);
    tree_is_growing = true;

  } else {

    TypeOfDescent type_descent;

    if (data_to_insert < node_to_insert->data()) {

      InsertAndBalance(node_to_insert->left_node_, data_to_insert, tree_is_growing);
      type_descent = kLeftDescent;

    } else {

      InsertAndBalance(node_to_insert->right_node_, data_to_insert, tree_is_growing);
      type_descent = kRightDescent;

    }

    if (tree_is_growing)
      BalanceTheVertexAfterInsert(node_to_insert, type_descent, tree_is_growing);

  }

}

template <class T>
void AvlTree<T>::EraseAndBalance(node_ptr<T> &node_to_erase,
                                 const T &data_to_erase,
                                 bool &tree_is_decreasing) {


  if (data_to_erase < node_to_erase->data()) {
    EraseAndBalance(node_to_erase->left_node_, data_to_erase, tree_is_decreasing);

    if (tree_is_decreasing)
      BalanceTheVertexAfterErase(node_to_erase, kLeftDescent, tree_is_decreasing);

  } else {

    if (data_to_erase > node_to_erase->data()) {
      EraseAndBalance(node_to_erase->right_node_, data_to_erase, tree_is_decreasing);

      if (tree_is_decreasing)
        BalanceTheVertexAfterErase(node_to_erase, kRightDescent, tree_is_decreasing);

    } else {
      EraseNode(node_to_erase, tree_is_decreasing);
    }
  }

}

template <class T>
void AvlTree<T>::EraseNode(node_ptr<T> &node_to_erase, bool &tree_is_decreasing) {

  node_ptr<T> temporal_node = node_to_erase;

  if (node_to_erase->left_node_ == nullptr) {

    node_to_erase = node_to_erase->right_node_;
    tree_is_decreasing = true;

  } else {

    if (node_to_erase->right_node_ == nullptr) {

      node_to_erase = node_to_erase->left_node_;
      tree_is_decreasing = true;

    } else {
      FindSubstitute(node_to_erase, node_to_erase->left_node_, tree_is_decreasing);

      if (tree_is_decreasing)
        BalanceTheVertexAfterErase(node_to_erase, kLeftDescent, tree_is_decreasing);
    }

  }

  temporal_node->right_node_ = nullptr;
  temporal_node->left_node_ = nullptr;

  this->Clear(temporal_node);

}

template <class T>
void AvlTree<T>::FindSubstitute(node_ptr<T> &original_node,
                                node_ptr<T> &substituted_node,
                                bool &tree_is_decreasing) {

  if (substituted_node->right_node_ != nullptr) {
    FindSubstitute(original_node, substituted_node->right_node_, tree_is_decreasing);

    if (tree_is_decreasing)
      BalanceTheVertexAfterErase(substituted_node,kRightDescent, tree_is_decreasing);

  } else {

    node_ptr<T> temporal_node = substituted_node->left_node_;

    substituted_node->left_node_ = original_node->left_node_;

    if (substituted_node->left_node_ == substituted_node) {
      substituted_node->left_node_ = temporal_node;
    }

    substituted_node->right_node_ = original_node->right_node_;

    original_node = substituted_node;
    substituted_node = temporal_node;

    tree_is_decreasing = true;
  }

}


template <class T>
void AvlTree<T>::BalanceTheVertexAfterInsert(node_ptr<T> &node_to_balance,
                                             TypeOfDescent type_descent,
                                             bool &tree_is_growing) {

  switch (node_to_balance->balance_factor()) {

    case 0: {
      int new_balance_factor = type_descent == kRightDescent ? -1 : 1;
      node_to_balance->set_balance_factor(new_balance_factor);

      break;
    }

    case -1: {

      if (type_descent == kRightDescent) {

        if(node_to_balance->right_node_->balance_factor() == -1) {
          RightRightRotation(node_to_balance);
        } else {
          RightLeftRotation(node_to_balance);
        }

      } else {
        node_to_balance->set_balance_factor(0);
      }

      tree_is_growing = false;
      break;
    }

    case 1: {

      if (type_descent == kLeftDescent) {

        if (node_to_balance->left_node_->balance_factor() == 1) {
          LeftLeftRotation(node_to_balance);
        }  else {
          LeftRightRotation(node_to_balance);
        }

      } else {
        node_to_balance->set_balance_factor(0);
      }

      tree_is_growing = false;
      break;
    }

  }

}

template <class T>
void AvlTree<T>::BalanceTheVertexAfterErase(node_ptr<T> &node_to_balance,
                                         TypeOfDescent type_descent,
                                         bool &tree_is_decreasing) {

  switch (node_to_balance->balance_factor()) {

    case 0: {

      node_to_balance->set_balance_factor(type_descent == kRightDescent ? 1 : -1);
      tree_is_decreasing = false;

      break;
    }
    case 1: {

      if (type_descent == kRightDescent) {

        if (node_to_balance->left_node_->balance_factor() < 0) {
          LeftRightRotation(node_to_balance);
        } else {

          if (node_to_balance->left_node_->balance_factor() == 0)
            tree_is_decreasing = false;

          LeftLeftRotation(node_to_balance);
        }

      } else {
        node_to_balance->set_balance_factor(0);
      }
      break;
    }
    case -1: {

      if (type_descent == kLeftDescent) {

        if (node_to_balance->right_node_->balance_factor() > 0) {
          RightLeftRotation(node_to_balance);
        } else {

          if (node_to_balance->right_node_->balance_factor() == 0)
            tree_is_decreasing = false;

          RightRightRotation(node_to_balance);
        }

      } else {
        node_to_balance->set_balance_factor(0);
      }

      break;
    }
  }

}


// ROTATIONS

template <class T>
void AvlTree<T>::LeftLeftRotation(node_ptr<T> &node_to_rotate) {

  node_ptr<T> node1 = node_to_rotate->left_node_;

  node_to_rotate->left_node_ = node1->right_node_;
  node1->right_node_ = node_to_rotate;

  if (node1->balance_factor() == 1) {
    node1->set_balance_factor(0);
    node_to_rotate->set_balance_factor(0);
  } else {
    node1->set_balance_factor(-1);
    node_to_rotate->set_balance_factor(1);
  }

  node_to_rotate = node1;
}

template <class T>
void AvlTree<T>::LeftRightRotation(node_ptr<T> &node_to_rotate) {

  node_ptr<T> node1 = node_to_rotate->left_node_;
  node_ptr<T> node2 = node1->right_node_;

  node_to_rotate->left_node_ = node2->right_node_;
  node2->right_node_ = node_to_rotate;

  node1->right_node_ = node2->left_node_;
  node2->left_node_ = node1;

  node1->set_balance_factor(node2->balance_factor() == -1 ? 1 : 0);

  node_to_rotate->set_balance_factor(node2->balance_factor() == 1 ? -1 : 0);

  node2->set_balance_factor(0);

  node_to_rotate = node2;
}

template <class T>
void AvlTree<T>::RightLeftRotation(node_ptr<T> &node_to_rotate) {

  node_ptr<T> node1 = node_to_rotate->right_node_;
  node_ptr<T> node2 = node1->left_node_;

  node_to_rotate->right_node_ = node2->left_node_;
  node2->left_node_ = node_to_rotate;

  node1->left_node_ = node2->right_node_;
  node2->right_node_ = node1;

  node1->set_balance_factor(node2->balance_factor() == 1 ? -1 : 0);

  node_to_rotate->set_balance_factor(node2->balance_factor() == -1 ? 1 : 0);

  node2->set_balance_factor(0);

  node_to_rotate = node2;

}

template <class T>
void AvlTree<T>::RightRightRotation(node_ptr<T> &node_to_rotate) {
  node_ptr<T> node1 = node_to_rotate->right_node_;

  node_to_rotate->right_node_ = node1->left_node_;
  node1->left_node_ = node_to_rotate;

  if (node1->balance_factor() == -1) {
    node1->set_balance_factor(0);
    node_to_rotate->set_balance_factor(0);
  } else {
    node1->set_balance_factor(1);
    node_to_rotate->set_balance_factor(-1);
  }

  node_to_rotate = node1;
}


#endif //PRACTICA_6_AVL_TREE_H
