/*
	Developed by: James Ald Teves
	BS CS - II

	Silliman University
	Description: Dynamic Linked List Queue and Stacks
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#define QSIZE 5
#define SLIMIT 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

typedef struct {
    Node* top;
} Stack;

// Function declarations
Queue* createQueue();
void enQueue(Queue* q, int data);
int deQueue(Queue* q);
void displayQueue(Queue* q);
bool isQueueEmpty(Queue* q);

Stack* createStack();
void push(Stack* s, int data);
int pop(Stack* s);
void displayStack(Stack* s);
bool isStackEmpty(Stack* s);

int main() {
    int choice, data;
    Queue* queue = createQueue();
    Stack* stack = createStack();

    while (true) {
        printf("\nSelect the type of list to work on:\n");
        printf("1. QUEUE\n");
        printf("2. STACK\n");
        printf("3. EXIT\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Program Terminated!\n");
            break;
        } else if (choice == 1) {
            while (true) {
                printf("\nQueue Operations:\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display Queue\n");
                printf("4. Go Back\n");
                printf("Enter Choice: ");
                scanf("%d", &choice);

                if (choice == 4) break;
                switch (choice) {
                    case 1:
                        printf("Enter data to enqueue: ");
                        scanf("%d", &data);
                        enQueue(queue, data);
                        break;
                    case 2:
                        data = deQueue(queue);
                        if (data != INT_MIN) {
                            printf("Dequeued: %d\n", data);
                        } else {
                            printf("Queue is empty.\n");
                        }
                        break;
                    case 3:
                        displayQueue(queue);
                        break;
                }
            }
        } else if (choice == 2) {
            while (true) {
                printf("\nStack Operations:\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Display Stack\n");
                printf("4. Go Back\n");
                printf("Enter Choice: ");
                scanf("%d", &choice);

                if (choice == 4) break;
                switch (choice) {
                    case 1:
                        printf("Enter data to push: ");
                        scanf("%d", &data);
                        push(stack, data);
                        break;
                    case 2:
                        data = pop(stack);
                        if (data != INT_MIN) {
                            printf("Popped: %d\n", data);
                        } else {
                            printf("Stack is empty.\n");
                        }
                        break;
                    case 3:
                        displayStack(stack);
                        break;
                }
            }
        }
    }

    // Free the memory allocated for the queue and stack
    while (!isQueueEmpty(queue)) {
        deQueue(queue);
    }
    free(queue);

    while (!isStackEmpty(stack)) {
        pop(stack);
    }
    free(stack);

    return 0;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int deQueue(Queue* q) {
    if (q->front == NULL)
        return INT_MIN;
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

void displayQueue(Queue* q) {
    Node* temp = q->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

// Stack Functions Implementation

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack* s, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL)
        return INT_MIN;
    Node* temp = s->top;
    int data = temp->data;
    s->top = s->top->next;
    free(temp);
    return data;
}

void displayStack(Stack* s) {
    Node* temp = s->top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool isStackEmpty(Stack* s) {
    return s->top == NULL;
}