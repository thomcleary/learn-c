CC = cc 
CC_FLAGS = -std=c99 -Wall -Werror

TARGET = 06

$(TARGET)a: $(TARGET).o stackADT.o
	$(CC) $(CC_FLAGS) -o $(TARGET)a $(TARGET).o stackADT.o

$(TARGET)b: $(TARGET)b.o stackADT2.o
	$(CC) $(CC_FLAGS) -o $(TARGET)b $(TARGET)b.o stackADT2.o

$(TARGET)c: $(TARGET).o stackADT3.o
	$(CC) $(CC_FLAGS) -o $(TARGET)c $(TARGET).o stackADT3.o

stackADT2.o: stackADT2.c stackADT2.h
	$(CC) $(CC_FLAGS) -c $<

%.o: %.c stackADT.h
	$(CC) $(CC_FLAGS) -c $<

clean:
	rm $(TARGET)a $(TARGET)b *.o