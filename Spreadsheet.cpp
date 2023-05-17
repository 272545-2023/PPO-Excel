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

void Spreadsheet::print() const
{
    if (cells.empty())
    {
        std::cout << "Empty spreadsheet" << std::endl;
        return;
    }

    // Print the top border
    std::cout << "+";
    for (int i = 0; i < cells[0].size(); i++)
    {
        std::cout << "------";
    }
    std::cout << std::endl;

    // Print the data
    for (int row = 0; row < cells.size(); row++)
    {
        std::cout << "|";
        for (int col = 0; col < cells[row].size(); col++)
        {
            std::cout << " ";
            if (cells[row][col] != nullptr)
            {
                std::cout << cells[row][col]->getValueAsString();
            }
            else
            {
                std::cout << " ";
            }
            std::cout << " |";
        }
        std::cout << std::endl;

        // Print the line below
        std::cout << "+";
        for (int i = 0; i < cells[row].size(); i++)
        {
            //set the length of the cell to size of content in the cell
            for (int j = 0; j < cells[row][i]->getValueAsString().length(); j++)
            {
                std::cout << "-";
            }

            std::cout << "------";
        }
        std::cout << std::endl;
    }

}

void Spreadsheet::deleteRow(int row)
{
    if (row < cells.size())
    {
        for (auto cell : cells[row])
        {
            delete cell;
        }
        cells.erase(cells.begin() + row);
    }
}

void Spreadsheet::deleteColumn(int col)
{
    if (!cells.empty() && col < cells[0].size())
    {
        for (auto &row : cells)
        {
            delete row[col];
            row.erase(row.begin() + col);
        }
    }
}

void Spreadsheet::addRow()
{
    cells.emplace_back();
}

void Spreadsheet::addColumn()
{
    
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