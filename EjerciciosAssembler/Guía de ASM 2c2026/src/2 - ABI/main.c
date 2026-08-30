#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "../test-utils.h"
#include "ABI.h"

int main() {
	/* Acá pueden realizar sus propias pruebas */
	assert(alternate_sum_4_using_c(8, 2, 5, 1) == 10);

	assert(alternate_sum_4_using_c_alternative(8, 2, 5, 1) == 10);
	assert(alternate_sum_8(1,1,1,1,1,1,1,1)==0);
	float f= 4.0; 
	uint32_t pdest;
	product_2_f(&pdest,4,f);
	uint32_t res= 16;
	assert(pdest==res);
	
	printf("Ta todo bien");
	return 0;
}
