/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int value;
    int top;
}   Stack;

void    find_warmer(int *temperatures, int len, int *answer, int *returnSize) {

    *returnSize = len;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *answer;

    answer = malloc(temperaturesSize * sizeof(int));
    if (!answer)
        return (NULL);
    if (temperaturesSize == 0)
        return (NULL);
    find_warmer(temperatures, temperaturesSize, &answer, &returnSize);
    return (answer);
}