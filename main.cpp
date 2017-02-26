/*
 * lab_12.cpp
 *
 *  Created on: Dec 5, 2013
 *      Author: Adam
 */
# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>

using namespace std;
struct employee {
    int ID;
    string name;
    double hours;
    double rate;
    double wage;
};

void readFile(employee[], ifstream &);

void enterHours(employee[]);

void calcWages(employee[]);

void writePayRoll(employee[], ofstream &);

const int SIZE = 6;

int main() {
    employee staff[SIZE];
    ifstream fin;
    fin.open("E_PayRoll.txt");
    readFile(staff, fin);
    fin.close();

    enterHours(staff);
    calcWages(staff);

    ofstream fout;
    fout.open("lab12_EmployeePayRoll.txt");
    writePayRoll(staff, fout);
    fout.close();

    return 0;
}

void readFile(employee staff[], ifstream &fin) {
    for (int i = 0; i < SIZE; i++) {
        fin >> staff[i].ID;
        fin >> staff[i].name;
        fin >> staff[i].rate;
    }
    return;
}

void enterHours(employee staff[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << staff[i].name << setw(10) << staff[i].ID << endl;
        cout << "Enter this employees hours: " << endl;
        cin >> staff[i].hours;

        while (staff[i].hours < 0) {
            cout << "Please enter a valid amount of hours worked." << endl;
            cin >> staff[i].hours;
        }
    }
}

void calcWages(employee staff[]) {
    for (int i = 0; i < SIZE; i++) {
        staff[i].wage = staff[i].hours * staff[i].rate;
    }
}

void writePayRoll(employee staff[], ofstream &fout) {
    for (int i = 0; i < SIZE; i++) {
        fout << "Employee ID" << setw(15) << "Hours Worked" << setw(15) << "Pay Rate" << setw(15) << "Wages Earned"
             << endl;
        fout << staff[i].ID << setw(11) << staff[i].hours << setw(21) << staff[i].rate << setw(10) << "$"
             << staff[i].wage << endl;
    }
}



