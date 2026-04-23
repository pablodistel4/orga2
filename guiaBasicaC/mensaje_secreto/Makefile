FLAGS = -Wall -Wextra -pedantic

all: mensaje_secreto

mensaje_secreto: mensaje_secreto.o
	gcc $(FLAGS) mensaje_secreto.o -o mensaje_secreto

mensaje_secreto.o: mensaje_secreto.c
	gcc $(FLAGS) -c mensaje_secreto.c -o mensaje_secreto.o

clean:
	rm *.o mensaje_secreto

run: 
	./mensaje_secreto.exe

.PHONY: all clean