#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int back;
    int len;
}   Array;

void    init_array(Array *arr, int len, int *nums) {
    arr->data = malloc(len * sizeof(int));
    if (!arr->data)
        return;
    for (int i = 0; i < len; i++) {
        arr->data[i] = nums[i];
    }
    arr->front = 0;
    arr->back = len - 1;
    arr->len = len;
}

void *next_greater(Array *arr, int len, int *returnSize, int *result) {
    printf("ICIIII\n");
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr->data[j] > arr->data[i]) {
                result[i] = arr->data[j];
                break;
            }
            result[i] = -1;
        }
    }
    *returnSize = len;
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

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int     *result;
    Array   arr;

    if (numsSize == 0)
        return (NULL);
    result = malloc(numsSize * sizeof(int));
    if (!result)
        return (NULL);
    if (numsSize == 1)
        result[0] = -1;
    else {
        init_array(&arr, numsSize, nums);
        printf("array struct array: ");
        print_array(arr.data, numsSize);
        next_greater(&arr, numsSize, returnSize, result);
    }
    return (result);
}

int main() {
    int *result;
    int nums[6] = {9, 7, 2, 3, 4, 4};
    int len = 6;
    int *return_len = NULL;

    printf("Initial array: ");
    print_array(nums, len);
    result = nextGreaterElements(nums, len, return_len);
    printf("Greater array: ");
    print_array(result, len);
}