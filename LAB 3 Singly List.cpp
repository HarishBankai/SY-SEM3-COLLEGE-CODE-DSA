#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertEnd(int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Insert in the middle (after given position)
void insertMiddle(int data, int pos) {
    Node *newNode = createNode(data);
    if (pos == 0) {
        insertFront(data);
        return;
    }
    Node *temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete at front
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

// Delete at end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete in middle (by position)
void deleteMiddle(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 0) {
        deleteFront();
        return;
    }
    Node *temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// Display list
void display() {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Display reverse using recursion
void displayReverse(Node *node) {
    if (node == NULL) return;
    displayReverse(node->next);
    printf("%d -> ", node->data);
}

// Reverse the linked list (in-place)
void reverseList() {
    Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

// Main menu
int main() {
    int choice, data, pos;
    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert in middle (position)\n");
        printf("4. Delete at front\n");
        printf("5. Delete at end\n");
        printf("6. Delete in middle (position)\n");
        printf("7. Display\n");
        printf("8. Display Reverse\n");
        printf("9. Reverse List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertMiddle(data, pos);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteMiddle(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Reverse Display: ");
                displayReverse(head);
                printf("NULL\n");
                break;
            case 9:
                reverseList();
                printf("List reversed!\n");
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


