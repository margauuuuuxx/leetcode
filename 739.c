#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 100000

typedef struct {
    int *elements;
    int top;
}   Stack;

void    init_stack(Stack *stack, int len) {
    stack->elements = malloc(len * sizeof(int));
    if (!stack->elements)
        return;
    stack->top = -1;
}

bool    is_empty(Stack *stack) {
    if (stack->top == -1)
        return (true);
    return (false);
}

void    push(Stack *stack, int value) {
    if (stack->top + 1 > CAPACITY)
        return;
    stack->elements[++stack->top] = value;
}

void    pop(Stack *stack) {
    if (!is_empty(stack))
        stack->top--;
}

int top(Stack *stack) {
    if (!is_empty(stack))
        return (stack->elements[stack->top]);
    return (-1);
}

void    find_warmer(int *temperatures, int len, int *answer, int *returnSize, Stack *stack) {
    int idx;

    for (int i = 0; i < len; i++) {
        //printf("i = %d; temp[i] = %d ; stack->top = %d ; temp[top] = %d\n\n", i, temperatures[i], top(stack), temperatures[top(stack)]);
        while (!is_empty(stack) && temperatures[i] > temperatures[top(stack)]) {
            idx = top(stack);
            answer[idx] = i - idx;
            pop(stack); 
        }
        push(stack, i);
    }
    *returnSize = len;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int     *answer;
    Stack   stack;

    answer = calloc(temperaturesSize, sizeof(int));
    if (!answer)
        return (NULL);
    if (temperaturesSize == 0)
        return (NULL);
    init_stack(&stack, temperaturesSize);
    find_warmer(temperatures, temperaturesSize, answer, returnSize, &stack);
    return (answer);
}

void    print_array(int *arr, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
        if (i < len - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    int temps[8] = {73,74,75,71,69,72,76,73};
    int len = 8;
    int return_len = 0;
    int *result;

    printf("Inital array: ");
    print_array(temps, len);
    printf("\n");

    result = dailyTemperatures(temps, len, &return_len);
    printf("Resulting array: ");
    print_array(result, len);
}