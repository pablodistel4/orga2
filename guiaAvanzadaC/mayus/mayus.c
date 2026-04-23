#include <stdio.h> 

void todomayus(char str[]){

    
    for(int i=0;str[i] != '\0';i++){ // forma de recorrer un arreglo sin usar el tamanio, ademas una palabra de 5 elems pesa 6 bytes

        if (str[i]>='a' && str[i]<='z'){ //mejor forma de interpretar una minuscula
            str[i]= str[i] -32;  // 32 siempre es la difernecia entre una letra y su mayuscula

        }
    }

}

int main(){

    char palabra[] = "ayuda";

    printf("original: %s\n",palabra); 
    todomayus(palabra);
    printf("cambio: %s",palabra); 

}