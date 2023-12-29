CC = g++
CFLAGS = -Wall
TARGET = meu_programa

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: main.cpp biblaureano.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f $(TARGET) main.o

