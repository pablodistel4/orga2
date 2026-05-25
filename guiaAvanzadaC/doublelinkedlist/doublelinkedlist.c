/*ejercicio 16: Extender la clase lista enlazada para que sea doblemente enlazada. Esto significa que cada
nodo tendrá un puntero al nodo anterior y al siguiente. Esto permitirá recorrer la lista
en ambas direcciones. Para esto, se debe agregar una función para agregar un nodo al
final de la lista. Mantener un puntero last en la lista que apunte al último nodo. Esto
permitir agregar nodos al final de la lista de manera eficiente.*/


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
    struct node* prev;
} node_t;

typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
    node_t* last;
} list_t;

list_t* crearlista(type_t tipo){

    list_t* lista = malloc(sizeof(list_t));

    lista->type= tipo; 
    lista->size=0;
    lista->first= NULL;
    lista->last=NULL;
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
        if (lista->size==0){
            lista->first=nuevonodo;
            lista->last=nuevonodo;
            nuevonodo->next=NULL;
            nuevonodo->prev=NULL;
        }
        else{
            lista->first->prev=nuevonodo;
            nuevonodo->next=lista->first;
            nuevonodo->prev=NULL;
            lista->first=nuevonodo;
            
        }
        lista->size++;
    }
}


void agregaratras(list_t* lista, void* data){
    node_t* nuevonodo = malloc(sizeof(node_t));
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
        if (lista->size==0){
            lista->first=nuevonodo;
            lista->last=nuevonodo;
            nuevonodo->next=NULL;
            nuevonodo->prev=NULL;
        }
        else{
            lista->last->next=nuevonodo;
            nuevonodo->prev=lista->last;
            nuevonodo->next=NULL;
            lista->last=nuevonodo;
        }
        lista->size++;
    }
}

void* getlist(list_t* lista, int i){
    if (lista->size==0 || i<0 || i>= lista->size){
        return NULL;
    }
    if (i<lista->size/2){
        int contador= 0; 
        node_t* actual= lista->first;
        while (contador<i)
        {
            actual= actual->next;
            contador++;
        }
        return actual->data; 
    }else{
        int contador= lista->size-1; 
        node_t* actual= lista->last;
        while (contador>i)
        {
            actual= actual->prev;
            contador--;
        }
        return actual->data;
    }
    
}

void* eliminar(list_t* lista, int i){
    if (lista->size==0 || i<0 || i>=lista->size){
        return NULL;
    }
    
    node_t* eliminado;
    if (lista->size==1){
        eliminado= lista->first;
        lista->first=NULL;
        lista->last=NULL;
    }
    else if (i==0){
        eliminado= lista->first;

        lista->first=lista->first->next;
        lista->first->prev=NULL;
    }
    else if (i== lista->size-1){
        eliminado = lista->last;

        lista->last= lista->last->prev;
        lista->last->next= NULL;
    }
    else{
        node_t* anterior= NULL;
        node_t* actual= lista->first;
        for(int j=0;j<i;j++){
            anterior= actual;
            actual= actual->next;
        }
        eliminado= actual;
        node_t* sig= actual->next; 
        anterior->next= sig; 
        sig->prev= anterior;
    }
    void* data = eliminado->data;
    free(eliminado); 
    lista->size--;
    return data;
  
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
    if (lista->size>1){
        //primero me aseguro que x es menor que y 
        if (x>y){
            int temp= y;
            y=x;
            x=temp;
        }
        //busco x
        node_t* anteriorX= NULL;
        node_t* actualX= lista->first;
        for(int i=0;i<x;i++){
                anteriorX= actualX;
                actualX= actualX->next;
        }
        //busco y
        node_t* anteriorY= anteriorX;
        node_t* actualY= actualX;
        for(int j=x;j<y;j++){
            anteriorY= actualY;
            actualY= actualY->next;
        }
        node_t* sigY= actualY->next; 

        int dif= y-x; 
        if (dif==1){
             
            actualX->next= sigY; 
            actualX->prev=actualY; 
            actualY->prev=anteriorX;
            actualY->next=actualX;
            if (anteriorX!=NULL){
                anteriorX->next= actualY; 
            }
            if (sigY!=NULL){
                sigY->prev=actualX;
            }
        }else{  
                node_t* sigX= actualX->next;
                
                actualY->next=sigX;
                actualY->prev= anteriorX;
                actualX->next=sigY;
                actualX->prev=anteriorY;
                if (anteriorX!=NULL){
                    anteriorX->next=actualY;
                }
                
                if (sigY!=NULL){
                    sigY->prev=actualX;
                }
                sigX->prev= actualY; 
                anteriorY->next=actualX;
                
        }
        if (x==0){
            lista->first=actualY;
        }
        if (y==lista->size-1){
            lista->last= actualX;
        }

    }
}