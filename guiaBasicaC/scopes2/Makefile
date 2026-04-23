FLAGS = -Wall -Wextra -pedantic

all: scopes2

scopes2: scopes2.o
	gcc $(FLAGS) scopes2.o -o scopes2

scopes2.o: scopes2.c
	gcc $(FLAGS) -c scopes2.c -o scopes2.o

clean:
	rm *.o scopes2

run: 
	./scopes2.exe

.PHONY: all clean