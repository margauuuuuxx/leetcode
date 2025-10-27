/*
    Implementing a RADIX sort
        Least significant digit (LSD) = unites then dizaines then centaines, ...
*/

#include <stdio.h>

int get_max(int *array, int len) {
    int max;

    max = array[0];
    for (int i = 0; i < len; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return (max);
}

void    count_sort(int *array, int len, int exp) {
    int output[len];
    int i;
    int count[10] = { 0 };

    for (i = 0; i < len; i++)
        count[(array[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = len - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) %10]--;
    }
    for (i = 0; i < len; i++)
        array[i] = output[i];
}

void    radix_sort(int *nums, int nums_len) {
    int max;
    
    max = get_max(nums, nums_len);
    for (int i = 1; max / i > 0; i *= 10) {
        count_sort(nums, nums_len, i);
        if (i > max / 10)
            break;
    }
}

int compute_max_gap(int *nums, int nums_len) {
    int max;

    max = nums[1] - nums[0];
    printf("array[0] = %d ; array[1] = %d ; inital max = %d\n", nums[0], nums[1], max);
    for (int i = 2; i < nums_len; i++) {
        if (nums[i] - nums[i - 1] > max)
            max = nums[i] - nums[i - 1];
        printf("i = %d ; arr[i] = %d ; arr[i - 1] = %d ; max = %d\n", i, nums[i], nums[i - 1], max);
    }
    return (max);
}

void    print_list(int *nums, int nums_len) {
    printf("[");
    for (int i = 0; i < nums_len; i++) {
        printf("%d", nums[i]);
        if (i < nums_len - 1)
            printf(", ");
    }
    printf("]\n");
}

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2)
    return (0);
radix_sort(nums, numsSize);
printf("Sorted list: ");
print_list(nums, numsSize);
return(compute_max_gap(nums, numsSize));
}


int main() {
    int nums[2] = {1000000000,1000000000};
    int  numsSize = 2;

    printf("Initial list: ");
    print_list(nums, numsSize);
    printf("Max gap = %d\n", maximumGap(nums, numsSize));
    return (0);
}