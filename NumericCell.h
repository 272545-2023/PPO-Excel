#include <iostream>
#include "Cell.h"

class NumericCell : public Cell {
    private:
        float value;
    public:

        /*
            * Default constructor
            * Initializes value to 0.0f
            * @param none
            * @return none
        */    
        NumericCell() : value(0.0f) {};

        /*
            * A method that sets the value of the cell
            * @param value The value to set the cell to
            * @return none
        */
        void setValue(const std::string& value);


        /*
            * A method that sets the value of the cell
            * @param value The value to set the cell to
            * @return none
        */
        void setValue(float value);
        
        /*
            * A method that returns the string value of the cell
            * @param none
            * @return The value of the cell
        */
        std::string getValueAsString() const;

        /*
            * A method that returns the float value of the cell
            * @param none
            * @return The value of the cell
        */
        float getValueAsFloat() const;
        
        /*
            * A method that prints the value of the cell
            * @param none
            * @return none
        */
        void print() const; 
};