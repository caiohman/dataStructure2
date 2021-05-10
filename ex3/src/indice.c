#include "indice.h"
#include <stdio.h>
#include <stdlib.h>

int binary_search(int key, INDEX **index, int end, int start){
  if(end >= start){
    int middle = start + (end - start)/2;
    if(index[middle]->key == key)return middle;
    if(index[middle]->key > key)return binary_search(key, index, middle - 1, start);
    if(index[middle]->key < key)return binary_search(key, index, end, middle + 1);
  }
  return -1;
}

int insert_array(INDEX **index, int space_alloc, int *nUSP, int *file_pos){
  if(!space_alloc){ //if it is empty
    index[space_alloc]->key = *nUSP;
    index[space_alloc]->file_position = *file_pos;
    return 0;
  }

  if(index[space_alloc - 1]->key < *nUSP ){  //the last one
    index[space_alloc]->key = *nUSP;
    index[space_alloc]->file_position = *file_pos;
    return 0; //success
  }

  if(binary_search(*nUSP, index, space_alloc -1, 0) != -1){ //already exist
    printf("%s\n", "O Registro ja existe!");
    return 1; //error
  }

  int x = space_alloc; //search
  while(index[x - 1]->key > *nUSP){
    index[x]->key = index[x - 1]->key; //move right
    index[x]->file_position = index[x - 1]->file_position;
    x--;
  }
  if(index[x - 1]->key < *nUSP && index[x]->key > *nUSP){
    index[x]->key = *nUSP;
    index[x]->file_position = *file_pos;
    return 0; //success
  }
  return 1; //error
}

void _delete_reg(int key, INDEX **index, int *size){
 int pos = binary_search(key, index, *size, 0);

 if(pos == -1){ //not found
   return;
 }

 if(index[pos]->key == index[(*size) -1]->key){ //delete last pos
   index[pos]->key = -1;
   index[pos]->file_position = -1;
   free(index[pos]);
   (*size)--;
   return;
 }

 int i = pos;
 for(; i < ((*size) -1); i++){ //delete middle or beginning
   index[i]->key = index[i + 1]->key;
   index[i]->file_position = index[i + 1]->file_position;
 }
 index[i]->key = -1;
 index[i]->file_position = -1;
 (*size)--;
 return;
}
