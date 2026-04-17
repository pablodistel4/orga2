FLAGS = -Wall -Wextra -pedantic

all: rotararreglo1

rotararreglo1: rotararreglo1.o
	gcc $(FLAGS) rotararreglo1.o -o rotararreglo1

rotararreglo1.o: rotararreglo1.c
	gcc $(FLAGS) -c rotararreglo1.c -o rotararreglo1.o

clean:
	rm *.o rotararreglo1

run: 
	./rotararreglo1.exe

.PHONY: all clean