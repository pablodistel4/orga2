FLAGS = -Wall -Wextra -pedantic

all: rotararreglo2

rotararreglo2: rotararreglo2.o
	gcc $(FLAGS) rotararreglo2.o -o rotararreglo2

rotararreglo2.o: rotararreglo2.c
	gcc $(FLAGS) -c rotararreglo2.c -o rotararreglo2.o

clean:
	rm *.o rotararreglo2

run: 
	./rotararreglo2.exe

.PHONY: all clean