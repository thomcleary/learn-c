CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = 06

$(TARGET)a: $(TARGET).o stackADT.o
	$(CC) $(CC_FLAGS) -o $(TARGET)a $(TARGET).o stackADT.o


%.o: %.c stackADT.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET)a *.o