FLAGS = -Wall -Wextra -pedantic

all: whileprueba

whileprueba: whileprueba.o
	gcc $(FLAGS) whileprueba.o -o whileprueba

whileprueba.o: whileprueba.c
	gcc $(FLAGS) -c whileprueba.c -o whileprueba.o

clean:
	rm *.o whileprueba

run: 
	./whileprueba.exe

.PHONY: all clean