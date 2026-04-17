#include <stdio.h>


int main() {

    int misnumeros[]= {1,2,3};

    /*en c no existe el misnumeros.length .Para saber el tamanio, 
    conseguimos el tamanio total de arreglo 
    (que es literalmente la suma del tamanio de todos sus elementos), 
    y la dividimos por el tamanio de un elemento del arreglo.*/

    size_t length_arreglo= sizeof(misnumeros)/ sizeof(misnumeros[0]); //size_t es tipo recomendable para hablar de tamanios en bytes
    int tamanioentero= (int) length_arreglo;

    printf("arreglo: {1,2,3} \n tamanio del arreglo: %zu \n tamanio de un solo elemento: %zu \n cantidad de elementos del arreglo: %i ", sizeof(misnumeros),sizeof(misnumeros[0]),tamanioentero) ;
    return 0;
}