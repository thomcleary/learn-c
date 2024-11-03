/*
Write a program that uses the clock function to measure how long it takes qsort
to sort an array of 1_000 integers that are originall sorted in reverse order.

Run the program for arrays of 10_000 and 100_000 integers as well
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int int_compare(const void *a, const void *b) {
  return (*(int *)a) - (*(int *)b);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ./03 size\n");
    exit(EXIT_FAILURE);
  }

  errno = 0;
  unsigned long long int size = strtoull(argv[1], NULL, 10);
  if (errno != 0) {
    perror("Invalid size");
    exit(EXIT_FAILURE);
  }

  if (size > SIZE_MAX) {
    fprintf(stderr, "Size must be less than or equal to %lu\n", SIZE_MAX);
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

  unsigned long long int *nums = malloc(size * sizeof(*nums));
  if (nums == NULL) {
    fprintf(stderr, "Failed to allocate array of size %llu\n", size);
    exit(EXIT_FAILURE);
  }

  for (size_t i = 0; i < size; i++) {
    nums[i] = size - i;
  }

  clock_t start = clock();
  if (start == -1) {
    fprintf(stderr, "start clock failed\n");
    exit(EXIT_FAILURE);
  }

  qsort(nums, size, sizeof(*nums), int_compare);

  clock_t end = clock();
  if (end == -1) {
    fprintf(stderr, "end clock failed\n");
    exit(EXIT_FAILURE);
  }

  printf("Took %lf seconds to sort %llu array elements\n",
         (end - start) / (double)(CLOCKS_PER_SEC), size);

  free(nums);
  return 0;
}
