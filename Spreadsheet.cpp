#include "Spreadsheet.h"

bool Spreadsheet::isNumeric(const std::string &value) const
{
    for (int i = 0; i < value.length(); i++)
    {
        if (!isdigit(value[i]))
        {
            return false;
        }
    }
    return true;
}

void Spreadsheet::setValue(int row, int col, const std::string &value)
{
    if (row >= cells.size())
    {
        cells.resize(row + 1);
    }
    if (col >= cells[row].size())
    {
        cells[row].resize(col + 1, nullptr);
    }
    if (cells[row][col] == nullptr)
    {
        if (isNumeric(value))
        {
            cells[row][col] = new NumericCell();
        }
        else
        {
            cells[row][col] = new StringCell();
        }
    }
    cells[row][col]->setValue(value);
}

void Spreadsheet::setValue(int row, int col, float value)
{
    if (row >= cells.size())
    {
        cells.resize(row + 1);
    }

    if (col >= cells[row].size())
    {
        cells[row].resize(col + 1, nullptr);
    }

    if (cells[row][col] == nullptr)
    {
        cells[row][col] = new NumericCell();
    }

    cells[row][col]->setValue(value);
}

std::string Spreadsheet::getValueAsString(int row, int col) const
{
    if (row < cells.size() && col < cells[row].size() && cells[row][col] != nullptr)
    {
        return cells[row][col]->getValueAsString();
    }
    return ""; // Wartość domyślna, gdy komórka nie istnieje
}

float Spreadsheet::getValueAsFloat(int row, int col) const
{
    if (row < cells.size() && col < cells[row].size() && cells[row][col] != nullptr)
    {
        return cells[row][col]->getValueAsFloat();
    }
    return 0.0f; // Wartość domyślna, gdy komórka nie istnieje
}

//write method for printing the spreadsheet bith in string and float

void Spreadsheet::print() const
{
    for (int i = 0; i < cells.size(); i++)
    {
        for (int j = 0; j < cells[i].size(); j++)
        {
            std::cout << getValueAsString(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}


//write method for adding and deleting rows and columns

void Spreadsheet::addRow()
{
    //add a new row to the end of the spreadsheet
    cells.resize(cells.size() + 1);
}

void Spreadsheet::addColumn()
{
    //add a new column to the end of the spreadsheet
    for (int i = 0; i < cells.size(); i++)
    {
        cells[i].resize(cells[i].size() + 1, nullptr);
    }
}

void Spreadsheet::deleteRow(int row)
{
    //delete a row from the spreadsheet
    if (row < cells.size())
    {
        cells.erase(cells.begin() + row);
    }
}

void Spreadsheet::deleteColumn(int col)
{
    //delete a column from the spreadsheet
    if (col < cells[0].size())
    {
        for (int i = 0; i < cells.size(); i++)
        {
            cells[i].erase(cells[i].begin() + col);
        }
    }
}

std::string Spreadsheet::getCellType(int row, int col) const
{
    if (row < cells.size() && col < cells[row].size() && cells[row][col] != nullptr)
    {
        if (dynamic_cast<NumericCell *>(cells[row][col]))
        {
            return "NumericCell";
        }
        else if (dynamic_cast<StringCell *>(cells[row][col]))
        {
            return "StringCell";
        }
    }
    return "Cell";
}

Spreadsheet::~Spreadsheet()
{
    for (auto &row : cells)
    {
        for (auto &cell : row)
        {
            delete cell;
        }
    }
}