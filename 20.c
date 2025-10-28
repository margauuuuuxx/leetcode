#include <stdio.h>
#include <stdbool.h>

#define MAX 10000

typedef struct Stack {
    char    value[MAX];
    int     top;
}   Stack;

void    init_stack(Stack *stack) {
    stack->top = -1;
}

size_t  stack_size(Stack *stack) {
    return (stack->top + 1);
}

bool    is_empty(Stack *stack) {
    if (stack->top == -1)
        return (true);
    return (false);
}

bool    is_full(Stack *stack) {
    if (stack->top == MAX -1)
        return (true);
    return (false);
}

char    pop(Stack *stack) {
    if (!is_empty(stack))
        return(stack->value[stack->top--]);
    return ('\0');
}

void    insert(Stack *stack, char c) {
    if (!is_full(stack))
        stack->value[++stack->top] = c;
}

bool    is_match(char open, char close) {
    if ((open == '(' && close == ')')
            || (open == '{' && close == '}')
            || (open == '[' && close == ']'))
        return (true);
    return (false);
}

bool isValid(char* s) {
    Stack   stack;
    char    open;

    init_stack(&stack);
    for (int i = 0; s[i]; i++) {
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (is_empty(&stack))
                return (false);
            open = pop(&stack);
            if (!is_match(open, s[i]))
                return (false);
        }
        else if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            insert(&stack, s[i]);
        else 
            printf("Wrong char submitted");
    }
    if (stack_size(&stack) != 0)
        return (false);
    return (true);
}