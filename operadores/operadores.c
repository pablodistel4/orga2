#include <stdio.h> 

int main() {

    int a = 5;  
    int b = 3; 
    int c = 2;
    int d = 1;
    int e=1; 
    printf( "a = 5 \n b = 3 \n c = 2 \n d = 1 \n");
    printf("a + b * c / d = %i \n", a + b * c / d); 
    printf("a mod b = %i \n", a % b); 
    printf("a == b = %i \n", a == b); 
    printf("a != b = %i \n", a != b); 
    printf("a == b = %i \n", a == b); 
    printf( "(binario AND bit a bit) a & b = %x \n", a & b); 
    printf( "(binario OR bit a bit) a | b = %x \n", a | b); 
    printf( "(binario NOT bit a bit) ~a = %x \n", ~a); 
    printf( "(binario shift izq) a<<1 = %x \n", a<<1); 
    printf("se usa principalmente para multiplicar rapidamente a por 2 \n" );
    printf( "(binario shift der) a>>1 = %x \n", a>>1); 
    printf("se usa principalmente para dividir rapidamente a por 2 \n" );
    printf("a && b = %i \n", a && b);
    printf("a || b = %i \n", a || b);


    printf("tengo e=1 \n si hago e++ devuelve %i, imprime 1 pues primero devuelve y despues incrementa \n",e++);
		
		printf (" si hago ++e devuelve %i pues primero incrementa y despues devuelve.\n", ++e);
    
    return 0;
}