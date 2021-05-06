#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "indice.h"


int main(int argc, char const *argv[]) {
  char op[6];
  INDEX **index_arr = (INDEX **)calloc(1, sizeof(INDEX*)); //index array
  int count = 0;

  do{
    scanf("%s ", op);
    if(!strcmp(op, "insert")){
      index_arr[count] = (INDEX *)realloc(index_arr[count], sizeof(INDEX));
      _read_line_send_binary(index_arr, count);
      index_arr = (INDEX **)realloc(index_arr, sizeof(INDEX *)); //alloc to another
      count++;
    }
    if(!strcmp(op, "search"));
    if(!strcmp(op, "delete"));
  }while(strcmp(op, "exit"));

  _read_binary();

  printf("%d\n", index_arr[1]->key);
  printf("%d\n", index_arr[1]->file_position);

  for(int i = 0; i < count; i++){
    free(index_arr[i]);
  }
  free(index_arr);


  return 0;
}
