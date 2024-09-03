CC=g++
WARN=-Wall
TARGET=meu_programa
SRCS= Poligono.cpp Ponto.cpp Quadrado.cpp Reta.cpp
OBJS= Poligono.o Ponto.o Quadrado.o Reta.o main.o

$(TARGET): $(OBJS)
	$(CC) $(WARN) $(OBJS) -o $(TARGET) 

main.o: main.cpp Ponto.o Reta.o Quadrado.o Poligono.o
	$(CC) $(WARN) -c main.cpp -o main.o

Ponto.o: Ponto.cpp Ponto.hpp
	$(CC) $(WARN) -c Ponto.cpp -o Ponto.o

Reta.o: Reta.cpp Ponto.o
	$(CC) $(WARN) -c Reta.cpp -o Reta.o

Quadrado.o: Quadrado.cpp Quadrado.hpp Reta.o
	$(CC) $(WARN) -c Quadrado.cpp -o Quadrado.o

Poligono.o: Poligono.cpp Poligono.hpp Reta.o
	$(CC) $(WARN) -c Poligono.cpp -o Poligono.o

clean:
	rm -f *.o

purge:
	rm $(TARGET)

