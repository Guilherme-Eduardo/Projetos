CC = g++
CFLAGS = -Wall -g
LIB = biblaureano
MAIN = main

$(MAIN): $(MAIN).o $(LIB).o
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN).o $(LIB).o

$(MAIN).o: $(MAIN).cpp $(LIB).h
	$(CC) $(CFLAGS) -c $(MAIN).cpp

$(LIB).o: $(LIB).cpp $(LIB).h
	$(CC) $(CFLAGS) -c $(LIB).cpp

all: $(MAIN)

clean:
	rm -f *.o *~ $(MAIN)

