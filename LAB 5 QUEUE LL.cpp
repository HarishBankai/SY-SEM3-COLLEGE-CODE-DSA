#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int data;
    struct queue* next;
} Queue;

Queue* front = NULL;
Queue* rear = NULL;

void insert();
void del();
void display();

int main() {
    int ch;
    while (1) {
        printf("\n1) INSERT ");
        printf("\n2) DELETE ");
        printf("\n3) DISPLAY ");
        printf("\n4) EXIT ");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("done");
                exit(0);
                break;
            default:
                printf("invalid choice");
                break;
        }
    }
    return 0; 
}

void insert() {
    Queue* newnode;
    newnode = (Queue*)malloc(sizeof(Queue));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("enter the element ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (rear == NULL) {
        rear = newnode;
        front = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void del() {
    Queue* temp;
    if (front == NULL) {
        printf("queue is empty\n");
    } else {
        temp = front;
        printf("removed element : %d", temp->data);
        front = temp->next;
        free(temp);
    }
}

void display() {
    Queue* temp = front;
    if (temp == NULL) {
        printf("Queue is empty");
        return;
    }
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
