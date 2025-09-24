#Build a singly linked list with options: 
#a. Insert (at front, at end, in the middle) 
#b. Delete (at front, at end, in the middle) 
#c. Display 
#d. Display Reverse 
#e. Revert the SLL.

#include <stdio.h>
#define SIZE 100

typedef struct {
    int items[SIZE];
    int top;
} stack;

void chqstack(stack *s) {
    s->top = -1;
}

void push(stack *s, int value) {
    if (s->top == SIZE - 1)
        printf("Stack is full\n");
    else {
        s->items[++s->top] = value;
    }
}

int pop(stack *s) {
    if (s->top == -1) {  // Fixed condition here
        printf("Stack is empty, can't pop any valid data\n");
        return -1;  // Return a sentinel value indicating error
    } else {
        return s->items[s->top--];
    }
}

void displaystack(stack *s) {
    printf("Stack:\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d\n", s->items[i]);
    }
}

int main() {
    stack s;
    chqstack(&s);
    push(&s, 30);
    push(&s, 90);
    pop(&s);
    displaystack(&s);
    return 0;
}
