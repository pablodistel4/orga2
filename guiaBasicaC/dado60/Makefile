FLAGS = -Wall -Wextra -pedantic

all: dado60

dado60: dado60.o
	gcc $(FLAGS) dado60.o -o dado60

dado60.o: dado60.c
	gcc $(FLAGS) -c dado60.c -o dado60.o

clean:
	rm *.o dado60

run: 
	./dado60.exe

.PHONY: all clean