//Preprocessor Directives
#include <conio.h>
#include <iostream>
using namespace std;

int main() {
    int numericalGrade;
    char letterGrade;

    cout << "Enter the student's numerical grade: ";
    cin >> numericalGrade;

    if (numericalGrade >= 90) letterGrade = 'A';
    else if (numericalGrade >= 80) letterGrade = 'B';
    else if (numericalGrade >= 70) letterGrade = 'C';
    else if (numericalGrade >= 60) letterGrade = 'D';
    else letterGrade = 'F';

    cout << "The student's letter grade is: " << letterGrade << endl;

    return 0;
}