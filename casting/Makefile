FLAGS = -Wall -Wextra -pedantic

all: casting

casting: casting.o
	gcc $(FLAGS) casting.o -o casting

casting.o: casting.c
	gcc $(FLAGS) -c casting.c -o casting.o

clean:
	rm *.o casting

run: 
	./casting.exe

.PHONY: all clean