#include <stdio.h>
#include <stdlib.h>
#include <time.h>  //usamos el tiempo para variar la semilla 
void tirardado(int arreglo[]){
   
    int x= rand() %6;
    arreglo[x]= arreglo[x]+1;
}


int main (){
    srand(time(NULL));

    int dado[6]= {0};
    long contador = 60000000;

    while (contador!=0)
    {
        tirardado(dado);
        contador--;
    }
    for (int i=0;i<6;i++){
        printf("%i=%i\n",i+1,dado[i]);
    }
    return 0;
}