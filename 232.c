#include <stdlib.h>

#define CAPACITY 100

typedef struct {
    int *elements;
    int front; // FI
    int rear;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue  *queue = malloc(sizeof(MyQueue));
    queue->elements = malloc(CAPACITY * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    return (queue);
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->rear < CAPACITY - 1) {
        obj->rear++;
        obj->elements[obj->rear] = x;
    }
}

bool myQueueEmpty(MyQueue* obj) {
    if (obj->front > obj->rear)
        return (true);
    return (false);
}

int myQueuePeek(MyQueue* obj) {
    if (!myQueueEmpty(obj))
        return (obj->elements[obj->front]);
    return (-1);
}

int myQueuePop(MyQueue* obj) {
    int val;
    
    if (myQueueEmpty(obj))
        return (-1);
    val = obj->elements[obj->front];
    obj->front++;
    if (obj->front > obj->rear) {
        obj->front = 0;
        obj->rear = -1;
    }
    return (val);
}

void myQueueFree(MyQueue* obj) {
    if (obj) {
        free (obj->elements);
        free (obj);
    }
}
