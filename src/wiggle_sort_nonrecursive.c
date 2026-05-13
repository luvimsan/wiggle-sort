#include "wiggle_sort.h"

void wiggle_sort_nonrecursive(int nums[], int n) {
    int temp[n];
    sort(nums, 0, n - 1);

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
