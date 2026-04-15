FLAGS = -Wall -Wextra -pedantic

all: factorial

factorial: factorial.o
	gcc $(FLAGS) factorial.o -o factorial

factorial.o: factorial.c
	gcc $(FLAGS) -c factorial.c -o factorial.o

clean:
	rm *.o factorial

run: 
	./factorial.exe

.PHONY: all clean