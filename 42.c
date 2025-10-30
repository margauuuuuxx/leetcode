#include <stdio.h>

int trap(int* height, int heightSize) {
    int result;
    int *left;
    int *right;
    int left_max;
    int right_max;
    
    if (heightSize <= 2)
        return (0);
    result = 0;
    left = height;
    right = height + heightSize - 1;
    left_max = 0;
    right_max = 0;
    while (left < right) {
        if (*left < *right) {
            left_max = (*left > left_max) ? *left : left_max;
            result += left_max - *left++;
        }
        else {
            right_max = (*right > right_max) ? *right : right_max;
            result += right_max - *right--;
        }
    }
    return (result);
}

int main() {
    int h[] = {4, 2, 0, 3, 2, 5};
    int h_len = 6;

    printf("Result = %d\n", trap(h, h_len));
    return (0);
}