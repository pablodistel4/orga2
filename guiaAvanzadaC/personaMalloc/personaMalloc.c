#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[20];
    int edad; 
} persona_t;

persona_t* crearPersona(char nombre[], int edad){



    persona_t* persona= malloc(sizeof(persona_t));
    if (persona==NULL){
        return NULL;
    }

    persona->edad=edad;
    strcpy(persona->nombre,nombre);
    return persona;
}   

//Definir una funcion eliminarPersona que reciba un puntero a una estructura persona t
//y libere la memoria reservada para la estructura.
void eliminarPersona(persona_t* p){

    free(p);
}
int main(){

    persona_t* pablito= crearPersona("Pablo",21);

    free(pablito);
}

