//
// Created by cristian on 1/05/17.
//

#ifndef PRACTICA_5_PROGRAM_MODES_H
#define PRACTICA_5_PROGRAM_MODES_H

#include "../Menu/Menu.hpp"
#include "../binary_tree/binary_tree.h"
#include "../number_plate/number_plate.h"

#include <iomanip>

namespace AEDA_P5 {

void DemonstrationMode(BinaryTree<double> *&binary_tree);

void StatisticsMode(BinaryTree<NumberPlate> *&test_tree);

void EvaluateSearchOperationAtTree(const BinaryTree<NumberPlate> *test_tree,
                                   const std::vector<NumberPlate> test_bench);

}


#endif //PRACTICA_5_PROGRAM_MODES_H
