FLAGS = -Wall -Wextra -pedantic -g -fsanitize=address
FILE = linkedList
FILE2 = tipo_t
# Creamos una variable explícita para el ejecutable de Windows
EXEC = $(FILE).exe

all: $(EXEC)

# Ahora make sabe que tiene que buscar exactamente "linkedList.exe"
$(EXEC): $(FILE).o $(FILE2).o 
	gcc $(FLAGS) $(FILE).o $(FILE2).o -o $(EXEC)

$(FILE).o: $(FILE).c
	gcc $(FLAGS) -c $(FILE).c -o $(FILE).o

$(FILE2).o: $(FILE2).c
	gcc $(FLAGS) -c $(FILE2).c -o $(FILE2).o

clean:
	rm -f *.o $(EXEC)

# Hacemos que "run" dependa de "$(EXEC)". 
# Así, si hacés "make run", compila todo primero si hace falta.
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run