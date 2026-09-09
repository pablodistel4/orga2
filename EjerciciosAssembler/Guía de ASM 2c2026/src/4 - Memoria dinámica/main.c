#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "Memoria.h"

int main() {
	
	int32_t res= strCmp("perro","gato");
	
	char palabra[]= "hola";
	char* res2= strClone(palabra);
	printf("palabra= %s \n",res2 );
	//int32_t res1= strLen(palabra); 
	//printf("tamanio= %d \n",res1 );

	free(res2);
	return 0;
}
