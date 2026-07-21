#include <stdio.h>

void print_int(int x) {
    printf("%d\n", x);
}

void pretty_print_int(int x) {
    printf("Entero[%lu bits]: %d\n", sizeof(x)*8, x);
}

int main() {
    void (*print)(int) = print_int; //puntero a la funcion print_int 
    print(42); // () desreferencia el puntero a funcion
    print = pretty_print_int; // ahora el puntero apunta a la funcion de pretty_print_int
    print(3);
}