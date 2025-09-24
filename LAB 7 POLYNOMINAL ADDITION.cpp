#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int power;
    struct node *next;
} node;

// Function to create a new node
node* createnode(int coeff, int power) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a term into the polynomial
void insertterm(node** poly, int coeff, int power) {
    node* newnode = createnode(coeff, power);
    if (*poly == NULL) {
        *poly = newnode;
    } else {
        node* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to print the polynomial
void printpoly(node* poly) {
    if (poly == NULL) {
        printf("Empty polynomial\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->power);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
node* addpoly(node* poly1, node* poly2) {
    node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->power > poly2->power) {
            insertterm(&result, poly1->coeff, poly1->power);
            poly1 = poly1->next;
        } else if (poly1->power < poly2->power) {
            insertterm(&result, poly2->coeff, poly2->power);
            poly2 = poly2->next;
        } else {
            int sum_coeff = poly1->coeff + poly2->coeff;
            if (sum_coeff != 0) {
                insertterm(&result, sum_coeff, poly1->power);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Append remaining terms from poly1
    while (poly1 != NULL) {
        insertterm(&result, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }
    // Append remaining terms from poly2
    while (poly2 != NULL) {
        insertterm(&result, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    node* poly1 = NULL;
    node* poly2 = NULL;
    node* sum = NULL;

    insertterm(&poly1, 3, 3);
    insertterm(&poly1, 2, 2);
    insertterm(&poly1, 5, 1);

    insertterm(&poly2, 4, 2);
    insertterm(&poly2, 2, 1);
    insertterm(&poly2, 7, 0);

    printf("Polynomial 1 : \n");
    printpoly(poly1);
    printf("Polynomial 2 : \n");
    printpoly(poly2);

    sum = addpoly(poly1, poly2);
    printf("Sum : \n");
    printpoly(sum);

    return 0;
}

