CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = main
OBJS =

$(TARGET): $(TARGET).o $(OBJS)
	$(CC) $(CC_FLAGS) -o $(TARGET) $(TARGET).o $(OBJS)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET) $(OBJS) *.o