//
// Created by cristian on 1/05/17.
//

#include "../../include/program_modes/program_modes.h"

void AEDA_P5::DemonstrationMode(BinaryTree<double> *&binary_tree) {

  std::string   options_prompt = "\t   \033[44m -- MODO DEMOSTRACIÓN -- \033[0m \n\n\t "
      "Seleccione la operación que quiere realizar en el árbol:";

  OptionsList_t user_options = {"Salir:",
                                "Mostrar el árbol:",
                                "Insertar clave:",
                                "Eliminar Clave:",
                                "Buscar Clave:",
                                "Determinar si está vacío:",
                                "Determinar si está balanceado:",
                                "Determinar si está completo:",
                                "Produndidad del árbol:",
                                "Número de nodos del árbol:"};
  int option = 0;

  do {

    option = showMenu(user_options, options_prompt);

    switch (option) {

      case 1: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- MOSTRAR EL ÁRBOL --";
        std::cout << setFormat(Text::resetAttributes) << "\n\n";

        std::cout << *binary_tree << std::endl;

        break;
      }

      case 2: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- INSERTAR CLAVE EN EL ÁRBOL --";
        std::cout << setFormat(Text::resetAttributes) << '\n';

        double introduced_number;

        std::cout << "\n\t" << "Introduzca el número que quiera > ";
        std::cin >> introduced_number;
        std::cin.get();

        if (binary_tree->Insert(introduced_number)) {
          std::cout << setFormat(Text::green);
          std::cout << "\n\t" << "¡Clave insertada con éxito!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

          std::cout << *binary_tree << std::endl;

        } else {
          std::cout << setFormat(Text::red);
          std::cout << "\n\t" << "La clave estaba previamente en el árbol." << "\n\n";
          std::cout << setFormat(Text::resetAttributes);
        }

        break;
      }
      case 3: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- ELIMINAR CLAVE DEL ÁRBOL --";
        std::cout << setFormat(Text::resetAttributes) << '\n';

        double introduced_number;

        std::cout << "\n\t" << "Introduzca el número que quiera> ";
        std::cin >> introduced_number;
        std::cin.get();

        if (binary_tree->Erase(introduced_number)) {

          std::cout << setFormat(Text::green);
          std::cout << "\n\t" << "¡Clave eliminada!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

          std::cout << *binary_tree << std::endl;

        } else {
          std::cout << setFormat(Text::red);
          std::cout << "\n\t" << "La clave no se encuentra." << "\n\n";
          std::cout << setFormat(Text::resetAttributes);
        }

        break;
      }

      case 4: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- BUSCAR CLAVE EN EL ÁRBOL --";
        std::cout << setFormat(Text::resetAttributes) << '\n';

        double introduced_number;

        std::cout << "\n\t" << "Introduzca el número que quiera> ";
        std::cin >> introduced_number;
        std::cin.get();

        if (binary_tree->Search(introduced_number)) {

          std::cout << setFormat(Text::green);
          std::cout << "\n\t" << "¡Clave encontrada!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

        } else {

          std::cout << setFormat(Text::red);
          std::cout << "\n\t" << "La clave no se encuentra." << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

        }

        break;
      }

      case 5: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- DETERMINAR SI EL ÁRBOL ESTÁ VACÍO --";
        std::cout << setFormat(Text::resetAttributes) << '\n';

        if (binary_tree->IsEmpty()) {

          std::cout << setFormat(Text::red);
          std::cout << "\n\t" << "¡Árbol vacío!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

        } else {

          std::cout << setFormat(Text::green);
          std::cout << "\n\t" << "¡Árbol no vacío!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

        }

        break;
      }

      case 6: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- DETERMINAR SI EL ÁRBOL ESTÁ BALANCEADO --";
        std::cout << setFormat(Text::resetAttributes) << '\n';

        if (binary_tree->IsBalanced()) {

          std::cout << setFormat(Text::green);
          std::cout << "\n\t" << "¡Árbol balanceado!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

        } else {

          std::cout << setFormat(Text::red);
          std::cout << "\n\t" << "¡Árbol no balanceado!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

        }

        break;
      }

      case 7: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- DETERMINAR SI EL ÁRBOL ESTÁ COMPLETO --";
        std::cout << setFormat(Text::resetAttributes) << '\n';

        if (binary_tree->IsComplete()) {

          std::cout << setFormat(Text::green);
          std::cout << "\n\t" << "¡Árbol completo!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

        } else {

          std::cout << setFormat(Text::red);
          std::cout << "\n\t" << "¡Árbol no completo!" << "\n\n";
          std::cout << setFormat(Text::resetAttributes);

        }

        break;
      }

      case 8: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- PROFUNDIDAD DEL ÁRBOL--";
        std::cout << setFormat(Text::resetAttributes) << '\n';

        std::cout << "\n\t" << "La profundidad del árbol es de ";

        std::cout << setFormat(Text::green);
        std::cout << binary_tree->Depth();
        std::cout << setFormat(Text::resetAttributes);

        std::cout << " niveles." << '\n';

        break;
      }

      case 9: {

        std::cout << "\n\n" << "\t\t";
        std::cout << setFormat(Text::blueBackground);
        std::cout << "-- NÚMERO DE NODOS DEL ÁRBOL--";
        std::cout << setFormat(Text::resetAttributes) << '\n';

        std::cout << "\n\t" << "El número de nodos del árbol es de ";

        std::cout << setFormat(Text::green);
        std::cout << binary_tree->NumberOfNodes();
        std::cout << setFormat(Text::resetAttributes);

        std::cout << " nodos." << '\n';

        break;
      }

    }

    if (option != 0){
      std::cout << "\nPulse cualquier letra para continuar > ";
      std::cin.get();
    }

  } while (option != 0);

}

