/*
    red(0) >> white(1) >> blue(2)
    in-place sort = sorting algo that directly modifies the list wthout creating a copy of it 
*/

#include <stdio.h>

void    print_list(int *array, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i < len - 1)
            printf(", ");
    }
    printf("]\n");
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sortColors(int* nums, int numsSize) {
    int low;
    int mid;
    int high;

    if (numsSize == 0 || numsSize == 1)
        return;
    low = 0;
    mid = 0;
    high = numsSize - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            // printf("CASE 0: Swapping low-->nums[%d] = %d with mid-->nums[%d] = %d\n", low, nums[low], mid, nums[mid]);
            swap(&nums[low], &nums[mid]);
            // printf("List after swap: ");
            // print_list(nums, numsSize);
            // printf("\n");
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            // printf("CASE 1: incrementing mid from %d to %d\n", mid, mid + 1);
            // printf("\n");
            mid++;
        } else if (nums[mid] == 2) {
            // printf("CASE 2: Swapping mid-->nums[%d] = %d with high-->nums[%d] = %d\n", mid, nums[mid], high, nums[high]);
            swap(&nums[mid], &nums[high]);
            // printf("List after swap: ");
            // print_list(nums, numsSize);
            // printf("\n");
            high--;
        }
        else
            return;
    }

}

int main() {
    int input[6] = {1, 0, 0, 2, 2, 1};
    int numsSize = 6;
    printf("Initial list: ");
    print_list(input, numsSize);
    printf("\n");
    sortColors(input, numsSize);
    printf("Sorted list: ");
    print_list(input, numsSize);
}