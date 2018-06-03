//
// Created by cristian on 26/03/17.
//

#ifndef PRACTICA_4_NUMBERPLATE_H
#define PRACTICA_4_NUMBERPLATE_H

/** Inclusion of C++ libraries. */
#include <cassert>
#include <ostream>
#include <random>
#include <string>

/**
 * @author Cristian Abrante Dorta
 * @date March 2017
 *
 * @var Const variable that sets the probability
 *      during the ramdom creation of the number plate.
 */

const double creation_parameter = 0.5;

/**
 * @author Cristian Abrante Dorta
 * @date March 2017
 *
 * @class Class that represent an european number plate.
 *        The format is:  XXXXYYY
 *        where X is a digit of the number and Y is a letter.
 */


class NumberPlate {

 public:

  /**
   * @brief Variable that store the number of times that any
   *        relational operator has been used.
   */

  static int number_of_comparisons_;

  /**
   * @author Cristian Abrante Dorta
   * @date March 2017
   *
   * @brief Random constructor of the class.
   *        It sets the number plate to a value
   *        from 0000AAA to 999ZZZ.
   */

  NumberPlate();

  /**
   * @author Cristian Abrante Dorta
   * @date March 2017
   *
   * @brief Constructor with parameters.
   * @param number_plate   String that contains the value
   *                        of the number plate.
   *
   */

  NumberPlate(const std::string &number_plate);

  /**
   * @author    Cristian Abrante Dorta
   * @date      March 2017
   *
   * @brief     Operator that converts the number plate into a number
   *
   * @details   The conversion is do in this way: a value is assigned
   *            to each position of the number plate.
   *
   * @return    an unsigned long int corresponding to the value
   *            of the number plate.
   */

  operator unsigned long () const;

  /**
   * @author    Cristian Abrante Dorta
   * @date      March 2017
   *
   * @brief     Relational operators between two number plates.
   *
   * @param rhs Number plate to be compared with this number plate.
   * @return    true if this number plate is (whatever operator)
   *            between the other number plate.
   */

  bool operator<(const NumberPlate &rhs) const;

  bool operator>(const NumberPlate &rhs) const;

  bool operator<=(const NumberPlate &rhs) const;

  bool operator>=(const NumberPlate &rhs) const;

  bool operator==(const NumberPlate &rhs) const;

  bool operator!=(const NumberPlate &rhs) const;

  /**
   * @author      Cristian Abrante Dorta
   * @date        March 2017
   *
   * @brief       Output stream operator
   *
   * @param os    The stream where we want to send the number plate.
   * @param plate Number plate to be sent to the stream
   * @return      The same output stream os.
   */

  friend std::ostream &operator<<(std::ostream &os, const NumberPlate &plate);

 private:

  std::string number_plate_;

};

#endif //PRACTICA_4_NUMBERPLATE_H
