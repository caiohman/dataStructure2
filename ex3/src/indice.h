#ifndef INDICE_H_
#define INDICE_H_

typedef struct index{
  int key;
  int file_position;
}INDEX;

/*@Description: insert values to index                                        */
/*@Param: pointer to array, array size, key and binary file position          */
/*@Return: 0 for success or 1 for error                                       */
int insert_array(INDEX **, int , int *, int *);

/*@Description: search elements in array*/
/*@Param: key, pointer to array, end of array and beginning of array*/
/*@Return: array position*/
int binary_search(int , INDEX **, int , int );

/*@Description: delete array's elements                                       */
/*@Param: key, pointer to array and array size                                */
/*@Return: none                                                               */
void _delete_reg(int key, INDEX **index, int *size);
#endif
