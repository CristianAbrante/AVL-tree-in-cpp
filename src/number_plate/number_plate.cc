//
// Created by cristian on 26/03/17.
//

#include "../../include/number_plate/number_plate.h"

// STATIC VARIABLES

int NumberPlate::number_of_comparisons_ = 0;

// PUBLIC METHODS

NumberPlate::NumberPlate() : number_plate_() {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::binomial_distribution<int> creator(9, creation_parameter);

    for (int i = 0; i < 4; ++i) {
        number_plate_.push_back(creator(mt) + '0');
    }

    for (int j = 0; j < 3; ++j) {
        number_plate_.push_back('A' + creator(mt) % 26);
    }

}

NumberPlate::NumberPlate(const std::string &number_plate_) : number_plate_(number_plate_) {

    assert(number_plate_.size() == 7);

    for (int i = 0; i < 4; ++i) {
        assert(number_plate_[i] >= '0' && number_plate_[i] <= '9');
    }

    for (int j = 4; j < 7; ++j) {
        assert(number_plate_[j] >= 'A' && number_plate_[j] <= 'Z');
    }

}

NumberPlate::operator unsigned long() const {

    unsigned long number_value = 0;

    for (int i = 0; i < 4; ++i) {
        number_value += number_plate_[i] - '0';
    }

    for (int j = 4; j < 7; ++j) {
        number_value += number_plate_[j] - 'A';
    }

    return number_value;
}

// RELATIONAL OPERATORS

bool NumberPlate::operator<(const NumberPlate &rhs) const {

    number_of_comparisons_++;

    int i = 0;

    while (i < 7) {

        if (number_plate_[i] < rhs.number_plate_[i]) {
            return true;
        } else {
            if (number_plate_[i] == rhs.number_plate_[i]) {
                i++;
            } else {
                return false;
            }
        }
    }

    return false;

}

bool NumberPlate::operator>(const NumberPlate &rhs) const {
    return rhs < *this;
}

bool NumberPlate::operator<=(const NumberPlate &rhs) const {
    return !(rhs < *this);
}

bool NumberPlate::operator>=(const NumberPlate &rhs) const {
    return !(*this < rhs);
}

bool NumberPlate::operator==(const NumberPlate &rhs) const {

    number_of_comparisons_++;

    int i = 0;

    if(number_plate_.size() != rhs.number_plate_.size())
        return false;

    while (i < 7) {
        if (number_plate_[i] != rhs.number_plate_[i]) {
            return false;
        } else {
            i++;
        }
    }

    return true;
}

bool NumberPlate::operator!=(const NumberPlate &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const NumberPlate &plate) {
  os << plate.number_plate_;
  return os;
}