#include <stdio.h>
#include <stdint.h>


int main (){   

    int32_t a = 0xFF; 

    int32_t masc1 = 0xE0;
    int32_t masc2 = 0x07;
    //hago las mascaras
    int32_t amasc1= a & masc1;
    int32_t amasc2= a & masc2;
    //shifteo una de as mascaras para compararlas 
    amasc1=  masc1 >> 5;

    printf("los primeros tres bits son iguales a los ultimos tres bits?: %i", amasc1== amasc2);
    return 0;
}