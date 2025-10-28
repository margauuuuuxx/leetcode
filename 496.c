bool    in_set(int check, int* set, int set_size) {
    for (int i = 0; i < set_size; i++) {
        if (set[i] == check)
            return (true);
    }
    return (false);
}

int find_greatest(int check, int* set, int set_size) {
    int i;

    i = 0;
    while (set[i] != check)
        i++;
    if (i == set_size)
        return (-1);
    while (i < set_size) {
        if (set[i] > check)
            return (set[i]);
        i++;
    }
    return (-1);
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int *result = malloc(nums1Size * sizeof(int));
    if (!result)
        return (NULL);
    
    for (int i = 0; i < nums1Size; i++) {
        if (!in_set(nums1[i], nums2, nums2Size))
            result[i] = -1;
        else 
            result[i] = find_greatest(nums1[i], nums2, nums2Size);
    }
    return (result);
}