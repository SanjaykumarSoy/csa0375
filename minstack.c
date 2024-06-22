#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct StackNode {
    int data;
    struct StackNode* next;
};
struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

// Utility function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// Function to push an element to stack
void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

// Function to pop an element from stack
int pop(struct StackNode** root) {
    if (isEmpty(*root)) {
        return INT_MIN;
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Function to return the top element of stack
int top(struct StackNode* root) {
    if (isEmpty(root)) {
        return INT_MIN;
    }
    return root->data;
}

// MinStack structure definition
typedef struct {
    struct StackNode* stack;
    struct StackNode* minStack;
} MinStack;

// MinStack initialization function
MinStack* minStackCreate() {
    MinStack* minStack = (MinStack*)malloc(sizeof(MinStack));
    minStack->stack = NULL;
    minStack->minStack = NULL;
    return minStack;
}

// Push function for MinStack
void minStackPush(MinStack* obj, int val) {
    push(&(obj->stack), val);
    if (isEmpty(obj->minStack) || val <= top(obj->minStack)) {
        push(&(obj->minStack), val);
    }
}

// Pop function for MinStack
void minStackPop(MinStack* obj) {
    if (top(obj->stack) == top(obj->minStack)) {
        pop(&(obj->minStack));
    }
    pop(&(obj->stack));
}

// Top function for MinStack
int minStackTop(MinStack* obj) {
    return top(obj->stack);
}

// GetMin function for MinStack
int minStackGetMin(MinStack* obj) {
    return top(obj->minStack);
}

// Free function for MinStack
void minStackFree(MinStack* obj) {
    while (!isEmpty(obj->stack)) {
        pop(&(obj->stack));
    }
    while (!isEmpty(obj->minStack)) {
        pop(&(obj->minStack));
    }
    free(obj);
}

// Example usage
int main() {
    MinStack* minStack = minStackCreate();
    minStackPush(minStack, -2);
    minStackPush(minStack, 0);
    minStackPush(minStack, -3);
    printf("Minimum element: %d\n", minStackGetMin(minStack)); // Returns -3
    minStackPop(minStack);
    printf("Top element: %d\n", minStackTop(minStack));        // Returns 0
    printf("Minimum element: %d\n", minStackGetMin(minStack)); // Returns -2
    minStackFree(minStack);
    return 0;
}
