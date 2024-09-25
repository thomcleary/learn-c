CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

remind: remind.o readline.o
	$(CC) $(CC_FLAGS) -o remind remind.o readline.o

%.o: %.c readline.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm remind *.o