FLAGS = -Wall -Wextra -pedantic

all: tamanio

tamanio: tamanio.o
	gcc $(FLAGS) tamanio.o -o tamanio

tamanio.o: tamanio.c
	gcc $(FLAGS) -c tamanio.c -o tamanio.o

clean:
	rm *.o tamanio

run: 
	./tamanio.exe

.PHONY: all clean