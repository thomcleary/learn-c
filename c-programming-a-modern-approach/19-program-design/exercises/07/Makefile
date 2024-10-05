CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = 07

$(TARGET): $(TARGET).o stackADT2.o
	$(CC) $(CC_FLAGS) -o $(TARGET) $(TARGET).o stackADT2.o

%.o: %.c stackADT2.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET) *.o