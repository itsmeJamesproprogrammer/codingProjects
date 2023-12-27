/* 
	Developed by: James Ald Teves
	CCS 4
	BS Computer Science - II
   
   Description: This program aims to solve your current BMI by inputting your details in the program.
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

//Main Function
int main() {

	//Declarations
    char choice, decision;
    int age, feet, inches, weightKg;
    float heightMeters, weightPounds, bmi;

    do {
        system("CLS");
        printf("\n\t Please enter the following details before your BMI gets Calculated. ");
        printf("\n\t Are you a muscle builder, a long-distance athlete, or pregnant? (Y/N): ");
        scanf(" %c", &choice);

        if (tolower(choice) == 'n') {
            printf("\n\t Enter your age: ");
            scanf("%d", &age);
            while (getchar() != '\n');  // Clear input buffer

            if (age >= 18 && age <= 65) {
                printf("\n Do you want to enter your height in: ");
                printf("\n 1. Feet and Inches");
                printf("\n 2. Centimeters");
                printf("\n Enter your choice: ");
                scanf("%d", &feet); // Reusing 'feet' variable for choice
                while (getchar() != '\n');  // Clear input buffer

                if (feet == 1) {
                    printf("\n Enter your Height in Feet: ");
                    scanf("%d", &feet);
                    printf("\n Inches: ");
                    scanf("%d", &inches);
                    heightMeters = (feet * 0.3048) + (inches * 0.0254);
                } else {
                    printf("\n\t Enter your Height in Centimeters: ");
                    scanf("%f", &heightMeters);
                    heightMeters /= 100;
                }
                while (getchar() != '\n');  // Clear input buffer

                printf("\n\t Do you want to enter your Weight in: ");
                printf("\n 1. Kilogram");
                printf("\n 2. Pounds");
                printf("\n Enter your choice: ");
                scanf("%d", &weightKg); // Reusing 'weightKg' variable for choice
                while (getchar() != '\n');  // Clear input buffer

                if (weightKg == 1) {
                    printf("\n\t Enter your Weight in (Kg): ");
                    scanf("%f", &weightPounds); // Reusing 'weightPounds' variable for weight in kg
                } else {
                    printf("\n\t Enter your weight in pounds:");
                    scanf("%f", &weightPounds);
                    weightPounds *= 0.453592;
                }
                while (getchar() != '\n');  // Clear input buffer

                // BMI Calculation
                bmi = weightPounds / (heightMeters * heightMeters);
                printf("\n\t Your BMI is %.2f", bmi);

                if (bmi <= 18) {
                    printf(" and you are classified as Underweight.");
                } else if (bmi <= 24.9) {
                    printf(" and you are classified as Normal weight.");
                } else if (bmi <= 29.9) {
                    printf(" and you are classified as Overweight.");
                } else if (bmi <= 34.9) {
                    printf(" and you are classified as Obesity Class 1.");
                } else if (bmi <= 39.9) {
                    printf(" and you are classified as Obesity Class 2.");
                } else {
                    printf(" and you are classified as Extreme Obesity Class 3.");
                }
                printf("\n");
            } else {
                printf("\n\t Sorry, you're not applicable for measuring BMI...\n");
            }
        } else if (tolower(choice) == 'y') {
            printf("\n\t Sorry, your Body Mass Index Cannot be Calculated...\n");
        }
        printf("\n\t Do you want to repeat the process? (Y/N): ");
        scanf(" %c", &decision);
    } while (tolower(decision) == 'y');
    return 0;
}