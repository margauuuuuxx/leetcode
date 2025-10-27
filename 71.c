#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define CAPACITY 2000

typedef struct {
    char    *element;
    size_t  len;
}   Token;

typedef struct {
    Token   **tokens;
    int     top;
}   Stack;

void    free_token(Token *token) {
    if (token->element)
        free(token->element);
    free(token);
}

size_t  ft_strlen(char *s) {
    size_t  i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    init_stack(Stack *stack) {
    stack->tokens = malloc(sizeof(Token*) * CAPACITY);
    if (!stack->tokens)
        return;
    stack->top = -1;
}

void    push(Stack *stack, Token *token) {
    if (stack->top + 1 >= CAPACITY)
        return;
    stack->tokens[++stack->top] = token;
}

void    pop(Stack *stack) {
    if (stack->top == -1)
        return;
    free_token(stack->tokens[stack->top]);
    stack->top--;
}

void    free_stack(Stack *stack) {
    while (stack->top != -1)
        pop(stack);
    free(stack->tokens);
}

void    handle_dots(char *path, int *i, Stack *stack) {
    int     count;
    int     start;
    int     len;
    Token   *token;

    count = 0;
    while (path[(*i)] == '.') {
        (*i)++;
        count++;
    }
    if (count == 1 && (path[(*i)] == '/' || path[(*i)] == '\0'))
        return;
    if (count == 2 && (path[(*i)] == '/' || path[(*i)] == '\0'))
        pop(stack);
    else {
        start = (*i) - count;
        while (path[(*i)] != '/' && path[(*i)] != '\0')
            (*i)++;
        len = (*i) - start;
        token = malloc(sizeof(Token));
        if (!token)
            return;
        token->element = malloc((len + 1) * sizeof(char));
        if (!token->element) {
            free(token);
            return;
        }
        token->len = len + 1;
        strncpy(token->element, path + start, len);
        token->element[len] = '\0';
        push(stack, token);
    }
}

void    handle_token(char *path, int *i, Stack *stack) {
    int     start;
    int     len;
    Token   *token;


    start = (*i);
    while (path[(*i)] != '/' && path[(*i)] != '\0')
        (*i)++;
    len = (*i) - start;
    if (len <= 0)
        return;
    token = malloc(sizeof(Token));
    if (!token)
        return;
    token->element = malloc((len + 1) * sizeof(char));
    if (!token->element)
        return;
    token->len = len + 1;
    strncpy(token->element, path + start, len);
    token->element[len] = '\0';
    push(stack, token);
}

void    parse(char *path, Stack *stack) {
    int     i;
    size_t  len;

    if (path[0] != '/')
        return;
    i = 0;
    len = ft_strlen(path);
    while (i < len) {
        if (path[i] == '/')
            while (i < len && path[i] == '/')
                i++;
        else if (path[i] == '.')
            handle_dots(path, &i, stack);
        else
            handle_token(path, &i, stack);
    }
}

char    *build_path(Stack *stack) {
    char    *result;
    size_t  total_len;

    total_len = 0;
    for (int i = 0; i <= stack->top; i++) {
        total_len += stack->tokens[i]->len;
    }
    if (total_len == 0)
        return (strdup("/"));
    result = malloc((total_len + stack->top + 2) * sizeof(char));
    if (!result)
        return (NULL);
    result[0] = '\0';
    for (int i = 0; i <=stack->top; i++) {
        strcat(result, "/");
        strcat(result, stack->tokens[i]->element);
    }
    return (result);
}

char* simplifyPath(char* path) {
    Stack   stack;
    char    *result;

    init_stack(&stack);
    parse(path, &stack);
    result = build_path(&stack);
    free_stack(&stack);
    return (result);
}

int main() {
    char path[] = "/a//b////c/d//././/..";
    char *result = simplifyPath(path);
    printf("Result: %s\n", result);
}