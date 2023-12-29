CC = g++
CFLAGS = -Wall -g
LIB = biblaureano
MAIN = main

$(MAIN): $(MAIN).o $(LIB).o
$(MAIN).o: $(MAIN).cpp $(LIB).h
$(LIB).o: $(LIB).cpp $(LIB).h

all: $(MAIN)

clean:
	rm -f *.o *~ $(MAIN)

