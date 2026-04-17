#include <stdio.h>


void rotararreglo(int arreglo[], int len) {

    int primerelem = arreglo[0];
    
    printf("tamanio: %i",len);
    for(int i=1;i<len;i++){

        arreglo[i-1]=arreglo[i];
    }
    arreglo[len-1]=primerelem;
}

int main() {

    int arr[] = {1,2,3,4};
    int len=(int) (sizeof(arr)/sizeof(arr[0]));
    for (int j=0;j<len;j++){
        printf("%i: %i \n",j,arr[j]);
    }

    rotararreglo(arr,len);
    printf("---\n");
    for (int j=0;j<len;j++){
        printf("%i: %i\n",j,arr[j]);
    }

}


