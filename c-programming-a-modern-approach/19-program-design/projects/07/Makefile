CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = queueclient

$(TARGET): $(TARGET).o queueADT.o
	$(CC) $(CC_FLAGS) -o $(TARGET) $(TARGET).o queueADT.o

%.o: %.c stackADT.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET) *.o