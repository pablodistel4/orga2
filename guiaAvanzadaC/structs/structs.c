#include <stdio.h> 


typedef struct 
{
 char nombre[50];

 int vida; 

 double ataque;

 double defensa;
} monstruo_t;


void imprimirtodos(monstruo_t arreglo[], int size){

    monstruo_t m;
    for (int i=0; i<size;i++){
        m= arreglo[i];
        printf("monstruo %i:\nNombre= %s\nVida: %i\nAtaque: %f\nDefensa: %f\n----\n",
            i+1,m.nombre,m.vida,m.ataque,m.defensa);
    }

}

monstruo_t evolution(monstruo_t m){

    m.ataque= m.ataque+10;
    m.defensa= m.defensa+10;
    return m;
}

int main(){

    monstruo_t monstruos[]=
     {{"bigfoot",50,30.0,50.0},
    {"slenderman",30,60.0,20.0},{"lopez",40,40.0,40.0},
    {"comuzzi",10,20.0,70.0}};
    int size = (int) (sizeof(monstruos)/sizeof(monstruos[0]));

    imprimirtodos(monstruos,size);

    monstruos[0]= evolution(monstruos[0]);

    printf("evolucion\n");
    imprimirtodos(monstruos,size);

}