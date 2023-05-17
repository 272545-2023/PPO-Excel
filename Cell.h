#ifndef CELL_H
#define CELL_H

#include <string>

class Cell {
    public:
        virtual void setValue(const std::string& value) = 0;
        virtual void setValue(const float value) = 0;
        virtual std::string getValueAsString() const = 0;
        virtual float getValueAsFloat() const = 0;
        virtual void print() const = 0;
};

#endif // CELL_H