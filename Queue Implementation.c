#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100


struct Queue {
    int front;
    int rear;
    int items[MAX_SIZE];
};
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    return queue;
}
void enqueue(struct Queue* queue, int data) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    } else if (queue->front == -1) {
        queue->front = 0;
        queue->rear = 0;
        queue->items[queue->rear] = data;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = data;
    }
}
int dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return data;
}
void display(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue->items[i]);
    }
    printf("%d\n", queue->items[queue->rear]);
}
int sizeOfQueue(struct Queue* queue) {
    if (queue->front == -1) {
        return 0;
    } else if (queue->rear >= queue->front) {
        return queue->rear - queue->front + 1;
    } else {
        return MAX_SIZE - queue->front + queue->rear + 1;
    }
}
int headOfQueue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}
int endOfQueue(struct Queue* queue) {
    if (queue->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->rear];
}
int QueueIsEmpty(struct Queue* queue) {
    return queue->front == -1;
}
int QueueIsFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}
