FLAGS = -Wall -Wextra -pedantic

all: mascaras

mascaras: mascaras.o
	gcc $(FLAGS) mascaras.o -o mascaras

mascaras.o: mascaras.c
	gcc $(FLAGS) -c mascaras.c -o mascaras.o

clean:
	rm *.o mascaras

run: 
	./mascaras.exe

.PHONY: all clean