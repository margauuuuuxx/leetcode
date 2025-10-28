/*
    Fenwick tree (Binary Indexed Tree - BIT)

    Steps:
        1. Compress coordinates (sort --> unique --> map)


*/

#pragma GCC optimize("03")

#include <stdlib.h>
#include <stdio.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

typedef struct {
    int N;
    int *tree;
}   Fenwick;

void    init_fenwick(Fenwick *f, int len) {
    int parent;
    
    f->N = len;
    f->tree = calloc((len + 1), sizeof(int));
    if (!f->tree)
        return;
}

void    fenwick_update(Fenwick *f, int idx, int val) {
    while (idx <= f->N) {
        f->tree[idx] += val;
        idx += (idx & -idx);
    }
}

int fenwick_query(Fenwick *f, int idx) {
    int sum;

    sum = 0;
    while (idx > 0) {
        sum += f->tree[idx];
        idx -= (idx & -idx);
    }
    return (sum);
}

int map_values(int *arr, int len, int target) {
    int left;
    int right;
    int med;

    left = 0;
    right = len - 1;
    while (left <= right) {
        med = left + (right - left) / 2;
        if (arr[med] == target)
            return (med + 1);
        else if (arr[med] < target)
            left = med + 1;
        else 
            right = med - 1;
    }
    return (-1);
}

int *remove_duplicates(int *arr, int len, int *new_len) {
    int *result;
    int j;

    j = 0;
    result = malloc(len * sizeof(int));
    if (!result)
        return (NULL);
    for (int i = 0; i < len; i++) {
        if (i == 0 || arr[i] != arr[i - 1])
            result[j++] = arr[i];
    }
    *new_len = j;
    return (result);
}

int *compress_coordinates(int *nums, int len, int *unique_len) {
    int *copy;
    int *result;
    int *unique;

    copy = malloc(len * sizeof(int));
    if (!copy)
        return (NULL);
    for (int i = 0; i < len; i++)
        copy[i] = nums[i];
    qsort(copy, len, sizeof(int), cmp);
    unique = remove_duplicates(copy, len, unique_len);
    result = malloc(len * sizeof(int));
    if (!result)
        return (NULL);
    for (int i = 0; i < len; i++)
        result[i] = map_values(unique, *unique_len, nums[i]);
    free(copy);
    free(unique);
    return (result);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int     *result;
    int     *compressed;
    int     compressed_len;
    Fenwick f;

    *returnSize = numsSize;
    if (numsSize == 0)
        return (NULL);
    compressed = compress_coordinates(nums, numsSize, &compressed_len);
    init_fenwick(&f, compressed_len);
    result = malloc(numsSize * sizeof(int));
    if (!result)
        return (NULL);
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] = fenwick_query(&f, compressed[i] - 1);
        fenwick_update(&f, compressed[i], 1);
    }
    free(compressed);
    free(f.tree);
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
    int arr[] = {0, 9, 9, 87, 4};
    int len = 5;
    int result_len = 0;

    printf("Initial array: ");
    print_array(arr, len);

    int *result = countSmaller(arr, len, &result_len);
    printf("\nResult array: ");
    print_array(result, len);
}