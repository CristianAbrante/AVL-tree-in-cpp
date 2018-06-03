
#include <iostream>

#include "../include/program_modes/program_modes.h"
#include "../include/binary_search_tree/binary_search_tree.h"
#include "../include/AVL_tree/AVL_tree.h"

int main() {

  std::string title = "\033[44m ---------------- Práctica 6 : Árbol Binario de Búsqueda Balanceado--------------- \033[0m";

  std::vector<std::string> options = {"Modo demostración", "Modo Estadística"};

  int option = showMenu(options, title);



  switch (option) {

    case 0: {

      BinaryTree<double> *binary_tree = new AvlTree<double>;

      AEDA_P5::DemonstrationMode(binary_tree);

      delete binary_tree;

      break;
    }

    case 1: {

      BinaryTree<NumberPlate> *binary_tree = new AvlTree<NumberPlate>;

      AEDA_P5::StatisticsMode(binary_tree);

      delete binary_tree;

      break;
    }

    default: break;
  }



  std::cout << "Programa Hecho por : \n";
  std::cout << setFormat(Text::blueBackground);
  std::cout << setFormat(Text::yellow);
  std::cout << "Cristian Abrante Dorta";
  std::cout << setFormat(Text::resetAttributes) << std::endl;


  return 0;
}