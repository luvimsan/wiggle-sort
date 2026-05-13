#include "wiggle_sort.h"
#include <stdio.h>

void print_arr(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums1[] = {1, 5, 1, 1, 6, 4};
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Original array: ");
    print_arr(nums1, n1);
    wiggle_sort_nonrecursive(nums1, n1);
    printf("Wiggled sorted array: ");
    print_arr(nums1, n1);

    int nums2[] = {1, 3, 2, 2, 3, 1};
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Original array: ");
    print_arr(nums2, n2);
    wiggle_sort_nonrecursive(nums2, n2);
    printf("Wiggled sorted array: ");
    print_arr(nums2, n2);

    return 0;
}
