CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = calc

$(TARGET): $(TARGET).o stack.o
	$(CC) $(CC_FLAGS) -o $(TARGET) $(TARGET).o stack.o

%.o: %.c stack.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET) *.o