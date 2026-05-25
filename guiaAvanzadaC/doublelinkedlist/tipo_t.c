#include <stdio.h>
#include <stdint.h>
#include "tipo_t.h"




fat32_t* new_fat32(){
  fat32_t* p = malloc(sizeof(fat32_t));
  if (p==NULL){
    return NULL; 
  }
  *p=32; 
  return p;
}
ext4_t* new_ext4(){
    ext4_t* p = malloc(sizeof(ext4_t));
    if (p==NULL){
       return NULL; 
     }
    *p=64; 
    return p;
}
ntfs_t* new_ntfs(){
    ntfs_t* p = malloc(sizeof(ntfs_t));
    if (p==NULL){
        return NULL; 
  }
    *p=8; 
    return p;
}
fat32_t* copy_fat32(fat32_t* file){
    fat32_t* nuevo = malloc(sizeof(fat32_t));
    if (nuevo==NULL){
        return NULL; 
    }
    *nuevo=*file; 
    return nuevo; 

}
ext4_t* copy_ext4(ext4_t* file){
    ext4_t* nuevo = malloc(sizeof(ext4_t));
    if (nuevo==NULL){
        return NULL; 
    }
    *nuevo=*file; 
    return nuevo; 

}
ntfs_t* copy_ntfs(ntfs_t* file){
    ntfs_t* nuevo = malloc(sizeof(ntfs_t));
    if (nuevo==NULL){
        return NULL; 
    }
    *nuevo=*file; 
    return nuevo; 

}
void rm_fat32(fat32_t* file){
    free(file);
}
void rm_ext4(ext4_t* file){
    free(file);
}
void rm_ntfs(ntfs_t* file){
    free(file);
}