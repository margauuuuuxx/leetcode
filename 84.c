#include <stdlib.h>

typedef struct {
    int top;
    int *values;
}   Stack;

void    init_stack(Stack *s, int len) {
    s->values = malloc(len * sizeof(int));
    if (!s->values)
        return;
    s->top = -1;
}

int largestRectangleArea(int* heights, int heightsSize) {
    Stack   s;
    int     h;
    int     w;
    int     area;
    int     result;

    if (heightsSize == 0)
        return (0);
    init_stack(&s, heightsSize);
    result = 0;
    for (int i = 0; i < heightsSize; i++) {
        while (s.top != -1 && heights[i] < heights[s.values[s.top]]) {
            h = heights[s.values[s.top--]];
            w = (s.top == -1) ? i : i - s.values[s.top] - 1;
            area = h * w;
            result = (area > result) ? area : result; // case true --> left of the : ; case false --> right of the :
        }
        s.values[++s.top] = i; // push index i on the stack
    }
    while (s.top != -1) {
        h = heights[s.values[s.top--]];
        w = (s.top == -1) ? heightsSize : heightsSize - s.values[s.top] - 1;
        area = h * w;
        result = (area > result) ? area : result;
    }
    free(s.values);
    return (result);
}