#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int items[MAX_SIZE];
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}
void push(struct Stack* stack, int data) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = data;
}
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = stack->items[stack->top];
    stack->top--;
    return data;
}
void display(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}
int sizeOfStack(struct Stack* stack) {
    return stack->top + 1;
}
int topOfStack(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}
int StackIsEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int StackIsFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

