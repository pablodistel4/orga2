all: holamundo

holamundo: holamundo.o
	gcc -Wall -Wextra -pedantic holamundo.o -o holamundo

holamundo.o: holamundo.c
	gcc -Wall -Wextra -pedantic -c holamundo.c -o holamundo.o

clean:
	rm *.o holamundo

.PHONY: all clean