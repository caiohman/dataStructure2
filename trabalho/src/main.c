#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"
#include "indice.h"


int main(int argc, char const *argv[]) {
  char op[6];
  int count = 0;

  PAGE *b_tree = _create();

   do{
    scanf("%s ", op);
    if(!strcmp(op, "insert")){
        if(!_read_line_send_binary(b_tree)) count++;
    }
    if(!strcmp(op, "search")){
      int key;
      scanf("%d", &key);
      (count) ? _search_binary(key, b_tree) : printf("%s\n", "Registro nao encontrado!"); //search if there is register
    };
    if(!strcmp(op, "delete")){
      int key;
      scanf("%d", &key);
    }
  }while(strcmp(op, "exit"));

  _delete_b_tree(b_tree);

  return 0;
}
