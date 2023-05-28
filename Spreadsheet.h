#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
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
            A method that returns the sum of a range of cells
            @param row1 The first row of the range
            @param col1 The first column of the range
            @param row2 The second row of the range
            @param col2 The second column of the range
            @return The sum of the range
        */
        float sum(int row1, int col1, int row2, int col2) const;

        /*
            A method that returns the average of a range of cells
            @param row1 The first row of the range
            @param col1 The first column of the range
            @param row2 The second row of the range
            @param col2 The second column of the range
            @return The average of the range
        */
        float average(int row1, int col1, int row2, int col2) const;

        /*
            A method that returns the maximum of a range of cells
            @param row1 The first row of the range
            @param col1 The first column of the range
            @param row2 The second row of the range
            @param col2 The second column of the range
            @return The maximum of the range
        */
        float max(int row1, int col1, int row2, int col2) const;

        /*
            A method that returns the minimum of a range of cells
            @param row1 The first row of the range
            @param col1 The first column of the range
            @param row2 The second row of the range
            @param col2 The second column of the range
            @return The minimum of the range
        */
        float min(int row1, int col1, int row2, int col2) const;

        /*
            A method that concatenates a range of cells
            @param row1 The first row of the range
            @param col1 The first column of the range
            @param row2 The second row of the range
            @param col2 The second column of the range
            @return The concatenation of the range
        */

        std::string concatenate(int row1, int col1, int row2, int col2) const;

        /*
            A method that saves the spreadsheet to a file
            @param filename The name of the file to save to
            @return none
        */
        void saveSpreadsheet(std::string filename) const;

        /*
            A method that loads the spreadsheet from a file
            @param filename The name of the file to load from
            @return none
        */
        void loadSpreadsheet(std::string filename);


        /*
            Destructor
        */
        ~Spreadsheet();
};