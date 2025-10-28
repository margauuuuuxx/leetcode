#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
}   Array;

void    init_array(Array *arr, int len, int *nums) {
    arr->data = malloc(len * sizeof(int));
    if (!arr->data)
        return;
    arr->front = 0;
    arr->rear = len - 1;
    for (int i = 0; i < len; i++)
        arr->data[i] = nums[i];
}

void next_greater(Array *arr, int len, int *returnSize, int *result) {
    int k;

    for (int i = 0; i < len; i++) {
        result[i] = -1;
        for (int j = 1; j < len; j++) {
            k = (i + j) % len;
            if (arr->data[k] > arr->data[i]) {
                result[i] = arr->data[k];
                break;
            }
        }
    }
    *returnSize = len;
}

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int     *result;
    Array   arr;
    
    if (numsSize == 0)
    return (NULL);
    result = malloc(numsSize * sizeof(int));
    if (!result)
            return (NULL);
    init_array(&arr, numsSize, nums);
    next_greater(&arr, numsSize, returnSize, result);
    return (result);
}

void    print_array(int *arr, int len) {
    printf("[");
    for (int i = 0; i < len; i++){
        printf("%d", arr[i]);
        if (i < len - 1)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    int *result;
    int nums[1] = {1};
    int len = 1;
    int return_len = 0;

    printf("Initial array: ");
    print_array(nums, len);
    result = nextGreaterElements(nums, len, &return_len);
    printf("Greater array: ");
    print_array(result, len);
}