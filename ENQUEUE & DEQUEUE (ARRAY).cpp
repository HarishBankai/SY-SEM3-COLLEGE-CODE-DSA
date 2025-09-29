#include <stdio.h>
#define SIZE 100

typedef struct {
    int items[SIZE];
    int front;
    int back;
} queue;

void initQueue(queue *s) {
    s->front = -1;  // queue empty
    s->back = -1;
}

void enqueue(queue *s, int value) {
    if (s->back == SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (s->front == -1) {
        s->front = 0;  // first element
    }
    s->back++;
    s->items[s->back] = value;
    printf("%d element has entered the queue\n", value);
}

int dequeue(queue *s) {
    if (s->front == -1 || s->front > s->back) {
        printf("Queue is empty, can't dequeue\n");
        return -1;  // error value
    }
    int value = s->items[s->front];
    printf("POP : %d\n", value);
    s->front++;
    if (s->front > s->back) {  // queue became empty
        s->front = -1;
        s->back = -1;
    }
    return value;
}

void displayqueue(queue *s) {
    if (s->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue:\n");
    for (int i = s->front; i <= s->back; i++) {
        printf("%d\t", s->items[i]);
    }
    printf("\n");
}

int main() {
    queue s;
    initQueue(&s);

    enqueue(&s, 45);
    enqueue(&s, 30);
    enqueue(&s, 60);
    enqueue(&s, 80);

    dequeue(&s);
    displayqueue(&s);

    return 0;
}
