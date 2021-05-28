#include "indice.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*********************************************************************************************************/
/* AUXILIAR FUNCTIONS */

BOOL _page_full(PAGE *page){
  assert(page);
  if( page->key_num >= MAXKEYS) return true;
  return false;
}

int binary_search(long key, INDEX *index, int end, int start){
  if(end >= start){
    int middle = start + (end - start)/2;
    if(index[middle].key == key)return middle;
    if(index[middle].key > key)return binary_search(key, index, middle - 1, start);
    if(index[middle].key < key)return binary_search(key, index, end, middle + 1);
  }
  return -1;
}

/**********************************************************************************************/

PAGE *_create(){
  PAGE *page = (PAGE *)calloc(1, sizeof(PAGE));
  assert(page);
  page->is_leaf = true;
  return page;
}

int _insert_b_tree(PAGE *page, int *nUSP , long *file_pos){
  assert(page);

  if(!page->key_num){ // first
    page->index[0].key = *nUSP;
    page->index[0].file_position = *file_pos;
    page->key_num++;
    return 0;
  }

  if(binary_search(*nUSP, page->index, page->key_num - 1, 0) != -1){ //already exist
    printf("%s\n", "O Registro ja existe!");
    return 1; //error
  }

  if(_page_full(page) != true){
    //binary search
  }


  return 1;
}

int _search(PAGE *page){
  
  if(page == NULL) return 1; //error
  return 0; //success
}

void _delete_b_tree(PAGE *page){
  free(page);
}
