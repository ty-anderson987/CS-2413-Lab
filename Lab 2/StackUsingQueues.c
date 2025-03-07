#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


typedef struct {
    struct Node* queuePush;
    struct Node* queuePop;
} MyStack;


MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    stack->queuePush = NULL;
    stack->queuePop = NULL;

    return stack;
}

void myStackPush(MyStack* obj, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    obj->queuePush = newNode;

    struct Node* move = obj->queuePop;
    obj->queuePop = NULL;
    newNode->next = move;

    struct Node* tmp = obj->queuePush;
    obj->queuePush = obj->queuePop;
    obj->queuePop = tmp;
}

int myStackPop(MyStack* obj) {
    if (obj->queuePop == NULL) {
        printf("underflow. no elements in enqueue and dequeue stacks.\n");
        return -1;
    }
    struct Node* tmp = obj->queuePop;
    int popped = tmp->data;
    obj->queuePop = (obj->queuePop)->next;
    free(tmp);
    return popped;
}

int myStackTop(MyStack* obj) {
    if (obj->queuePop == NULL) {
        printf("No data in stack\n");
        return -1;
    }
    return (obj->queuePop)->data;
}

bool myStackEmpty(MyStack* obj) {
    return obj->queuePush == NULL && obj->queuePop == NULL;
}

void myStackFree(MyStack* obj) {
    while (obj->queuePush != NULL) {
        struct Node* tmp = obj->queuePush;
        obj->queuePush = (obj->queuePush)->next;
        free(tmp);
    }
    while (obj->queuePop != NULL) {
        struct Node* tmp = obj->queuePop;
        obj->queuePop = (obj->queuePop)->next;
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