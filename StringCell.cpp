#include "StringCell.h"

void StringCell::setValue(const std::string& value) {
    this->value = value;
}

void StringCell::setValue(const float value) {
    
}

std::string StringCell::getValueAsString() const {
    return value;
}

float StringCell::getValueAsFloat() const {
    return 0.0f;
}

void StringCell::print() const {
    std::cout << value;
}