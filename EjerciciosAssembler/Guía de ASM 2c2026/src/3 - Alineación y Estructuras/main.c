#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "Estructuras.h"

int main() {
	
	packed_nodo_t lista1; 

	lista1.next= NULL;
	lista1.categoria=2; 
	lista1.longitud= 3;
	lista1.arreglo=NULL;
	packed_nodo_t lista2; 

	lista2.next= &lista1;
	lista2.categoria=2; 
	lista2.longitud= 3;
	lista2.arreglo=NULL;

	packed_lista_t lista_en; 
	lista_en.head=&lista2;
	
	uint32_t res=cantidad_total_de_elementos_packed(&lista_en);
	printf("len: %d \n", res);
	return 0;
}
