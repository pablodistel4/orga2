FLAGS = -Wall -Wextra -pedantic

all: structs

structs: structs.o
	gcc $(FLAGS) structs.o -o structs

structs.o: structs.c
	gcc $(FLAGS) -c structs.c -o structs.o

clean:
	rm *.o structs

run: 
	./structs.exe

.PHONY: all clean