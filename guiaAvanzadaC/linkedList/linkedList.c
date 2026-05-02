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

void* get(list_t* lista, int i){

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

