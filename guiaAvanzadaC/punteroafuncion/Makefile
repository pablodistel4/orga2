FLAGS = -Wall -Wextra -pedantic -g 
FILE = punteroafuncion

# Declaramos explícitamente el nombre con .exe para evitar conflictos en Windows
EXEC = $(FILE).exe

all: $(EXEC)

# La regla del ejecutable ahora usa $(EXEC)
$(EXEC): $(FILE).o
	gcc $(FLAGS) $(FILE).o -o $(EXEC)

# La regla del objeto queda igual
$(FILE).o: $(FILE).c
	gcc $(FLAGS) -c $(FILE).c -o $(FILE).o

# En el clean usamos -f para que no tire error si el archivo no existe, y borramos el $(EXEC)
clean:
	rm -f *.o $(EXEC)

# Hacemos que "run" dependa de "$(EXEC)" para que compile automáticamente antes de correr
run: $(EXEC)
	./$(EXEC)

debug: $(EXEC)
	gdb ./$(EXEC)

.PHONY: all clean run