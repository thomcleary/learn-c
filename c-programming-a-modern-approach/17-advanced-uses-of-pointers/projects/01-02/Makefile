CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = inventory

$(TARGET): $(TARGET).o readline.o
	$(CC) $(CC_FLAGS) -o $(TARGET) $(TARGET).o readline.o

%.o: %.c readline.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET) *.o