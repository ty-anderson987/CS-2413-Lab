#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


typedef struct {
    struct Node* enqueueStack;
    struct Node* dequeueStack;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    queue->enqueueStack = NULL;
    queue->dequeueStack = NULL;

    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = obj->enqueueStack; 
    obj->enqueueStack = newNode;
}

int myQueuePop(MyQueue* obj) {
    if (obj->dequeueStack == NULL) {
        while (obj->enqueueStack != NULL) {
            struct Node* temp = obj->enqueueStack;
            obj->enqueueStack = (obj->enqueueStack)->next;
            temp->next = obj->dequeueStack;
            obj->dequeueStack = temp;
        }
    }
    if (obj->dequeueStack == NULL) {
        printf("underflow. no elements in enqueue and dequeue stacks.\n");
        return -1;
    }
    
    struct Node* temp = obj->dequeueStack;
    int popped = temp->data;
    obj->dequeueStack = (obj->dequeueStack)->next;
    free(temp);
    return popped;
}

int myQueuePeek(MyQueue* obj) {
    if (obj->dequeueStack == NULL) {
        while (obj->enqueueStack != NULL) {
            struct Node* temp = obj->enqueueStack;
            obj->enqueueStack = (obj->enqueueStack)->next;
            temp->next = obj->dequeueStack;
            obj->dequeueStack = temp;
        }
    }
    if (obj->dequeueStack == NULL) {
        printf("underflow. no elements in enqueue and dequeue stacks.\n");
        return -1;
    }
    return (obj->dequeueStack)->data;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->enqueueStack == NULL && obj->dequeueStack == NULL;
}

void myQueueFree(MyQueue* obj) {
    while (obj->enqueueStack != NULL) {
        struct Node* temp = obj->enqueueStack;
        obj->enqueueStack = (obj->enqueueStack)->next;
        free(temp);
    }
    while (obj->dequeueStack != NULL) {
        struct Node* temp = obj->dequeueStack;
        obj->dequeueStack = (obj->dequeueStack)->next;
        free(temp);
    }
    free(obj);
}




/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/