#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "tipo_t.h"

typedef enum e_type {
TypeFAT32 = 0,
TypeEXT4 = 1,
TypeNTFS = 2
} type_t;

typedef struct node {
    void* data;
    struct node* next;
} node_t;

typedef struct list {
type_t type;
uint8_t size;
node_t* first;
} list_t;

list_t* crearlista(type_t tipo){

    list_t* lista = malloc(sizeof(list_t));

    lista->type= tipo; 
    lista->size=0;
    lista->first= NULL;
    return lista;
}

void agregaradelante(list_t* lista, void* data){
    node_t* nuevonodo= malloc(sizeof(node_t));

    if (nuevonodo!=NULL){
        switch(lista->type){
            case TypeFAT32:
                nuevonodo->data= (void*) copy_fat32(data);
                break; 
            case TypeEXT4:
                nuevonodo->data= (void*) copy_ext4(data); 
                break;
            case TypeNTFS:
                nuevonodo->data= (void*) copy_ntfs(data);
                break; 
        }
        nuevonodo->next= lista->first;
        lista->first=nuevonodo;
        lista->size++;
    }
}

void* getlist(list_t* lista, int i){

    node_t* actual= lista->first;

    int contador= i; 

    while (contador>0)
    {
        actual= actual->next;
        contador--;
    }
    return actual->data; 
    
}

void* eliminar(list_t* lista, int i){
    void* eliminado;
    if (lista->size==0){
        return NULL;
    }
    else if (lista->size==1){
        eliminado = lista->first->data;
        free(lista->first);
        lista->first=NULL;  
        lista->size--; 
        return eliminado;
    }
    else{
        if (i==0){
            node_t* primero= lista->first;
            node_t* segundo = primero->next;
            void* dataprimero= primero->data; 
            free(primero);
            lista->first= segundo; 
            lista->size--;
            return dataprimero;
        }
        else{
            node_t* anterior = lista->first;
            node_t* actual= lista->first->next; 
            int contador= i-1; 
            while (contador>0)
            {
                actual=actual->next; 
                anterior= anterior->next;

            }
            eliminado=actual->data; 
            anterior->next= actual->next;
            free(actual);
            lista->size--;
            return eliminado;
        }
    }
}

void eliminarlista(list_t* lista){



    while (lista->first!=NULL)
    {
        void* elem= eliminar(lista,0);
        switch(lista->type){
            case TypeFAT32:
                rm_fat32(elem);
                break; 
            case TypeEXT4:
                rm_ext4(elem); 
                break;
            case TypeNTFS:
                rm_ntfs(elem);
                break; 
        }
    }
    free(lista);
    
}

/* Agregar una funcion a la lista que permita intercambiar el orden de dos nodos. Para esto,
se debe tener en cuenta que la lista puede estar vacia o tener un solo nodo. En caso de
que la lista tenga un solo nodo o este vacia, no se debe hacer nada.*/

void intercambiar(list_t* lista, int x, int y){
    // se asume que los indices x e y estan el el rango por precondicion

    if (lista->size>1){ //si el tamanio de la lista es 1 o 0 no hace nada.

        //creo punteros a los datos
        void* elemx= getlist(lista,x);
        void* elemy= getlist(lista,y);

        //busco a cada uno y le cambio la data
        node_t* actual= lista->first; //creo nodo para iterar

        for(int i=0;i<lista->size;i++){
            if (i==x){               
                actual->data=elemy;
            }
            if (i==y){
                actual->data=elemx;
            }
            if (i>x && i>y){
                break;  //para no iterar de mas, si el indice ya supero ambos 
            }
            actual= actual->next;
        }
    }
}


void intercambiarNodos(list_t* lista, int x, int y){
    //se asume que los datos de entrada son validos por precondicion.
    if (lista->size>1){ //si el tamanio de la lista es 1 o 0 no hace nada.
        //ajusto los indices para que x siempre sea el chico
        if (x>y){
            int temp = x; 
            x=y;
            y=temp;
        }
        //Primero encuentro x e y 

        node_t* punteroX= lista->first;
        node_t* anteriorX= NULL;
        for (int i=0;i<x;i++){
            anteriorX= punteroX;
            punteroX=punteroX->next;
        }
        node_t* sigX= punteroX->next;

        node_t* punteroY= lista->first;
        node_t* anteriorY= NULL;
        for (int i=0;i<y;i++){
            anteriorY=punteroY;
            punteroY=punteroY->next;
        }
        node_t* sigY=punteroY->next;

        int diferencia= y-x;

        if (diferencia==1){// si ambos nodos estan pegados (SE PUEDE OPTIMIZAR PARA SACAR ESTA PARTE)
            if (x==0){ //x es el primero e y es el segundo

                node_t* tercero= punteroY->next; 
                lista->first=punteroY; 
                punteroY->next= punteroX; 
                punteroX->next=tercero;
            }

            else{  
                    anteriorX->next=punteroY;
                    punteroY->next=punteroX;
                    punteroX->next=sigY; 
                      
            }
            
        } 
        else if (x==0){ // si x es el primero..
            
            //pongo x en y
            anteriorY->next=punteroX; 
            punteroX->next=sigY;

            //pongo y al principio
            lista->first=punteroY; 
            punteroY->next= sigX;
        }
        else{ // si ninguno de los dos el primero, entonces tenemos que buscar el anterior de ambos y hacer ambos cambios

            //hago los cambios
            anteriorX->next=punteroY; 
            punteroY->next= sigX; 
            
            anteriorY->next= punteroX; 
            punteroX->next= sigY;

        }

    }
}

void invertirlista(list_t* lista){

//pendiente

}
int main(){

    fat32_t* item1 = new_fat32(1);
    fat32_t* item2 = new_fat32(2);
    fat32_t* item3 = new_fat32(3);
    fat32_t* item4 = new_fat32(4);
    list_t* lista= crearlista(TypeFAT32);
    agregaradelante(lista,item4);
    agregaradelante(lista,item3);
    agregaradelante(lista,item2);
    agregaradelante(lista,item1);
    node_t* actual= lista->first; 

    printf("[");
    for(int i=0; i<lista->size;i++){
        
        printf("%u,",*(uint32_t*) actual->data);
        actual=actual->next;
    }
    printf("]\n");

    intercambiarNodos(lista,1,2);
    printf("cambio nodos 1 y 2\n");

    node_t* actual2= lista->first; 

    printf("[");
    for(int i=0; i<lista->size;i++){

         printf("%u,",*(uint32_t*) actual2->data);
        actual2=actual2->next;
    }
    printf("]\n");

    invertirlista(lista);

    node_t* actual3= lista->first; 

    printf("invierto la lista: \n");
    printf("[");
    for(int i=0; i<lista->size;i++){

         printf("%u,",*(uint32_t*) actual3->data);
        actual3=actual3->next;
    }
    printf("]\n");
    eliminarlista(lista);
    rm_fat32(item1);
    rm_fat32(item2);
    rm_fat32(item3);
    rm_fat32(item4);

}


