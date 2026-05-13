#include "wiggle_sort.h"

void merge_sorted_arrays(int nums[], int l, int m, int r) {
    int left_len = m - l + 1;
    int right_len = r - m;

    int temp_left[left_len];
    int temp_right[right_len];

    for (int i = 0; i < left_len; i++) {
        temp_left[i] = nums[l + i];
    }
    for (int i = 0; i < right_len; i++) {
        temp_right[i] = nums[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < left_len && j < right_len) {
        if (temp_left[i] <= temp_right[j]) {
            nums[k] = temp_left[i];
            i++;
        }
        else {
            nums[k] = temp_right[j];
            j++;
        }
        k++;
    }

    while (i < left_len) {
        nums[k] = temp_left[i];
        i++;
        k++;
    }

    while (j < right_len) {
        nums[k] = temp_right[j];
        j++;
        k++;
    }

}

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
