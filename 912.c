/*
    Implementing a quick sort
        1. Choose a pivot --> using the median-of-five
        2. Partition the array --> Hoare's partition
        3. Recursively call
        4. Base case --> when there's only 1 element left in the sub-array
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void    print_array(int *array, int len) {
    printf("[");
    for (int i = 0; i < len; i ++) {
    printf("%d", array[i]);
    if (i < len - 1)
        printf(", ");
    }
    printf("]\n");
}

void    swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void    insertion_sort(int *array, int len) {
    int key;
    int j;

    for (int i = 1; i < len; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int find_median_five(int *array, int len) {
    int elements[5] = { array[0], array[len / 4], array[len / 2], array[(3 * len) / 4], array[len - 1] };
    insertion_sort(elements, 5);
    return (elements[2]);
}

int find_pivot(int *array, int len) {
    if (len <= 5)
        return (array[len / 2]);
    else
        return (find_median_five(array, len));
}

int partition(int *array, int pivot, int low, int high) {
    // printf("Pivot = %d ; high = %d ; low = %d ; Partition array: ", pivot, high, low);
    // int len = sizeof(array) / sizeof(array[low]);
    // print_array(array, len);
    int i;
    int j;

    i = low - 1;
    j = high + 1;
    while (1) {
        do {
            i++;
        }   while (array[i] < pivot);
        do {
            j--;
        }   while (array[j] > pivot);
        if (i >= j)
            return (j);
        swap(&array[i], &array[j]);
    }
    return (-1);
}

void    sort(int *array, int low, int high) {
    int pivot_val;
    int pivot_index;
    
    if (!array)
        return;
    if (low >= high)
        return;
    if (high - low == 1 && array[low] > array[high])
        swap(&array[low], &array[high]);
    if (high - low <= 1)
        return;
    pivot_val = find_pivot(array + low, high - low + 1);
    pivot_index = partition(array + low, pivot_val, 0, high - low) + low;
    sort(array, low, pivot_index);
    sort(array, pivot_index + 1, high);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int *result;
    
    if (numsSize <= 0) {
        *returnSize = 0;
        return (NULL);
    }
    result = malloc(numsSize * sizeof(int));
    if (!result)
        return (NULL);
    for (int i = 0; i < numsSize; i++)
        result[i] = nums[i];
    sort(result, 0, numsSize - 1);
    *returnSize = numsSize;
    return (result);
}


int main() {
    int nums[] = {0,7,-5};
    int nums_len = sizeof(nums) / sizeof(nums[0]);
    int return_len = nums_len;
    printf("Inital: ");
    print_array(nums, nums_len);
    int *result = sortArray(nums, nums_len, &return_len);
    printf("Sorted: ");
    print_array(result, nums_len);
    free(result);
    return(0);
}