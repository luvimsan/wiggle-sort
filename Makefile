CC = gcc
CFLAGS = -Wall -Wextra -I src

wiggle_sort: src/main.c src/wiggle_sort_recursive.c src/wiggle_sort_nonrecursive.c
	$(CC) $(CFLAGS) -o $@ $^
