CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = 03

$(TARGET)a: $(TARGET).o queue-array.o
	$(CC) $(CC_FLAGS) -o $(TARGET)a $(TARGET).o queue-array.o

$(TARGET)b: $(TARGET).o queue-list.o
	$(CC) $(CC_FLAGS) -o $(TARGET)b $(TARGET).o queue-list.o

%.o: %.c queue.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET)a $(TARGET)b *.o