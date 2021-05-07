#ifndef INDICE_H_
#define INDICE_H_

typedef struct index{
  int key;
  int file_position;
}INDEX;

/*@Description:*/
/*@Param:*/
/*@Return:*/
int insert_array(INDEX **, int , int *, int *);

/*@Description:*/
/*@Param:*/
/*@Return:*/
int binary_search(int key, INDEX **index, int end, int start);

/*@Description:*/
/*@Param:*/
/*@Return:*/
void _delete_reg(int key, INDEX **index, int *size);
#endif
