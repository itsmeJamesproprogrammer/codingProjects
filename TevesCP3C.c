/* 
	Developed by: James Ald Teves
	CCS 4 - C
	Instructor: Assist. Prof. Melody Angelique Rivera
	Singly Linked List

	Description: This program enables you to record a detail's of a person. I use both of Linked list and Singly linked list in this program. This program uses Nodes, to store that inputted data from the user.
*/

// Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#define NAMESIZE 40

typedef struct node {
    char firstName[NAMESIZE];
    char lastName[NAMESIZE];
    char sex[10];
    int feet;
    int inches;
    int pounds;
    float weight;
    struct node *next;
} NODE;

// Function Declarations
void createNodeList(NODE **head);
void viewNodeList(NODE *head);
void searchNodeList(NODE *head);
int menu(NODE **head);

void createNodeList(NODE **head) {
    NODE *temp, *current;
    temp = (NODE*)malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    temp->next = NULL;

    printf("Enter the following details: \n");
    printf("Firstname: ");
    scanf("%39s", temp->firstName);
    printf("Lastname: ");
    scanf("%39s", temp->lastName);
    printf("Sex (Male/Female): ");
    scanf("%9s", temp->sex);
    printf("Height (Feet Inches): ");
    scanf("%d %d", &temp->feet, &temp->inches);
    printf("Weight (Pounds): ");
    scanf("%d", &temp->pounds);
    temp->weight = temp->pounds * 0.453592;

    if (*head == NULL) {
        *head = temp;
    } else {
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }
}
void viewNodeList(NODE *head) {
    NODE *current = head;
    if (current == NULL) {
        printf("No records found.\n");
        return;
    }
    printf("--------------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-6s %-15s %-10s\n", "Firstname", "Lastname", "Sex", "Height(ft, in)", "Weight(kg)");
    printf("--------------------------------------------------------------------------------\n");
    while (current != NULL) {
        printf("%-20s %-20s %-6s %-2d' %-2d\" %-10.2f\n", 
               current->firstName, 
               current->lastName, 
               current->sex, 
               current->feet, 
               current->inches, 
               current->weight);
        current = current->next;
    }
    printf("--------------------------------------------------------------------------------\n");
}

void searchNodeList(NODE *head) {
    char searchName[NAMESIZE];
    int found = 0, choice;

    if (head == NULL) {
        printf("No records to search.\n");
        return;
    }

    printf("Search by:\n1. Firstname\n2. Lastname\n");
    printf("Choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n'); // Clear buffer

    if (choice == 1 || choice == 2) {
        printf("Enter name to search: ");
        scanf("%39s", searchName);
    } else {
        printf("Invalid choice.\n");
        return;
    }

    NODE *current = head;
    while (current != NULL) {
        if ((choice == 1 && strcmp(searchName, current->firstName) == 0) ||
            (choice == 2 && strcmp(searchName, current->lastName) == 0)) {
            found = 1;
            printf("Record found:\n");
            printf("Name: %s %s\n", current->firstName, current->lastName);
            printf("Sex: %s\n", current->sex);
            printf("Height: %d' %d\"\n", current->feet, current->inches);
            printf("Weight: %.2f kg\n\n", current->weight);
        }
        current = current->next;
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

int menu(NODE **head) {
    int choice;

    do {
        printf("1. Record Data\n2. View Data\n3. Search Data\n4. Exit Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createNodeList(head);
                break;
            case 2:
                viewNodeList(*head);
                break;
            case 3:
                searchNodeList(*head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

int main() {
    NODE *head = NULL;
    menu(&head);

    // Free the linked list
    NODE *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}