void AEDA_P5::StatisticsMode(BinaryTree<NumberPlate> *&test_tree) {

  std::cout << "\n\n" << "\t\t    ";
  std::cout << setFormat(Text::blueBackground);
  std::cout << "-- MODO ESTADÍSTICA --";
  std::cout << setFormat(Text::resetAttributes) << '\n';

  size_t size_of_test_bench = 0;
  std::cout << "\n\tIntroduzca el tamaño del banco de pruebas > ";
  std::cin >> size_of_test_bench;

  size_t num_of_tests = 0;
  std::cout << "\tIntroduzca el tamaño del banco de pruebas > ";
  std::cin >> num_of_tests;

  while (!(num_of_tests > 0 && num_of_tests <=size_of_test_bench)) {
    std::cout << "\n\tEl número de pruebas ha de ser menor que el tamaño del banco de pruebas" << '\n';
    std::cout << "\tIntroduzca el tamaño del banco de pruebas > ";
    std::cin >> num_of_tests;
  }

  std::vector<NumberPlate> test_bench(2*size_of_test_bench);

  std::cout << "\n\tEl vector que usaremos será : \n";
  std::cout << setFormat(Text::green) << '\t';

  for (int i = 0; i < test_bench.size(); ++i) {

    if (i % 6 == 0)
      std::cout << "\n\t";

    std::cout << test_bench[i] << " ";
  }

  std::cout << setFormat(Text::resetAttributes) << '\n';

  test_tree->Insert(test_bench);

  std::cout << "\n\n" << "\t\t    " << "-- Comparaciones --" << '\n';

  std::cout << "\n\t" << setFormat(Text::yellowBackground);
  std::cout << setFormat(Text::black);
  std::cout << "Operación     N     P  Mínimo   Media  Máximo";
  std::cout << setFormat(Text::resetAttributes) << '\n';

  std::cout << '\t' << " Búsqueda";
  std::cout << std::setw(6) << size_of_test_bench;
  std::cout << std::setw(6) << num_of_tests;

  EvaluateSearchOperationAtTree(test_tree,
                                std::vector<NumberPlate>(test_bench.begin(), test_bench.begin()+num_of_tests));

  std::cout << '\t' << "Inserción";
  std::cout << std::setw(6) << size_of_test_bench;
  std::cout << std::setw(6) << num_of_tests;

  EvaluateSearchOperationAtTree(test_tree,
                                std::vector<NumberPlate>(test_bench.begin() + size_of_test_bench,
                                                         test_bench.begin() + size_of_test_bench + num_of_tests));

  std::cout << std::endl << std::endl;

}


void AEDA_P5::EvaluateSearchOperationAtTree(const BinaryTree<NumberPlate> *test_tree,
                                            const std::vector<NumberPlate> test_bench) {

  NumberPlate::number_of_comparisons_ = 0;
  test_tree->Search(test_bench[0]);

  int min_comparisons   = NumberPlate::number_of_comparisons_;
  int max_comparisons   = NumberPlate::number_of_comparisons_;
  int accum_comparisons = NumberPlate::number_of_comparisons_;

  for (int i = 1; i < test_bench.size(); ++i) {

    NumberPlate::number_of_comparisons_ = 0;

    test_tree->Search(test_bench[i]);

    min_comparisons = std::min(min_comparisons, NumberPlate::number_of_comparisons_);
    max_comparisons = std::max(max_comparisons, NumberPlate::number_of_comparisons_);

    accum_comparisons += NumberPlate::number_of_comparisons_;
  }

  double average = accum_comparisons / test_bench.size();

  std::cout << std::setw(8) << min_comparisons;
  std::cout << std::setw(8) << std::setprecision(3) << average;
  std::cout << std::setw(8) << max_comparisons << std::endl;

}
