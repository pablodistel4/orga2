#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "tipo_t.h"



fat32_t* new_fat32(int a){
  fat32_t* p = malloc(sizeof(fat32_t));
  if (p==NULL){
    return NULL; 
  }
  *p=a; 
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

funcCopy_t getCopyFunction(type_t t) {
    switch (t) {
        case TypeFAT32: return (funcCopy_t) copy_fat32; break;
        case TypeEXT4: return (funcCopy_t) copy_ext4; break;
        case TypeNTFS: return (funcCopy_t) copy_ntfs; break;
        default: return NULL; break;
    }
}

funcRm_t getRmFunction(type_t t) {
    switch (t) {
        case TypeFAT32: return (funcRm_t) rm_fat32; break;
        case TypeEXT4: return (funcRm_t) rm_ext4; break;
        case TypeNTFS: return (funcRm_t) rm_ntfs; break;
        default: return NULL; break;
    }
}