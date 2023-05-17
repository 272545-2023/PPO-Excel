#include "NumericCell.h"

void NumericCell::setValue(const std::string& value) {
    this->value = std::stof(value);
}

void NumericCell::setValue(float value) {
    this->value = value;
}

std::string NumericCell::getValueAsString() const {
    return std::to_string(value);
}

float NumericCell::getValueAsFloat() const {
    return value;
}

void NumericCell::print() const {
    std::cout << value;
}
