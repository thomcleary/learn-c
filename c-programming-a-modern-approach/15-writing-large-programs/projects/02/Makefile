CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

justify: justify.o word.o line.o
	$(CC) $(CC_FLAGS) -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	$(CC) $(CC_FLAGS) -c justify.c

word.o: word.c word.h
	$(CC) $(CC_FLAGS) -c word.c

line.o: line.c line.h
	$(CC) $(CC_FLAGS) -c line.c

clean:
	rm justify *.o

# For more information on creating more generic Makefiles see:
# https://diveintosystems.org/book/Appendix2/makefiles.html#genericmulti