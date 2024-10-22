CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = inventory
OBJS = readline.o

$(TARGET): $(TARGET).o $(OBJS)
	$(CC) $(CC_FLAGS) -o $(TARGET) $(TARGET).o $(OBJS)

%.o: %.c readline.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET) $(OBJS) *.o