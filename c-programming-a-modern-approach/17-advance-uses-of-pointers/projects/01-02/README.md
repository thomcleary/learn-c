# Exercise 1, 2

## Exercise 1

Modify the `inventory.c` program of Section 16.3 so that the inventory array is allocated dynamically and later reallocated when it fills up. Use `malloc` initially to allocate enouh space for an array of 10 part structures. When the array has no more room for new parts, use `realloc` to double its size. Repeat the doubling step each time the array becomes full.

## Exercise 2

Modify the `inventory.c` program of Section 16.3 so that the `p` (print) command calls `qsort` to sort the inventory array before it prints the parts.
