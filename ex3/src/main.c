#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "indice.h"


int main(int argc, char const *argv[]) {
  char op[6];
  INDEX **index_arr = (INDEX **)calloc(200 , sizeof(INDEX *)); //index array
  int count = 0;

  do{
    scanf("%s ", op);
    if(!strcmp(op, "insert")){
      index_arr[count] = (INDEX *)realloc(index_arr[count], sizeof(INDEX));
      if(!_read_line_send_binary(index_arr, count)){
        count++;
        //index_arr = (INDEX **)realloc(index_arr, sizeof(INDEX *)); //alloc to another
      }
    }
    if(!strcmp(op, "search")){
      int key;
      scanf("%d", &key);
      (count) ? _search_binary(key, index_arr, count) : printf("%s\n", "Registro nao encontrado!"); //search if there is register
    };
    if(!strcmp(op, "delete")){
      int key;
      scanf("%d", &key);
      if(count) _delete_reg(key, index_arr, &count);
    }
  }while(strcmp(op, "exit"));

  for(int i = 0; i < count; i++){
    free(index_arr[i]);
  }
  free(index_arr);

  return 0;
}
