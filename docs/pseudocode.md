## Pseudocode Wiggle Sort

## Wiggle Sort Non-Recursive

```c
Algorithm wiggle_sort_nonrecursive(nums, n)
// nums is an array of size n
{
    // first we need to sort the array
    sort(nums, 0, n - 1)

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

    sort(temp)

    left ← (n - 1) / 2
    right ← n - 1

    recursive_interleave(nums, temp, left, right, 0, n)
}
```

