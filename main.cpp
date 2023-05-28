#include "Spreadsheet.h"

using namespace std;

int main(){

    Spreadsheet sheet;

    sheet.setValue(0, 0, "Hello");
    sheet.setValue(1, 0, "World");
    sheet.setValue(2, 0, "!");
    sheet.setValue(0, 1, 1.5);
    sheet.setValue(1, 1, 2.5);
    sheet.setValue(2, 1, 3.5);

    sheet.print();

    cout << "______________" << endl;


    sheet.addColumn();

    sheet.setValue(0, 2, "Goodbye");


    sheet.setValue(1, 2, 4.5);


    sheet.setValue(2, 2, "World");


    sheet.addRow();

cout << "______________" << endl;

    sheet.setValue(3, 1, 5.5);


    sheet.setValue(3, 2, "World");

    sheet.deleteRow(1);

    cout << "______________" << endl;


    sheet.print();

    cout << "Dotarlem do konca" << endl;

    return 0;
}