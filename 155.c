#define CAPACITY 10000

typedef struct {
    int *elements;
    int *mins;
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack    *stack;

    stack = malloc(sizeof(MinStack));
    if (!stack)
        return (NULL);
    stack->elements = malloc(CAPACITY * sizeof(int));
    stack->mins = malloc(CAPACITY * sizeof(int));
    stack->top = -1;
    return (stack);
}

void minStackPush(MinStack* obj, int val) {
    int t;
    
    if (!obj)
        return;
    t = ++obj->top;
    if (t < CAPACITY - 1)
        obj->elements[t] = val;
    if (t == 0)
        obj->mins[t] = val;
    else {
        if (val < obj->mins[t - 1])
            obj->mins[t] = val;
        else 
            obj->mins[t] = obj->mins[t -1];
    }
}

void minStackPop(MinStack* obj) {
    if (!obj || obj->top == -1)
        return;
    --obj->top;
}

int minStackTop(MinStack* obj) {
    if (!obj || obj->top == -1)
        return (0);
    return (obj->elements[obj->top]);
}

int minStackGetMin(MinStack* obj) {
    if (!obj || !obj->mins || obj->top == -1)
        return (0);
    return (obj->mins[obj->top]);
}

void minStackFree(MinStack* obj) {
    if (obj) {
        free(obj->elements);
        free(obj->mins);
        free(obj);
    }
}
