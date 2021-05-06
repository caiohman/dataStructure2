#include "indice.h"


void insert_array(INDEX **index, int space_alloc, int *nUSP, int *file_pos){
  if(!space_alloc){ //if it is empty
    index[space_alloc]->key = *nUSP;
    index[space_alloc]->file_position = *file_pos;
    return;
  }

  if(index[space_alloc - 1]->key < *nUSP ){  //the last one
    index[space_alloc]->key = *nUSP;
    index[space_alloc]->file_position = *file_pos;
    return;
  }


  //binary search
  return;
}
