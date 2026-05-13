# Pseudocode Wiggle Sort

## Merge Sorted Arrays

```c
Algorithm merge_sorted_arrays(nums, l, m, r)
{
    left_len ← m - l + 1
    right_len ← r - m

    // copy data to temporary arrays
    for i ← 0 to left_len - 1 do
    {
        temp_left[i] ← nums[l + i]
    }

    for i ← 0 to right_len - 1 do
    {
        temp_right[i] ← nums[m + 1 + i]
    }

    i ← 0
    j ← 0
    k ← l

    // merge the temporary arrays back into nums
    while (i < left_len) and (j < right_len) do
    {
        if temp_left[i] <= temp_right[j] then
        {
            nums[k] ← temp_left[i]
            i ← i + 1
        }
        else
        {
            nums[k] ← temp_right[j]
            j ← j + 1
        }
        k ← k + 1
    }

    // copy any remaining elements of temp_left
    while i < left_len do
    {
        nums[k] ← temp_left[i]
        i ← i + 1
        k ← k + 1
    }

    // copy any remaining elements of temp_right
    while j < right_len do
    {
        nums[k] ← temp_right[j]
        j ← j + 1
        k ← k + 1
    }
}
```

## Merge Sort Non-Recursive

> Sorting using merge sort non-recursivly

```c
Algorithm sort_nonrecursive(nums, n)
{
    curr_size ← 1

    // bottom-up merge -> sizes 1, 2, 4, 8...
    while curr_size <= n - 1 do
    {
        left_start ← 0

        while left_start < n - 1 do
        {
            mid ← left_start + curr_size - 1

            if mid > n - 1 then
            {
                mid ← n - 1
            }

            right_end ← left_start + 2 * curr_size - 1

            if right_end > n - 1 then
            {
                right_end ← n - 1
            }

            merge_sorted_arrays(nums, left_start, mid, right_end)

            left_start ← left_start + 2 * curr_size
        }

        curr_size ← 2 * curr_size
    }
}
```

> Wiggle Sort Non-Recursive Pseudocode

```c
Algorithm wiggle_sort_nonrecursive(nums, n)
// nums is an array of size n
{
    // first we need to sort the array
    sort_nonrecursive(nums, 0, n - 1)

    // we create a temporary array and copy all of the original array elements in it to preserve the original array
    for i ← 0 to n - 1 do
    {
        temp[i] ← nums[i]
    }

    // we create two variables for the two halves of the array
    // mid points to the end of the smaller half
    // right points to the end of the larger half
    mid ← ((n + 1) / 2) - 1
    right ← n - 1

    // rebuild the original array using the two halves
    for i ← 0 to n - 1 do
    {
        // even indices get the largest available from the smaller half
        if (i % 2) = 0 then
        {
            nums[i] ← temp[mid]
            mid ← mid - 1
        }
        // odd indices get the largest available from the larger half
        else
        {
            nums[i] ← temp[right]
            right ← right - 1
        }
    }
}
```

---

## Wiggle Sort Recursive

> Sorting using merge sort recursivly

```c
Algorithm merge_sort_recursion(nums, l, r)
{
    if l < r then
    {
        m ← l + (r - l) / 2
        merge_sort_recursion(nums, l, m)
        merge_sort_recursion(nums, m + 1, r)

        merge_sorted_arrays(nums, l, m, r)
    }
}

Algorithm sort_recursive(nums, n)
{
    merge_sort_recursion(nums, 0, n - 1)
}
```

> Wiggle Sort Non-Recursive Pseudocode

```c
Algorithm recursive_interleave(nums, temp, left, right, i, n)
{
    if i = n then
    {
        return
    }


    if (i mod 2) = 0 then
    {
        nums[i] ← temp[left]
        recursive_interleave(nums, temp, left - 1, right, i + 1, n)
    }
    else
    {
        nums[i] ← temp[right]
        recursive_interleave(nums, temp, left, right - 1, i + 1, n)
    }
}

Algorithm wiggle_sort_recursive(nums, n)
{
    // we create a temporary array and copy all of the original array elements in it to preserve the original array
    for i ← 0 to n - 1 do
    {
        temp[i] ← nums[i]
    }

    sort_recursive(temp)

    left ← (n - 1) / 2
    right ← n - 1

    recursive_interleave(nums, temp, left, right, 0, n)
}
```

