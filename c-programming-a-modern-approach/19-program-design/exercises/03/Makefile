CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET_A = 03a

$(TARGET_A): $(TARGET_A).o queue-array.o
	$(CC) $(CC_FLAGS) -o $(TARGET_A) $(TARGET_A).o queue-array.o

%.o: %.c queue.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET) *.o