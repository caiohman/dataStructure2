#ifndef INDICE_H_
#define INDICE_H_

typedef struct index{
  int key;
  int file_position;
}INDEX;

/*@Description:*/
/*@Param:*/
/*@Return:*/
void insert_array(INDEX **, int , int *, int *);
#endif
