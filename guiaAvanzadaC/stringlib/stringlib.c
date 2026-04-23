#include <stdio.h>
#include <string.h> 



int main(){

    char str[]= "pablodistel"; 

    size_t len = strlen(str);
    char copia[len];
    strcpy(copia,str);
    char hola[30] = "hola "; 
    strcat(hola,str);
    int soniguales= strcmp(hola,str);

  
    
    printf("string: %s\n",str);
    printf("strlen-> tamanio: %zu \n",len);
    printf("strcopy-> copia: %s\n",copia);
    printf("strcat -> concatenar: %s\n",hola);
    printf("strcmp->equals para string: %i",soniguales);

}