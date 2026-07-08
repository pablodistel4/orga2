#include <stdio.h>
#include <stdlib.h>
/* el doble puntero es un puntero a un puntero.
La ventaja que tiene es que, como los parametros en C siempre los pasamos por copia,
no podemos modificar la direccion a la que punta un puntero pasado por parametro. 
Para solucionar esto, podemos pasar como parametro un puntero al puntero*/ 


// MAL 


void allocateArray(int *arr, int size, int value) {
    arr = (int*)malloc(size * sizeof(int));
    if(arr != NULL) {
        for(int i=0; i<size; i++) {
            arr[i] = value;
        }
    }
}
/* Esta funcion no va a crear y colocar el arreglo porque el puntero que se define es un puntero local,
no afecta al puntero global. Tira segementation error.  */

//BIEN 

void allocateArray2(int **arr, int size, int value) {
    *arr = (int*)malloc(size * sizeof(int));
    if(*arr != NULL) {
        for(int i=0; i<size; i++) {
            (*arr)[i] = value;
        }
    }
}

//aca pasamos  un puntero al puntero que queremos modificar, por lo que se produce el cambio que queremos.


int main(){
   int *vector = NULL;

    allocateArray2(&vector,5,45);
    for(int i = 0; i < 5; i++)
        printf("%d\n", vector[i]);
    free(vector); 
}
