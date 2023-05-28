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

//add checking if the cell is empty, if yes 0 is added to the sum, if not the value is added to the sum, if the value is not a number, the sum is not calculated
float Spreadsheet::sum(int row1, int col1, int row2, int col2) const {
    float sum = 0.0f;
    for (int i = row1; i <= row2; i++)
    {
        for (int j = col1; j <= col2; j++)
        {
            if (row1 < cells.size() && col1 < cells[row1].size() && cells[row1][col1] != nullptr)
            {
                if (dynamic_cast<NumericCell *>(cells[row1][col1]))
                {
                    sum += cells[row1][col1]->getValueAsFloat();
                }
                else if (dynamic_cast<StringCell *>(cells[row1][col1]))
                {
                    return 0.0f;
                }
            }
        }
    }
    return sum;
}

float Spreadsheet::average(int row1, int col1, int row2, int col2) const {
    float sum = 0.0f;
    int count = 0;
    for (int i = row1; i <= row2; i++)
    {
        for (int j = col1; j <= col2; j++)
        {
            if (row1 < cells.size() && col1 < cells[row1].size() && cells[row1][col1] != nullptr)
            {
                if (dynamic_cast<NumericCell *>(cells[row1][col1]))
                {
                    sum += cells[row1][col1]->getValueAsFloat();
                    count++;
                }
                else if (dynamic_cast<StringCell *>(cells[row1][col1]))
                {
                    return 0.0f;
                }
            }
        }
    }
    return sum/count;
}

float Spreadsheet::max(int row1, int col1, int row2, int col2) const {
    float max = 0.0f;
    for (int i = row1; i <= row2; i++)
    {
        for (int j = col1; j <= col2; j++)
        {
            if (row1 < cells.size() && col1 < cells[row1].size() && cells[row1][col1] != nullptr)
            {
                if (dynamic_cast<NumericCell *>(cells[row1][col1]))
                {
                    if (cells[row1][col1]->getValueAsFloat() > max)
                    {
                        max = cells[row1][col1]->getValueAsFloat();
                    }
                }
                else if (dynamic_cast<StringCell *>(cells[row1][col1]))
                {
                    return 0.0f;
                }
            }
        }
    }
    return max;
}

float Spreadsheet::min(int row1, int col1, int row2, int col2) const {
    float min = 0.0f;
    for (int i = row1; i <= row2; i++)
    {
        for (int j = col1; j <= col2; j++)
        {
            if (row1 < cells.size() && col1 < cells[row1].size() && cells[row1][col1] != nullptr)
            {
                if (dynamic_cast<NumericCell *>(cells[row1][col1]))
                {
                    if (cells[row1][col1]->getValueAsFloat() < min)
                    {
                        min = cells[row1][col1]->getValueAsFloat();
                    }
                }
                else if (dynamic_cast<StringCell *>(cells[row1][col1]))
                {
                    return 0.0f;
                }
            }
        }
    }
    return min;
}

std::string Spreadsheet::concatenate(int row1, int col1, int row2, int col2) const {
    std::string concat = "";
    for (int i = row1; i <= row2; i++)
    {
        for (int j = col1; j <= col2; j++)
        {
            if (row1 < cells.size() && col1 < cells[row1].size() && cells[row1][col1] != nullptr)
            {
                if (dynamic_cast<StringCell *>(cells[row1][col1]))
                {
                    concat += cells[row1][col1]->getValueAsString();
                }
                else if (dynamic_cast<NumericCell *>(cells[row1][col1]))
                {
                    return "";
                }
            }
        }
    }
    return concat;
}

void Spreadsheet::saveSpreadsheet(std::string filename) const{
    std::ofstream file;
    file.open(filename);
    if (file.is_open())
    {
        //go row by row and column by column and save the cell type and value separated by a comma, and save the cell coordinates and inform in the beginning of the file, how many rows and columns the spreadsheet has
        file << cells.size() << "," << cells[0].size() << std::endl;
        for (int i = 0; i < cells.size(); i++)
        {
            for (int j = 0; j < cells[i].size(); j++)
            {
                if (cells[i][j] != nullptr)
                {
                    file << getCellType(i,j) << "," << cells[i][j]->getValueAsString() << "," << i << "," << j << std::endl;
                }
            }
        }
    }
    file.close();
}

void Spreadsheet::loadSpreadsheet(std::string filename){
    std::ifstream file;
    file.open(filename);
    if (file.is_open())
    {
        //load file line by line and create cells based on the cell type and value, and place them in the correct coordinates
        //firstly, read first line to get the number of rows and columns, and create a vector of vectors of that size
        
        std::string line;
        std::getline(file, line);
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        int rows = std::stoi(tokens[0]);
        int cols = std::stoi(tokens[1]);
        cells.resize(rows);
        for (int i = 0; i < rows; i++)
        {
            cells[i].resize(cols);
        }
        //now, read the rest of the file and create cells based on the cell type and value, and place them in the correct coordinates
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::vector<std::string> tokens;
            while (std::getline(ss, token, ','))
            {
                tokens.push_back(token);
            }
            int row = std::stoi(tokens[2]);
            int col = std::stoi(tokens[3]);
            if (tokens[0] == "NumericCell")
            {
                cells[row][col] = new NumericCell();
                cells[row][col]->setValue(stof(tokens[1]));
            }
            else if (tokens[0] == "StringCell")
            {
                cells[row][col] = new StringCell();
                cells[row][col]->setValue(tokens[1]);
            }
            else if (tokens[0] == "Cell")
            {
                cells[row][col] = new StringCell();
                cells[row][col]->setValue("");
            }
        }
        

    }
    file.close();
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