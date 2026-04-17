FLAGS = -Wall -Wextra -pedantic

all: scopes

scopes: scopes.o
	gcc $(FLAGS) scopes.o -o scopes

scopes.o: scopes.c
	gcc $(FLAGS) -c scopes.c -o scopes.o

clean:
	rm *.o scopes

run: 
	./scopes.exe

.PHONY: all clean