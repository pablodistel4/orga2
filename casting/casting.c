#include <stdio.h>


int main() {

   float f = 0.1;
   double d = 0.1; 
   printf("tengo este float: %f y este double: %f \n --casteo--", f,d); 
   int f1 = (int) f;
   int d1 = (int) d;
   printf("tengo este float: %i y este double: %i", f1,d1); 

    return 0;
}