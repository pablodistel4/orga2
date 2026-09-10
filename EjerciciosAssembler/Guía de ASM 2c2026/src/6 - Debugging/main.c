#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../test-utils.h"
#include "Debugging.h"

int main(int argc, char* argv[]) {
	
    item_t item1; 

    char* palabra= "pablo"; 

    uint32_t id= 2;
    uint32_t cant= 3;
    ejercicio2(&item1,id,cant,palabra); 

    printf("%d", sizeof(item1.nombre));
    printf("nombre=%s. \n id= %d \n cantidad = %d",item1.nombre,item1.id,item1.cantidad);

    return 0;
    

}