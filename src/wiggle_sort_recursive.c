#include "wiggle_sort.h"

void merge_sort_recursion(int nums[], int l, int r) {
    if (l < r ) {
        int m = l + (r - l) / 2;
        merge_sort_recursion(nums, l, m);
        merge_sort_recursion(nums, m + 1, r);

        merge_sorted_arrays(nums, l, m, r);
    }
}

void sort_recursive(int nums[], int n) {
    merge_sort_recursion(nums, 0, n - 1);
}


void recursive_interleave(int nums[], int temp[], int left, int right, int i, int n) {
    if (i == n) {
        return;
    }


    if (i % 2 == 0) {
        nums[i] = temp[left];
        recursive_interleave(nums, temp, left - 1, right, i + 1, n);
    }
    else {
        nums[i] = temp[right];
        recursive_interleave(nums, temp, left, right - 1, i + 1, n);
    }
}

void wiggle_sort_recursive(int nums[], int n) {
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = nums[i];
    }
    sort_recursive(temp, n);

    int left = (n - 1) / 2;
    int right = n - 1;

    recursive_interleave(nums, temp, left, right, 0, n);

}
