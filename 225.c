#include <stdlib.h>

#define CAPACITY 100

typedef struct {
    int *elements;
    int top;
} MyStack;


MyStack* myStackCreate() {
    MyStack *s = malloc(sizeof(MyStack));
    s->elements = malloc(CAPACITY * sizeof(int));
    s->top = -1;
    return (s);
}

void myStackPush(MyStack* obj, int x) {
    if (obj->top < CAPACITY  -1)
        obj->elements[++obj->top] = x;
}

bool myStackEmpty(MyStack* obj) {
    if (obj->top != -1)
        return (false);
    return (true);
}

int myStackPop(MyStack* obj) {
    if (!myStackEmpty(obj))
        return(obj->elements[obj->top--]);
    return (-1);
}

int myStackTop(MyStack* obj) {
    if (!myStackEmpty(obj))
        return(obj->elements[obj->top]);
    return (-1);
}


void myStackFree(MyStack* obj) {
    if (obj) {
        free(obj->elements);
        free(obj);
    }
}
