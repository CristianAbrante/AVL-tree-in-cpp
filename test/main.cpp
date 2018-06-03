
#include <iostream>

#include "../include/binary_search_tree/binary_search_tree.h"
#include "../include/AVL_tree/AVL_tree.h"
#include "../include/Menu/Menu.hpp"

int main() {

  BinaryTree<double> *myTree = new AvlTree<double>;


  myTree->Insert(2.0);
  std::cout << *myTree << std::endl << std::endl;

  myTree->Insert(1.0);
  std::cout << *myTree << std::endl << std::endl;

  myTree->Insert(4.0);
  std::cout << *myTree << std::endl << std::endl;

  myTree->Insert(9.0);
  std::cout << *myTree << std::endl << std::endl;

  myTree->Insert(10.0);
  std::cout << *myTree << std::endl << std::endl;
  /*
  myTree.Insert(3);
  std::cout << myTree << std::endl << std::endl;

  myTree.Insert(4);
  std::cout << myTree << std::endl << std::endl;

  myTree.Insert(1);
  std::cout << myTree << std::endl << std::endl;
*/

  std::cout << "Empty Tree : " << myTree->IsEmpty() << std::endl;
  std::cout << "Balanced Tree : " << myTree->IsBalanced() << std::endl;
  std::cout << "Complete Tree : " << myTree->IsComplete() << std::endl;
  std::cout << "Tree Depth : " << myTree->Depth() << std::endl;
  std::cout << "Number Of Nodes : " << myTree->NumberOfNodes() << std::endl;

  std::cout << "Buscar 7 : " << myTree->Search(7) << std::endl;
  std::cout << "Buscar 1 : " << myTree->Search(1) << std::endl;
  std::cout << "Buscar 48 : " << myTree->Search(48) << std::endl << std::endl;

  myTree->Erase(7);

  std::cout << *myTree << std::endl << std::endl;

  /*
  myTree.Erase(20);

  std::cout << myTree << std::endl << std::endl;

  myTree.Erase(8);

  std::cout << myTree << std::endl << std::endl;
  */
  return 0;
}