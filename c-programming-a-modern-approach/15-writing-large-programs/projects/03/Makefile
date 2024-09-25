CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

qsort: qsort.o quicksort.o
	$(CC) $(CC_FLAGS) -o qsort qsort.o quicksort.o

%.o: %.c quicksort.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm qsort *.o