#ifndef tipo_t.h

#define tipo_t.h

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum e_type {
TypeFAT32 = 0,
TypeEXT4 = 1,
TypeNTFS = 2
} type_t;


// 1. Definimos los tipos de datos
typedef uint32_t fat32_t;
typedef uint64_t ext4_t;
typedef int8_t   ntfs_t;

// 2. Declaramos las firmas de las funciones (¡Ojo, terminan en punto y coma!)
fat32_t* new_fat32(int a);
ext4_t*  new_ext4();
ntfs_t*  new_ntfs();

fat32_t* copy_fat32(fat32_t* file);
ext4_t*  copy_ext4(ext4_t* file);
ntfs_t*  copy_ntfs(ntfs_t* file);

void rm_fat32(fat32_t* file);
void rm_ext4(ext4_t* file);
void rm_ntfs(ntfs_t* file);

//definimos funciones para devolver los punteros a funciones 

typedef void* (*funcCopy_t)(void*);
typedef void (*funcRm_t)(void*);
funcCopy_t getCopyFunction(type_t t);
funcRm_t getRmFunction(type_t t);

#endif