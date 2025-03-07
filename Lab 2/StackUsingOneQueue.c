#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


typedef struct {
    struct Node* queue;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    stack->queue = NULL;

    return stack;
}

void myStackPush(MyStack* obj, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = x;
    newNode->next = obj->queue;
    obj->queue = newNode;
}

int myStackPop(MyStack* obj) {
    if (obj->queue == NULL) {
        printf("underflow. no elements in enqueue and dequeue stacks.\n");
        return -1;
    }
    struct Node* tmp = obj->queue;
    int popped = tmp->data;
    obj->queue = (obj->queue)->next;
    free(tmp);
    return popped;
}

int myStackTop(MyStack* obj) {
    if (obj->queue == NULL) {
        printf("No data in stack\n");
        return -1;
    }
    return (obj->queue)->data;
}

bool myStackEmpty(MyStack* obj) {
    return obj->queue == NULL;
}

void myStackFree(MyStack* obj) {
    while (obj->queue != NULL) {
        struct Node* tmp = obj->queue;
        obj->queue = (obj->queue)->next;
        free(tmp);
    }
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/