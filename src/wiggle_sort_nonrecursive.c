#include "wiggle_sort.h"

void sort_nonrecursive(int nums[], int n) {
    int curr_size;
    int left_start;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {

        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {

            int mid = left_start + curr_size - 1;
            if (mid > n - 1) {
                mid = n - 1;
            }

            int right_end = left_start + 2 * curr_size - 1;
            if (right_end > n - 1) {
                right_end = n - 1;
            }

            merge_sorted_arrays(nums, left_start, mid, right_end);
        }
    }
}


void wiggle_sort_nonrecursive(int nums[], int n) {
    int temp[n];
    sort_nonrecursive(nums, n);

    for (int i = 0; i < n; i++) {
        temp[i] = nums[i];
    }

    int mid = ((n + 1) / 2) - 1;
    int right = n - 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            nums[i] = temp[mid];
            mid = mid - 1;
        }
        else {
            nums[i] = temp[right];
            right = right - 1;
        }
    }
}
