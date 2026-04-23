#include <stdio.h>

int main() {
    int i = 10;
    while(i--){
        printf("i = %d\n",i); // imprime el 0 cuando el ciclo para por i==1. por eso lo imprime.
    }


    for(int j=10;j>=0;j--){

        printf("j = %i \n",j);
    }
}