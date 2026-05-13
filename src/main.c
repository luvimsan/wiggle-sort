#include "wiggle_sort.h"
#include <stdio.h>

void print_arr(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums1_nr[] = {1, 5, 1, 1, 6, 4};
    int n1 = sizeof(nums1_nr) / sizeof(nums1_nr[0]);

    int nums2_nr[] = {1, 3, 2, 2, 3, 1};
    int n2 = sizeof(nums2_nr) / sizeof(nums2_nr[0]);

    // wiggle_sort_nonrecursive
    printf("===Wiggle Sort Non-recursive===\n");

    printf("Example 1\n");
    printf("Original array\n");
    print_arr(nums1_nr, n1);
    wiggle_sort_nonrecursive(nums1_nr, n1);
    printf("Wiggled sorted with Non-recursive\n");
    print_arr(nums1_nr, n1);
    printf("\n");

    printf("Example 2\n");
    printf("Original array\n");
    print_arr(nums2_nr, n2);
    wiggle_sort_nonrecursive(nums2_nr, n2);
    printf("Wiggled sorted array\n");
    print_arr(nums2_nr, n2);

    printf("\n========================\n");

    int nums1_rec[] = {1, 5, 1, 1, 6, 4};
    int nums2_rec[] = {1, 3, 2, 2, 3, 1};

    // wiggle_sort_recursive
    printf("===Wiggle Sort Recursive===\n");

    printf("Example 1\n");
    printf("Original array\n");
    print_arr(nums1_rec, n1);
    wiggle_sort_recursive(nums1_rec, n1);
    printf("Wiggled sorted with Recursive\n");
    print_arr(nums1_rec, n1);
    printf("\n");

    printf("Example 2\n");
    printf("Original array\n");
    print_arr(nums2_rec, n2);
    wiggle_sort_recursive(nums2_rec, n2);
    printf("Wiggled sorted array\n");
    print_arr(nums2_rec, n2);

    return 0;
}
