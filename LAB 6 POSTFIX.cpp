#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} stack;

void initstack(stack *s) {
    s->top = -1;
}

int isempty(stack *s) {
    return s->top == -1;
}

int isfull(stack *s) {
    return s->top == MAX - 1;
}

int push(stack *s, int value) {
    if (isfull(s)) {
        printf("STACK OVERFLOW\n");
        return 0; 
    }
    s->items[++(s->top)] = value;
    return 1; 
}

int pop(stack *s, int *value) {
    if (isempty(s)) {
        printf("STACK UNDERFLOW\n");
        return 0; 
    }
    *value = s->items[(s->top)--];
    return 1; 
}

int postfix(const char *expression) {
    stack s;
    initstack(&s);
    int i = 0;

    while (expression[i] != '\0') {
        char ch = expression[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else {
            int operand2, operand1;

            if (!pop(&s, &operand2) || !pop(&s, &operand1)) {
                printf("Error: Not enough operands.\n");
                return 0;
            }

            switch (ch) {
                case '+':
                    push(&s, operand1 + operand2);
                    break;
                case '-':
                    push(&s, operand1 - operand2);
                    break;
                case '*':
                    push(&s, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero.\n");
                        return 0;
                    }
                    push(&s, operand1 / operand2);
                    break;
                case '^': {
                    int res = (int)pow(operand1, operand2);
                    push(&s, res);
                    break;
                }
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 0;
            }
        }
        i++;
    }

    int result;
    if (!pop(&s, &result) || !isempty(&s)) {
        printf("Error: Invalid postfix expression.\n");
        return 0;
    }

    return result;
}

int main() {
    char expression[MAX];
    printf("ENTER POSTFIX EXPRESSION: ");
    scanf("%s", expression);
    int result = postfix(expression);
    printf("RESULT OF POSTFIX EXPRESSION IS: %d\n", result);
    return 0;
}




