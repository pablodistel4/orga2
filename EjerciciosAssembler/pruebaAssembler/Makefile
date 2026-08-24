# =========================================================
# MAKEFILE GENÉRICO PARA C Y ASSEMBLER (Entorno Windows/GCC)
# =========================================================

# 1. Nombre de tu programa final
EXEC = programa.exe

# 2. Herramientas a utilizar
CC = gcc
ASM = nasm

# 3. Banderas de Compilación (Flags)
# -Wall -Wextra -pedantic : Prende todas las alarmas de advertencia de C.
# -g                      : Guarda el mapa de memoria para usar GDB.
# -O0                     : Apaga las optimizaciones (vital para que el debugger no salte líneas).
CFLAGS = -Wall -Wextra -pedantic -g -O0

# Banderas de Assembler
# OJO: -f win64 es para tu Windows actual (MSYS2). 
# Cuando subas el TP al servidor de la facultad (Linux), cambialo por: -f elf64
ASMFLAGS = -f win64

# 4. Detección automática de archivos
# Busca todos los .c y .asm en la carpeta actual
C_SRCS = $(wildcard *.c)
ASM_SRCS = $(wildcard *.asm)

# Convierte los nombres de .c y .asm a .o para generar los objetos
C_OBJS = $(C_SRCS:.c=.o)
ASM_OBJS = $(ASM_SRCS:.asm=.o)
OBJS = $(C_OBJS) $(ASM_OBJS)

# =========================================================
# REGLAS
# =========================================================

# Regla por defecto: compila todo
all: $(EXEC)

# Paso Final: Enlazar (linkear) todos los .o para armar el .exe
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Paso Intermedio C: Cómo transformar un .c en un .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Paso Intermedio ASM: Cómo transformar un .asm en un .o
%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

# Regla para limpiar la carpeta de archivos compilados
clean:
	rm -f *.o $(EXEC)

# Regla rápida para compilar y ejecutar de un solo golpe
run: all
	./$(EXEC)

# Evita conflictos si tenés un archivo que se llame "clean" o "run"
.PHONY: all clean run