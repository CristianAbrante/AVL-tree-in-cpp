cmake_minimum_required(VERSION 3.7)
project(AVLTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp include/Menu/FormattedOutput.cpp include/binary_search_tree/binary_search_tree.h include/Menu/Menu.cpp include/Menu/TerminalAttributes.cpp include/number_plate/number_plate.h src/number_plate/number_plate.cc include/binary_tree/binary_tree.h include/binary_tree_node/binary_tree_node.h include/program_modes/program_modes.h src/program_modes/program_modes.cc include/AVL_tree_node/AVL_tree_node.h include/AVL_tree/AVL_tree.h)
add_executable(AVLTree.out ${SOURCE_FILES})