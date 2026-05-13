CC = gcc
CFLAGS = -Wall -Wextra -I src

wiggle_sort: src/main.c src/wiggle_sort_recursive.c src/wiggle_sort_nonrecursive.c src/merge_sorted_arrays.c
	$(CC) $(CFLAGS) -o $@ $^
