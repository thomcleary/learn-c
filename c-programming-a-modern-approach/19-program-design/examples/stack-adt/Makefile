CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = stackclient

$(TARGET): $(TARGET).o stackADT.o
	$(CC) $(CC_FLAGS) -o $(TARGET) $(TARGET).o stackADT.o

$(TARGET)3: $(TARGET).o stackADT3.o
	$(CC) $(CC_FLAGS) -o $(TARGET)3 $(TARGET).o stackADT3.o


%.o: %.c stackADT.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET) $(TARGET)3 *.o