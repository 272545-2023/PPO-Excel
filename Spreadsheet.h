#include <iostream>
#include <vector>
#include <iomanip>
#include "NumericCell.h"
#include "StringCell.h"

class Spreadsheet {
    private:
        std::vector<std::vector<Cell*>> cells;

        /*
            A method that checks if a string is numeric
            @param value The string to check
            @return True if the string is numeric, false otherwise
        */
        bool isNumeric(const std::string& value) const;
    public:

        /*
            A method that sets the value of a cell
            @param row The row of the cell
            @param col The column of the cell
            @param value The value to set the cell to
            @return none
        */
        void setValue(int row, int col, const std::string& value);

        /*
            A method that sets the value of a cell
            @param row The row of the cell
            @param col The column of the cell
            @param value The value to set the cell to
            @return none
        */
        void setValue(int row, int col, const float value);

        /*
            A method that returns the value of a cell
            @param row The row of the cell
            @param col The column of the cell
            @return The value of the cell
        */
        std::string getValueAsString(int row, int col) const;

        /*
            A method that returns the value of a cell
            @param row The row of the cell
            @param col The column of the cell
            @return The value of the cell
        */
        float getValueAsFloat(int row, int col) const;

        /*
            A method that prints the value of a cell
            @return none
        */
        void print() const;

        /*
            A method that deletes a row
            @param row The row to delete
            @return none
        */
        void deleteRow(int row);

        /*
            A method that deletes a column
            @param col The column to delete
            @return none
        */
        void deleteColumn(int col);

        /*
            A method that adds a row
            @return none
        */
        void addRow();

        /*
            A method that adds a column
            @return none
        */
        void addColumn();


        /*
            A method that returns the type of a cell
            @param row The row of the cell
            @param col The column of the cell
            @return string The type of the cell
        */
        std::string getCellType(int row, int col) const;

        /*
            Destructor
        */
        ~Spreadsheet();
};