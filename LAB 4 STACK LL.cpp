#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} Stack;

Stack *top = NULL;

void push();
void pop();
void display();

int main() {
    int ch;
    while (1) {
        printf("\n1) PUSH ");
        printf("\n2) POP ");
        printf("\n3) DISPLAY ");
        printf("\n4) EXIT ");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
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
    return 0; // It's good practice to return a value from main
}

void push() {
    Stack *newnode;
    newnode = (Stack *)malloc(sizeof(Stack));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    printf("enter new element : ");
    scanf("%d", &newnode->data);
    
    newnode->next = NULL;
    if (top == NULL) {
        top = newnode;
    } else {
        newnode->next = top;
        top = newnode;
    }
    printf("successfully added");
}

void pop() {
    Stack *temp;
    if (top == NULL) {
        printf("its empty");
    } else {
        temp = top;
        printf("removed element from the stack : %d", temp->data);
        
        top = top->next;
        free(temp);
    }
    printf("\n");
}

void display() {
    Stack *temp = top;
    if (temp == NULL) {
        printf("Stack is empty");
        return;
    }
    printf("Stack elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

