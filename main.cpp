#include "Spreadsheet.h"

using namespace std;

int main(){

    Spreadsheet sheet;

    sheet.loadSpreadsheet("test.txt");

    cout << "Jestem" << endl;

    sheet.print();

    cout << "Test sumy od 0,1 do 2,2: " << sheet.sum(0, 1, 2, 1) << endl;

    cout << "Test sredniej od 0,1 do 2,2: " << sheet.average(0, 1, 2, 1) << endl;

    cout << "Test konkatenacji od 0,0 do 1,0: " << sheet.concatenate(0, 0, 1, 0) << endl;

    // sheet.setValue(0, 0, "Hello");
    // sheet.setValue(1, 0, "World");
    // sheet.setValue(2, 0, "!");
    // sheet.setValue(0, 1, 1.5);
    // sheet.setValue(1, 1, 2.5);
    // sheet.setValue(2, 1, 3.5);

    // sheet.addColumn();

    // sheet.setValue(0, 2, "Goodbye");

    // sheet.setValue(1, 2, 4.5);

    // sheet.setValue(2, 2, "World");

    // sheet.addRow();

    // sheet.setValue(3, 1, 5.5);

    // sheet.setValue(3, 2, "World");

    // sheet.deleteRow(1);

    // sheet.print();

    // cout << "Dotarlem do konca" << endl;

    // cout << "Ekspoertuje do pliku" << endl;

    // sheet.saveSpreadsheet("test.txt");

    return 0;
}