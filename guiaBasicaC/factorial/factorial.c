#include <stdio.h> 


int factorial(int n){

    if (n==0){
        return 1;
    }
    return n* factorial(n-1);
}


int main() {

    int p = 5; 

    printf("el factorial de %i es : %i \n",p,factorial(p));
    return 0;
}