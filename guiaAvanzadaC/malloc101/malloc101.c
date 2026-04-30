#include <stdio.h>
#include <stdlib.h>


int *secuencia(int n){
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
    // Manejar el error de asignaci´on de memoria
        return NULL;
    }
    for(int i = 0; i < n; i++)
        arr[i] = i;
    return arr;
}


int main(){
    int *arr = secuencia(10);
    if (arr == NULL) {
    // Manejar el error de asignaci´on de memoria
        return 1;
    }
    for(int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);
    free(arr); // Liberar la memoria reservada
    return 0;
}