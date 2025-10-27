/*
    Steps:
        1. Sorting the intervals in ascending order of their first elements using a merge sort
        2. Merge the intervals doing comparisons of the sorted array 
        3. Done 
*/

#include <stdio.h>
#include <stdlib.h>

int **merge_intervals(int **intervals, int intervals_nbr, int *return_size, int **returnColumnSizes) {
    int j;
    
    j = 0;
    for (int i = 1; i < intervals_nbr; i++) {
        if (intervals[j][1] >= intervals[i][0]) {
            if (intervals[j][1] < intervals[i][1])
            intervals[j][1] = intervals[i][1];
        }
        else {
            j++;
            intervals[j][0] = intervals[i][0];
            intervals[j][1] = intervals[i][1];
        }
    }
    *return_size = j + 1;
    *returnColumnSizes = malloc(*return_size * sizeof(int));
    if (!*returnColumnSizes)
        return (NULL);
    for (int i = 0; i < *return_size; i++)
        (*returnColumnSizes)[i] = 2;
    return (intervals);
}

void    merge_sorted(int **intervals, int left, int mid, int right) {
    int i;
    int j;
    int k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int left_arr[n1][2];
    int right_arr[n2][2];

    for (i = 0; i < n1; i++) {
        left_arr[i][0] = intervals[left + i][0];
        left_arr[i][1] = intervals[left + i][1];
    }
    for (j = 0; j < n2; j++) {
        right_arr[j][0] = intervals[mid + 1 + j][0];
        right_arr[j][1] = intervals[mid + 1 + j][1]; 
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (left_arr[i][0] <= right_arr[j][0]) {
            intervals[k][0] = left_arr[i][0];
            intervals[k][1] = left_arr[i][1];
            i++;
        }
        else {
            intervals[k][0] = right_arr[j][0];
            intervals[k][1] = right_arr[j][1];
            j++;
        }
        k++;
    }
    while (i < n1) {
        intervals[k][0] = left_arr[i][0];
        intervals[k][1] = left_arr[i][1];
        i++;
        k++;
    }
    while (j < n2) {
        intervals[k][0] = right_arr[j][0];
        intervals[k][1] = right_arr[j][1];
        j++;
        k++;
    }
}

// uses indices not values
void    sort_intervals(int **intervals, int left, int right) {
    int mid;

    if (left < right) {
        mid = left + (right - left) / 2;
        sort_intervals(intervals, left, mid);
        sort_intervals(intervals, mid + 1, right);
        merge_sorted(intervals, left, mid, right);
    }
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0)
        return (NULL);
    sort_intervals(intervals, 0, intervalsSize - 1);
    return (merge_intervals(intervals, intervalsSize, returnSize, returnColumnSizes));
}

void    print_array(int **array, int size) {
    int i;

    i = 0;
    printf("[ ");
    while (i < size) {
        printf("[%d, %d]", array[i][0], array[i][1]);
        if (i < size - 1)
            printf(", ");
        i++;
    }
    printf(" ]\n");
}

int main() {
    int intervalsSize = 4;
    int **intervals = malloc(intervalsSize * sizeof(int*));
    for (int i = 0; i < intervalsSize; i++)
    intervals[i] = malloc(2 * sizeof(int));

    intervals[0][0] = 1; intervals[0][1] = 3;
    intervals[1][0] = 2; intervals[1][1] = 6;
    intervals[2][0] = 8; intervals[2][1] = 10;
    intervals[3][0] = 15; intervals[3][1] = 18;

    printf("Initial array: ");
    print_array(intervals, intervalsSize);

    int returnSize;
    int *returnColumnSizes;
    int *intervalsColSize = malloc(intervalsSize * sizeof(int));
    for (int i = 0; i < intervalsSize; i++)
    intervalsColSize[i] = 2;

    int **result = merge(intervals, intervalsSize, intervalsColSize, &returnSize, &returnColumnSizes);  
    printf("Result array: ");
    print_array(result, returnSize);
}