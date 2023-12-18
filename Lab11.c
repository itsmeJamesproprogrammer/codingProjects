/*
	Developed by: James Ald  Teves
	BS CS - III

	Description: Further Activity Notice.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_STUDENTS 10

typedef struct {
    int idNumber;
    int mtExam;
    int fnlExam;
    float fnlGrade;
    char name[50];
    char ltrGrade;
    float numericGrade;
} Record;

// Function Declarations
// Function Declarations
void recordInputs(Record recordGrade[], int* inputRecords);
void menu(Record recordGrade[], int* inputRecords);
void displayRecords(const Record recordGrade[], int inputRecords);

// Main function
int main() {
    Record recordGrade[MAX_STUDENTS];
    int inputRecords = 0;
    menu(recordGrade, &inputRecords);
    return 0;
}

void menu(Record recordGrade[], int* inputRecords) {
    int choice;
    do {
        system("cls");
        printf("\n\t\t\t Menu \n\n");
        printf("\n\t 1. Input records\n");
        printf("\n\t 2. Display records\n");
        printf("\n\t 3. Exit \n ");
        printf("\n\t Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                recordInputs(recordGrade, inputRecords);
                break;
            case 2:
                displayRecords(recordGrade, *inputRecords);
                break;
            case 3:
                printf("\n\t Program Terminated! ");
                exit(0);
                break;
            default:
                printf("\n\t Error Input! ");
                printf("\n\t Try again... ");
        }
    } while (choice != 3);
}

void recordInputs(Record recordGrade[], int* inputRecords) {
    printf("\n\t Enter how many inputs to record (max %d): ", MAX_STUDENTS);
    scanf("%d", inputRecords);
    
    if (*inputRecords <= 0 || *inputRecords > MAX_STUDENTS) {
        printf("\n\t Sorry! Allowed input record must be between 1 to %d.\n", MAX_STUDENTS);
        return;
    }

    for (int i = 0; i < *inputRecords; i++) {
        printf("\nStudent # %d:\n", i + 1);
        printf("ID number: ");
        scanf("%d", &recordGrade[i].idNumber);

        fflush(stdin);
        printf("Enter name: ");
        gets(recordGrade[i].name);

        printf("MT Exam: ");
        scanf("%d", &recordGrade[i].mtExam);

        printf("Final Exam: ");
        scanf("%d", &recordGrade[i].fnlExam);

        // Calculate final grade and letter grade
        recordGrade[i].fnlGrade = (recordGrade[i].mtExam * 0.4) + (recordGrade[i].fnlExam * 0.6);
        recordGrade[i].numericGrade = (2 * recordGrade[i].fnlGrade - 60) / 35;

        if (recordGrade[i].fnlGrade >= 95) recordGrade[i].ltrGrade = 'A';
        else if (recordGrade[i].fnlGrade >= 80) recordGrade[i].ltrGrade = 'B';
        else if (recordGrade[i].fnlGrade >= 65) recordGrade[i].ltrGrade = 'C';
        else if (recordGrade[i].fnlGrade >= 55) recordGrade[i].ltrGrade = 'D';
        else recordGrade[i].ltrGrade = 'F';
    }
}

void displayRecords(const Record recordGrade[], int inputRecords) {
    printf("\t\t\t\tRecords\n\n");
    printf("ID no.\tName\tMT.Exam\tF.Exam\tF.Grade\tLetter Grade\t#Grade\n");
    
    for (int i = 0; i < inputRecords; i++) {
        printf("%d\t%s\t%d\t%d\t%.2f\t\t%c\t\t\t%.2f\n",
               recordGrade[i].idNumber,
               recordGrade[i].name,
               recordGrade[i].mtExam,
               recordGrade[i].fnlExam,
               recordGrade[i].fnlGrade,
               recordGrade[i].ltrGrade,
               recordGrade[i].numericGrade);
    }

    printf("\n\n\n\n Hit enter to return to menu.");
    getchar();
    getchar();
}