# Nombre de tu programa final
EXEC = programa

# Herramientas
CC = gcc
ASM = nasm

# Banderas de compilación
# -g: Habilita los símbolos para usar GDB o Valgrind
# -O0: Apaga optimizaciones para que el código se ejecute tal cual lo escribiste
# -no-pie: Evita errores de linkeo comunes al mezclar C y Assembler en Linux
CFLAGS = -Wall -Wextra -pedantic -g -O0 -no-pie

# Bandera vital de Assembler para Linux 64 bits
ASMFLAGS = -f elf64 -g

# Archivos objeto requeridos (asumiendo que tenés main.c y suma.asm)
OBJS = main.o suma.o

# =========================================================
# REGLAS
# =========================================================

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -f *.o $(EXEC)

.PHONY: all clean