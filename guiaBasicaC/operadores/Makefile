FLAGS = -Wall -Wextra -pedantic

all: operadores

operadores: operadores.o
	gcc $(FLAGS) operadores.o -o operadores

operadores.o: operadores.c
	gcc $(FLAGS) -c operadores.c -o operadores.o

clean:
	rm *.o operadores

run: 
	./operadores.exe

.PHONY: all clean