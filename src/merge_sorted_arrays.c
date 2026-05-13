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
